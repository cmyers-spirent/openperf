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


#include "PacketProtocolMpls.h"

namespace swagger {
namespace v1 {
namespace model {

PacketProtocolMpls::PacketProtocolMpls()
{
    m_Bottom_of_stack = false;
    m_Bottom_of_stackIsSet = false;
    m_Label = 0;
    m_LabelIsSet = false;
    m_Traffic_class = 0;
    m_Traffic_classIsSet = false;
    m_Ttl = 0;
    m_TtlIsSet = false;
    
}

PacketProtocolMpls::~PacketProtocolMpls()
{
}

void PacketProtocolMpls::validate()
{
    // TODO: implement validation
}

nlohmann::json PacketProtocolMpls::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    if(m_Bottom_of_stackIsSet)
    {
        val["bottom_of_stack"] = m_Bottom_of_stack;
    }
    if(m_LabelIsSet)
    {
        val["label"] = m_Label;
    }
    if(m_Traffic_classIsSet)
    {
        val["traffic_class"] = m_Traffic_class;
    }
    if(m_TtlIsSet)
    {
        val["ttl"] = m_Ttl;
    }
    

    return val;
}

void PacketProtocolMpls::fromJson(nlohmann::json& val)
{
    if(val.find("bottom_of_stack") != val.end())
    {
        setBottomOfStack(val.at("bottom_of_stack"));
    }
    if(val.find("label") != val.end())
    {
        setLabel(val.at("label"));
    }
    if(val.find("traffic_class") != val.end())
    {
        setTrafficClass(val.at("traffic_class"));
    }
    if(val.find("ttl") != val.end())
    {
        setTtl(val.at("ttl"));
    }
    
}


bool PacketProtocolMpls::isBottomOfStack() const
{
    return m_Bottom_of_stack;
}
void PacketProtocolMpls::setBottomOfStack(bool value)
{
    m_Bottom_of_stack = value;
    m_Bottom_of_stackIsSet = true;
}
bool PacketProtocolMpls::bottomOfStackIsSet() const
{
    return m_Bottom_of_stackIsSet;
}
void PacketProtocolMpls::unsetBottom_of_stack()
{
    m_Bottom_of_stackIsSet = false;
}
int32_t PacketProtocolMpls::getLabel() const
{
    return m_Label;
}
void PacketProtocolMpls::setLabel(int32_t value)
{
    m_Label = value;
    m_LabelIsSet = true;
}
bool PacketProtocolMpls::labelIsSet() const
{
    return m_LabelIsSet;
}
void PacketProtocolMpls::unsetLabel()
{
    m_LabelIsSet = false;
}
int32_t PacketProtocolMpls::getTrafficClass() const
{
    return m_Traffic_class;
}
void PacketProtocolMpls::setTrafficClass(int32_t value)
{
    m_Traffic_class = value;
    m_Traffic_classIsSet = true;
}
bool PacketProtocolMpls::trafficClassIsSet() const
{
    return m_Traffic_classIsSet;
}
void PacketProtocolMpls::unsetTraffic_class()
{
    m_Traffic_classIsSet = false;
}
int32_t PacketProtocolMpls::getTtl() const
{
    return m_Ttl;
}
void PacketProtocolMpls::setTtl(int32_t value)
{
    m_Ttl = value;
    m_TtlIsSet = true;
}
bool PacketProtocolMpls::ttlIsSet() const
{
    return m_TtlIsSet;
}
void PacketProtocolMpls::unsetTtl()
{
    m_TtlIsSet = false;
}

}
}
}

