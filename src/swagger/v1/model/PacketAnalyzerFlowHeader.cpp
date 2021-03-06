/**
* OpenPerf API
* REST API interface for OpenPerf
*
* OpenAPI spec version: 1
* Contact: support@spirent.com
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/swagger-api/swagger-codegen.git
* Do not edit the class manually.
*/


#include "PacketAnalyzerFlowHeader.h"

namespace swagger {
namespace v1 {
namespace model {

PacketAnalyzerFlowHeader::PacketAnalyzerFlowHeader()
{
    m_EthernetIsSet = false;
    m_Ipv4IsSet = false;
    m_Ipv6IsSet = false;
    m_MplsIsSet = false;
    m_TcpIsSet = false;
    m_UdpIsSet = false;
    m_VlanIsSet = false;
    m_Unknown = "";
    m_UnknownIsSet = false;
    
}

PacketAnalyzerFlowHeader::~PacketAnalyzerFlowHeader()
{
}

void PacketAnalyzerFlowHeader::validate()
{
    // TODO: implement validation
}

nlohmann::json PacketAnalyzerFlowHeader::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    if(m_EthernetIsSet)
    {
        val["ethernet"] = ModelBase::toJson(m_Ethernet);
    }
    if(m_Ipv4IsSet)
    {
        val["ipv4"] = ModelBase::toJson(m_Ipv4);
    }
    if(m_Ipv6IsSet)
    {
        val["ipv6"] = ModelBase::toJson(m_Ipv6);
    }
    if(m_MplsIsSet)
    {
        val["mpls"] = ModelBase::toJson(m_Mpls);
    }
    if(m_TcpIsSet)
    {
        val["tcp"] = ModelBase::toJson(m_Tcp);
    }
    if(m_UdpIsSet)
    {
        val["udp"] = ModelBase::toJson(m_Udp);
    }
    if(m_VlanIsSet)
    {
        val["vlan"] = ModelBase::toJson(m_Vlan);
    }
    if(m_UnknownIsSet)
    {
        val["unknown"] = ModelBase::toJson(m_Unknown);
    }
    

