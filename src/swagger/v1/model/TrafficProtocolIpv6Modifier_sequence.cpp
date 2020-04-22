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


#include "TrafficProtocolIpv6Modifier_sequence.h"

namespace swagger {
namespace v1 {
namespace model {

TrafficProtocolIpv6Modifier_sequence::TrafficProtocolIpv6Modifier_sequence()
{
    m_Count = 0;
    m_Start = "";
    m_Stop = "";
    m_StopIsSet = false;
    m_SkipIsSet = false;
    
}

TrafficProtocolIpv6Modifier_sequence::~TrafficProtocolIpv6Modifier_sequence()
{
}

void TrafficProtocolIpv6Modifier_sequence::validate()
{
    // TODO: implement validation
}

nlohmann::json TrafficProtocolIpv6Modifier_sequence::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    val["count"] = m_Count;
    val["start"] = ModelBase::toJson(m_Start);
    if(m_StopIsSet)
    {
        val["stop"] = ModelBase::toJson(m_Stop);
    }
    {
        nlohmann::json jsonArray;
        for( auto& item : m_Skip )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            val["skip"] = jsonArray;
        }
    }
    

    return val;
}

void TrafficProtocolIpv6Modifier_sequence::fromJson(nlohmann::json& val)
{
    setCount(val.at("count"));
    setStart(val.at("start"));
    if(val.find("stop") != val.end())
    {
        setStop(val.at("stop"));
        
    }
    {
        m_Skip.clear();
        nlohmann::json jsonArray;
        if(val.find("skip") != val.end())
        {
        for( auto& item : val["skip"] )
        {
            m_Skip.push_back(item);
            
        }
        }
    }
    
}


int32_t TrafficProtocolIpv6Modifier_sequence::getCount() const
{
    return m_Count;
}
void TrafficProtocolIpv6Modifier_sequence::setCount(int32_t value)
{
    m_Count = value;
    
}
std::string TrafficProtocolIpv6Modifier_sequence::getStart() const
{
    return m_Start;
}
void TrafficProtocolIpv6Modifier_sequence::setStart(std::string value)
{
    m_Start = value;
    
}
std::string TrafficProtocolIpv6Modifier_sequence::getStop() const
{
    return m_Stop;
}
void TrafficProtocolIpv6Modifier_sequence::setStop(std::string value)
{
    m_Stop = value;
    m_StopIsSet = true;
}
bool TrafficProtocolIpv6Modifier_sequence::stopIsSet() const
{
    return m_StopIsSet;
}
void TrafficProtocolIpv6Modifier_sequence::unsetStop()
{
    m_StopIsSet = false;
}
std::vector<std::string>& TrafficProtocolIpv6Modifier_sequence::getSkip()
{
    return m_Skip;
}
bool TrafficProtocolIpv6Modifier_sequence::skipIsSet() const
{
    return m_SkipIsSet;
}
void TrafficProtocolIpv6Modifier_sequence::unsetSkip()
{
    m_SkipIsSet = false;
}

}
}
}
