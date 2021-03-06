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


#include "TrafficProtocolFieldModifier.h"

namespace swagger {
namespace v1 {
namespace model {

TrafficProtocolFieldModifier::TrafficProtocolFieldModifier()
{
    m_ListIsSet = false;
    m_SequenceIsSet = false;
    
}

TrafficProtocolFieldModifier::~TrafficProtocolFieldModifier()
{
}

void TrafficProtocolFieldModifier::validate()
{
    // TODO: implement validation
}

nlohmann::json TrafficProtocolFieldModifier::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    {
        nlohmann::json jsonArray;
        for( auto& item : m_List )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            val["list"] = jsonArray;
        }
    }
    if(m_SequenceIsSet)
    {
        val["sequence"] = ModelBase::toJson(m_Sequence);
    }
    

    return val;
}

void TrafficProtocolFieldModifier::fromJson(nlohmann::json& val)
{
    {
        m_List.clear();
        nlohmann::json jsonArray;
        if(val.find("list") != val.end())
        {
        for( auto& item : val["list"] )
        {
            m_List.push_back(item);
            
        }
        }
    }
    if(val.find("sequence") != val.end())
    {
        if(!val["sequence"].is_null())
        {
            std::shared_ptr<TrafficProtocolFieldModifier_sequence> newItem(new TrafficProtocolFieldModifier_sequence());
            newItem->fromJson(val["sequence"]);
            setSequence( newItem );
        }
        
    }
    
}


std::vector<int32_t>& TrafficProtocolFieldModifier::getList()
{
    return m_List;
}
bool TrafficProtocolFieldModifier::listIsSet() const
{
    return m_ListIsSet;
}
void TrafficProtocolFieldModifier::unsetList()
{
    m_ListIsSet = false;
}
std::shared_ptr<TrafficProtocolFieldModifier_sequence> TrafficProtocolFieldModifier::getSequence() const
{
    return m_Sequence;
}
void TrafficProtocolFieldModifier::setSequence(std::shared_ptr<TrafficProtocolFieldModifier_sequence> value)
{
    m_Sequence = value;
    m_SequenceIsSet = true;
}
bool TrafficProtocolFieldModifier::sequenceIsSet() const
{
    return m_SequenceIsSet;
}
void TrafficProtocolFieldModifier::unsetSequence()
{
    m_SequenceIsSet = false;
}

}
}
}