    return val;
}

void PacketAnalyzerFlowHeader::fromJson(nlohmann::json& val)
{
    if(val.find("ethernet") != val.end())
    {
        if(!val["ethernet"].is_null())
        {
            std::shared_ptr<PacketProtocolEthernet> newItem(new PacketProtocolEthernet());
            newItem->fromJson(val["ethernet"]);
            setEthernet( newItem );
        }
        
    }
    if(val.find("ipv4") != val.end())
    {
        if(!val["ipv4"].is_null())
        {
            std::shared_ptr<PacketProtocolIpv4> newItem(new PacketProtocolIpv4());
            newItem->fromJson(val["ipv4"]);
            setIpv4( newItem );
        }
        
    }
    if(val.find("ipv6") != val.end())
    {
        if(!val["ipv6"].is_null())
        {
            std::shared_ptr<PacketProtocolIpv6> newItem(new PacketProtocolIpv6());
            newItem->fromJson(val["ipv6"]);
            setIpv6( newItem );
        }
        
    }
    if(val.find("mpls") != val.end())
    {
        if(!val["mpls"].is_null())
        {
            std::shared_ptr<PacketProtocolMpls> newItem(new PacketProtocolMpls());
            newItem->fromJson(val["mpls"]);
            setMpls( newItem );
        }
        
    }
    if(val.find("tcp") != val.end())
    {
        if(!val["tcp"].is_null())
        {
            std::shared_ptr<PacketProtocolTcp> newItem(new PacketProtocolTcp());
            newItem->fromJson(val["tcp"]);
            setTcp( newItem );
        }
        
    }
    if(val.find("udp") != val.end())
    {
        if(!val["udp"].is_null())
        {
            std::shared_ptr<PacketProtocolUdp> newItem(new PacketProtocolUdp());
            newItem->fromJson(val["udp"]);
            setUdp( newItem );
        }
        
    }
    if(val.find("vlan") != val.end())
    {
        if(!val["vlan"].is_null())
        {
            std::shared_ptr<PacketProtocolVlan> newItem(new PacketProtocolVlan());
            newItem->fromJson(val["vlan"]);
            setVlan( newItem );
        }
        
    }
    if(val.find("unknown") != val.end())
    {
        setUnknown(val.at("unknown"));
        
    }
    
}


std::shared_ptr<PacketProtocolEthernet> PacketAnalyzerFlowHeader::getEthernet() const
{
    return m_Ethernet;
}
void PacketAnalyzerFlowHeader::setEthernet(std::shared_ptr<PacketProtocolEthernet> value)
{
    m_Ethernet = value;
    m_EthernetIsSet = true;
}
bool PacketAnalyzerFlowHeader::ethernetIsSet() const
{
    return m_EthernetIsSet;
}
void PacketAnalyzerFlowHeader::unsetEthernet()
{
    m_EthernetIsSet = false;
}
std::shared_ptr<PacketProtocolIpv4> PacketAnalyzerFlowHeader::getIpv4() const
{
    return m_Ipv4;
}
void PacketAnalyzerFlowHeader::setIpv4(std::shared_ptr<PacketProtocolIpv4> value)
{
    m_Ipv4 = value;
    m_Ipv4IsSet = true;
}
bool PacketAnalyzerFlowHeader::ipv4IsSet() const
{
    return m_Ipv4IsSet;
}
void PacketAnalyzerFlowHeader::unsetIpv4()
{
    m_Ipv4IsSet = false;
}
std::shared_ptr<PacketProtocolIpv6> PacketAnalyzerFlowHeader::getIpv6() const
{
    return m_Ipv6;
}
void PacketAnalyzerFlowHeader::setIpv6(std::shared_ptr<PacketProtocolIpv6> value)
{
    m_Ipv6 = value;
    m_Ipv6IsSet = true;
}
bool PacketAnalyzerFlowHeader::ipv6IsSet() const
{
    return m_Ipv6IsSet;
}
void PacketAnalyzerFlowHeader::unsetIpv6()
{
    m_Ipv6IsSet = false;
}
std::shared_ptr<PacketProtocolMpls> PacketAnalyzerFlowHeader::getMpls() const
{
    return m_Mpls;
}
void PacketAnalyzerFlowHeader::setMpls(std::shared_ptr<PacketProtocolMpls> value)
{
    m_Mpls = value;
    m_MplsIsSet = true;
}
bool PacketAnalyzerFlowHeader::mplsIsSet() const
{
    return m_MplsIsSet;
}
void PacketAnalyzerFlowHeader::unsetMpls()
{
    m_MplsIsSet = false;
}
std::shared_ptr<PacketProtocolTcp> PacketAnalyzerFlowHeader::getTcp() const
{
    return m_Tcp;
}
void PacketAnalyzerFlowHeader::setTcp(std::shared_ptr<PacketProtocolTcp> value)
{
    m_Tcp = value;
    m_TcpIsSet = true;
}
bool PacketAnalyzerFlowHeader::tcpIsSet() const
{
    return m_TcpIsSet;
}
void PacketAnalyzerFlowHeader::unsetTcp()
{
    m_TcpIsSet = false;
}
std::shared_ptr<PacketProtocolUdp> PacketAnalyzerFlowHeader::getUdp() const
{
    return m_Udp;
}
void PacketAnalyzerFlowHeader::setUdp(std::shared_ptr<PacketProtocolUdp> value)
{
    m_Udp = value;
    m_UdpIsSet = true;
}
bool PacketAnalyzerFlowHeader::udpIsSet() const
{
    return m_UdpIsSet;
}
void PacketAnalyzerFlowHeader::unsetUdp()
{
    m_UdpIsSet = false;
}
std::shared_ptr<PacketProtocolVlan> PacketAnalyzerFlowHeader::getVlan() const
{
    return m_Vlan;
}
void PacketAnalyzerFlowHeader::setVlan(std::shared_ptr<PacketProtocolVlan> value)
{
    m_Vlan = value;
    m_VlanIsSet = true;
}
bool PacketAnalyzerFlowHeader::vlanIsSet() const
{
    return m_VlanIsSet;
}
void PacketAnalyzerFlowHeader::unsetVlan()
{
    m_VlanIsSet = false;
}
std::string PacketAnalyzerFlowHeader::getUnknown() const
{
    return m_Unknown;
}
void PacketAnalyzerFlowHeader::setUnknown(std::string value)
{
    m_Unknown = value;
    m_UnknownIsSet = true;
}
bool PacketAnalyzerFlowHeader::unknownIsSet() const
{
    return m_UnknownIsSet;
}
void PacketAnalyzerFlowHeader::unsetUnknown()
{
    m_UnknownIsSet = false;
}

}
}
}

