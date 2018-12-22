from mamba import description, before, after, it
from expects import *
import os

import client.api
import client.models
from common import Config, Service
from common.matcher import be_valid_port, raise_api_exception


CONFIG = Config(os.path.join(os.path.dirname(__file__), os.environ.get('MAMBA_CONFIG', 'config.yaml')))


with description('Ports,') as self:
    with before.all:
        service = Service(CONFIG.service())
        self.process = service.start()
        self.api = client.api.PortsApi(service.client())

    with description('list,'):
        with description('unfiltered,'):
            with it('returns valid ports'):
                ports = self.api.list_ports()
                expect(ports).not_to(be_empty)
                for port in ports:
                    expect(port).to(be_valid_port)

        with description('filtered,'):
            with description('known existing kind,'):
                with it('returns valid ports of that kind'):
                    ports = self.api.list_ports(kind='dpdk')
                    expect(ports).not_to(be_empty)
                    for port in ports:
                        expect(port).to(be_valid_port)
                        expect(port.kind).to(equal('dpdk'))

            with description('known non-existent kind,'):
                with it('returns no ports'):
                    ports = self.api.list_ports(kind='host')
                    expect(ports).to(be_empty)

            with description('invalid kind,'):
                with it('returns no ports'):
                    ports = self.api.list_ports(kind='foo')
                    expect(ports).to(be_empty)

            with description('missing kind,'):
                with it('returns no ports'):
                    ports = self.api.list_ports(kind='')
                    expect(ports).to(be_empty)

    with description('get,'):
        with description('known existing port,'):
            with it('succeeds'):
                expect(self.api.get_port('0')).to(be_valid_port)

        with description('non-existent port,'):
            with it('returns 404'):
                expect(lambda: self.api.get_port('foo')).to(raise_api_exception(404))

    with description('create,'):
        with before.each:
            self.port = client.models.Port()

        with description('dpdk kind,'):
            with before.each:
                self.port.kind = 'dpdk'
                self.port.config = client.models.PortConfig(dpdk=client.models.PortConfigDpdk())

            with it('returns 400'):
                expect(lambda: self.api.delete_port('0')).to(raise_api_exception(400))

        with description('host kind,'):
            with before.each:
                self.port.kind ='host'

            with it('returns 400'):
                expect(lambda: self.api.delete_port('0')).to(raise_api_exception(400))

        with description('bond kind,'):
            with before.each:
                self.port.kind = 'bond'
                self.port.config = client.models.PortConfig(bond=client.models.PortConfigBond())

            with description('LAG 802.3AD mode,'):
                with before.each:
                    self.port.config.bond.mode = 'lag_802_3_ad'

                with description('valid port list,'):
                    with before.each:
                        ports = self.api.list_ports(kind='dpdk')
                        expect(ports).not_to(be_empty)
                        self.port.config.bond.ports = [ p.id for p in ports ]
                        expect(self.port.config.bond.ports).not_to(be_empty)

                    with it('succeeds'):
                        port = self.api.create_port(self.port)
                        expect(port).to(be_valid_port)
                        self.cleanup = port
                        # TODO: no bond type in back end, at present
                        #expect(port.kind).to(equal(self.port.kind))
                        #expect(port.config.bond.mode).to(equal(self.port.config.bond.mode))

                with description('invalid port list,'):
                    with before.each:
                        self.port.config.bond.ports = ['foo']

                    with it('returns 400'):
                        expect(lambda: self.api.create_port(self.port)).to(raise_api_exception(400))

                with description('empty port list,'):
                    with before.each:
                        self.port.config.bond.ports = []

                    with it('returns 400'):
                        expect(lambda: self.api.create_port(self.port)).to(raise_api_exception(400))

                with description('missing port list,'):
                    with it('returns 400'):
                        expect(lambda: self.api.create_port(self.port)).to(raise_api_exception(400))

            with description('invalid mode,'):
                with before.each:
                    self.port.config.bond.mode = 'foo'

                with it('returns 400'):
                    expect(lambda: self.api.create_port(self.port)).to(raise_api_exception(400))

            with description('missing mode,'):
                with it('returns 400'):
                    expect(lambda: self.api.create_port(self.port)).to(raise_api_exception(400))

        with description('invalid kind,'):
            with before.each:
                self.port.kind = 'foo'

            with it('returns 400'):
                expect(lambda: self.api.create_port(self.port)).to(raise_api_exception(400))

        with description('missing kind,'):
            with it('returns 400'):
                expect(lambda: self.api.create_port(self.port)).to(raise_api_exception(400))

    with description('delete,'):
        with description('valid port,'):
            with before.each:
                ports = self.api.list_ports(kind='dpdk')
                self.port = client.models.Port()
                self.port.kind = 'bond'
                self.port.config = client.models.PortConfig(bond=client.models.PortConfigBond())
                self.port.config.bond.mode = 'lag_802_3_ad'
                self.port.config.bond.ports = [ p.id for p in ports ]
                expect(self.port.config.bond.ports).not_to(be_empty)
                port = self.api.create_port(self.port)
                expect(port).to(be_valid_port)
                self.port, self.cleanup = port, port

            with it('succeeds'):
                self.api.delete_port(self.port.id)
                expect(lambda: self.api.get_port(self.port.id)).to(raise_api_exception(404))
                self.cleanup = None

        with description('protected port,'):
            with it('returns 400'):
                expect(lambda: self.api.delete_port('0')).to(raise_api_exception(400))

        with description('non-existent port,'):
            with it('succeeds'):
                self.api.delete_port('foo')

    with after.each:
        try:
            if self.cleanup is not None:
                try:
                    self.api.delete_port(self.cleanup.id)
                except:
                    pass
                self.cleanup = None
        except AttributeError:
            pass

    with after.all:
        try:
            self.process.kill()
            self.process.wait()
        except AttributeError:
            pass
