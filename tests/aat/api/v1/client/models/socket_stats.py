# coding: utf-8

"""
    OpenPerf API

    REST API interface for OpenPerf  # noqa: E501

    OpenAPI spec version: 1
    Contact: support@spirent.com
    Generated by: https://github.com/swagger-api/swagger-codegen.git
"""


import pprint
import re  # noqa: F401

import six


class SocketStats(object):
    """NOTE: This class is auto generated by the swagger code generator program.

    Do not edit the class manually.
    """

    """
    Attributes:
      swagger_types (dict): The key is attribute name
                            and the value is attribute type.
      attribute_map (dict): The key is attribute name
                            and the value is json key in definition.
    """
    swagger_types = {
        'pid': 'int',
        'sid': 'int',
        'protocol': 'str',
        'rxq_bytes': 'int',
        'txq_bytes': 'int',
        'local_ip_address': 'str',
        'remote_ip_address': 'str',
        'local_port': 'int',
        'remote_port': 'int',
        'state': 'str',
        'send_queue_length': 'int'
    }

    attribute_map = {
        'pid': 'pid',
        'sid': 'sid',
        'protocol': 'protocol',
        'rxq_bytes': 'rxq_bytes',
        'txq_bytes': 'txq_bytes',
        'local_ip_address': 'local_ip_address',
        'remote_ip_address': 'remote_ip_address',
        'local_port': 'local_port',
        'remote_port': 'remote_port',
        'state': 'state',
        'send_queue_length': 'send_queue_length'
    }

    def __init__(self, pid=None, sid=None, protocol=None, rxq_bytes=None, txq_bytes=None, local_ip_address=None, remote_ip_address=None, local_port=None, remote_port=None, state=None, send_queue_length=None):  # noqa: E501
        """SocketStats - a model defined in Swagger"""  # noqa: E501

        self._pid = None
        self._sid = None
        self._protocol = None
        self._rxq_bytes = None
        self._txq_bytes = None
        self._local_ip_address = None
        self._remote_ip_address = None
        self._local_port = None
        self._remote_port = None
        self._state = None
        self._send_queue_length = None
        self.discriminator = None

        if pid is not None:
            self.pid = pid
        if sid is not None:
            self.sid = sid
        if protocol is not None:
            self.protocol = protocol
        if rxq_bytes is not None:
            self.rxq_bytes = rxq_bytes
        if txq_bytes is not None:
            self.txq_bytes = txq_bytes
        if local_ip_address is not None:
            self.local_ip_address = local_ip_address
        if remote_ip_address is not None:
            self.remote_ip_address = remote_ip_address
        if local_port is not None:
            self.local_port = local_port
        if remote_port is not None:
            self.remote_port = remote_port
        if state is not None:
            self.state = state
        if send_queue_length is not None:
            self.send_queue_length = send_queue_length

    @property
    def pid(self):
        """Gets the pid of this SocketStats.  # noqa: E501

        Process ID which created the socket  # noqa: E501

        :return: The pid of this SocketStats.  # noqa: E501
        :rtype: int
        """
        return self._pid

    @pid.setter
    def pid(self, pid):
        """Sets the pid of this SocketStats.

        Process ID which created the socket  # noqa: E501

        :param pid: The pid of this SocketStats.  # noqa: E501
        :type: int
        """
        self._pid = pid

    @property
    def sid(self):
        """Gets the sid of this SocketStats.  # noqa: E501

        The socket ID (used by server)  # noqa: E501

        :return: The sid of this SocketStats.  # noqa: E501
        :rtype: int
        """
        return self._sid

    @sid.setter
    def sid(self, sid):
        """Sets the sid of this SocketStats.

        The socket ID (used by server)  # noqa: E501

        :param sid: The sid of this SocketStats.  # noqa: E501
        :type: int
        """
        self._sid = sid

    @property
    def protocol(self):
        """Gets the protocol of this SocketStats.  # noqa: E501

        The protocol type  # noqa: E501

        :return: The protocol of this SocketStats.  # noqa: E501
        :rtype: str
        """
        return self._protocol

    @protocol.setter
    def protocol(self, protocol):
        """Sets the protocol of this SocketStats.

        The protocol type  # noqa: E501

        :param protocol: The protocol of this SocketStats.  # noqa: E501
        :type: str
        """
        self._protocol = protocol

    @property
    def rxq_bytes(self):
        """Gets the rxq_bytes of this SocketStats.  # noqa: E501

        Number of bytes in the socket receive queue  # noqa: E501

        :return: The rxq_bytes of this SocketStats.  # noqa: E501
        :rtype: int
        """
        return self._rxq_bytes

    @rxq_bytes.setter
    def rxq_bytes(self, rxq_bytes):
        """Sets the rxq_bytes of this SocketStats.

        Number of bytes in the socket receive queue  # noqa: E501

        :param rxq_bytes: The rxq_bytes of this SocketStats.  # noqa: E501
        :type: int
        """
        self._rxq_bytes = rxq_bytes

    @property
    def txq_bytes(self):
        """Gets the txq_bytes of this SocketStats.  # noqa: E501

        Number of bytes in the socket transmit queue  # noqa: E501

        :return: The txq_bytes of this SocketStats.  # noqa: E501
        :rtype: int
        """
        return self._txq_bytes

    @txq_bytes.setter
    def txq_bytes(self, txq_bytes):
        """Sets the txq_bytes of this SocketStats.

        Number of bytes in the socket transmit queue  # noqa: E501

        :param txq_bytes: The txq_bytes of this SocketStats.  # noqa: E501
        :type: int
        """
        self._txq_bytes = txq_bytes

    @property
    def local_ip_address(self):
        """Gets the local_ip_address of this SocketStats.  # noqa: E501

        The local IP address  # noqa: E501

        :return: The local_ip_address of this SocketStats.  # noqa: E501
        :rtype: str
        """
        return self._local_ip_address

    @local_ip_address.setter
    def local_ip_address(self, local_ip_address):
        """Sets the local_ip_address of this SocketStats.

        The local IP address  # noqa: E501

        :param local_ip_address: The local_ip_address of this SocketStats.  # noqa: E501
        :type: str
        """
        self._local_ip_address = local_ip_address

    @property
    def remote_ip_address(self):
        """Gets the remote_ip_address of this SocketStats.  # noqa: E501

        The remote IP address  # noqa: E501

        :return: The remote_ip_address of this SocketStats.  # noqa: E501
        :rtype: str
        """
        return self._remote_ip_address

    @remote_ip_address.setter
    def remote_ip_address(self, remote_ip_address):
        """Sets the remote_ip_address of this SocketStats.

        The remote IP address  # noqa: E501

        :param remote_ip_address: The remote_ip_address of this SocketStats.  # noqa: E501
        :type: str
        """
        self._remote_ip_address = remote_ip_address

    @property
    def local_port(self):
        """Gets the local_port of this SocketStats.  # noqa: E501

        The local port number  # noqa: E501

        :return: The local_port of this SocketStats.  # noqa: E501
        :rtype: int
        """
        return self._local_port

    @local_port.setter
    def local_port(self, local_port):
        """Sets the local_port of this SocketStats.

        The local port number  # noqa: E501

        :param local_port: The local_port of this SocketStats.  # noqa: E501
        :type: int
        """
        self._local_port = local_port

    @property
    def remote_port(self):
        """Gets the remote_port of this SocketStats.  # noqa: E501

        The remote port number  # noqa: E501

        :return: The remote_port of this SocketStats.  # noqa: E501
        :rtype: int
        """
        return self._remote_port

    @remote_port.setter
    def remote_port(self, remote_port):
        """Sets the remote_port of this SocketStats.

        The remote port number  # noqa: E501

        :param remote_port: The remote_port of this SocketStats.  # noqa: E501
        :type: int
        """
        self._remote_port = remote_port

    @property
    def state(self):
        """Gets the state of this SocketStats.  # noqa: E501

        The socket state  # noqa: E501

        :return: The state of this SocketStats.  # noqa: E501
        :rtype: str
        """
        return self._state

    @state.setter
    def state(self, state):
        """Sets the state of this SocketStats.

        The socket state  # noqa: E501

        :param state: The state of this SocketStats.  # noqa: E501
        :type: str
        """
        self._state = state

    @property
    def send_queue_length(self):
        """Gets the send_queue_length of this SocketStats.  # noqa: E501

        The number of packets in the protocol send queue  # noqa: E501

        :return: The send_queue_length of this SocketStats.  # noqa: E501
        :rtype: int
        """
        return self._send_queue_length

    @send_queue_length.setter
    def send_queue_length(self, send_queue_length):
        """Sets the send_queue_length of this SocketStats.

        The number of packets in the protocol send queue  # noqa: E501

        :param send_queue_length: The send_queue_length of this SocketStats.  # noqa: E501
        :type: int
        """
        self._send_queue_length = send_queue_length

    def to_dict(self):
        """Returns the model properties as a dict"""
        result = {}

        for attr, _ in six.iteritems(self.swagger_types):
            value = getattr(self, attr)
            if isinstance(value, list):
                result[attr] = list(map(
                    lambda x: x.to_dict() if hasattr(x, "to_dict") else x,
                    value
                ))
            elif hasattr(value, "to_dict"):
                result[attr] = value.to_dict()
            elif isinstance(value, dict):
                result[attr] = dict(map(
                    lambda item: (item[0], item[1].to_dict())
                    if hasattr(item[1], "to_dict") else item,
                    value.items()
                ))
            else:
                result[attr] = value
        if issubclass(SocketStats, dict):
            for key, value in self.items():
                result[key] = value

        return result

    def to_str(self):
        """Returns the string representation of the model"""
        return pprint.pformat(self.to_dict())

    def __repr__(self):
        """For `print` and `pprint`"""
        return self.to_str()

    def __eq__(self, other):
        """Returns true if both objects are equal"""
        if not isinstance(other, SocketStats):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
