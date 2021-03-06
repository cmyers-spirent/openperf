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


#include "Port.h"

namespace swagger {
namespace v1 {
namespace model {

Port::Port()
{
    m_Id = "";
    m_Kind = "";
    
}

Port::~Port()
{
}

void Port::validate()
{
    // TODO: implement validation
}

nlohmann::json Port::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    val["id"] = ModelBase::toJson(m_Id);
    val["kind"] = ModelBase::toJson(m_Kind);
    val["config"] = ModelBase::toJson(m_Config);
    val["status"] = ModelBase::toJson(m_Status);
    val["stats"] = ModelBase::toJson(m_Stats);
    

    return val;
}

void Port::fromJson(nlohmann::json& val)
{
    setId(val.at("id"));
    setKind(val.at("kind"));
    
}


std::string Port::getId() const
{
    return m_Id;
}
void Port::setId(std::string value)
{
    m_Id = value;
    
}
std::string Port::getKind() const
{
    return m_Kind;
}
void Port::setKind(std::string value)
{
    m_Kind = value;
    
}
std::shared_ptr<PortConfig> Port::getConfig() const
{
    return m_Config;
}
void Port::setConfig(std::shared_ptr<PortConfig> value)
{
    m_Config = value;
    
}
std::shared_ptr<PortStatus> Port::getStatus() const
{
    return m_Status;
}
void Port::setStatus(std::shared_ptr<PortStatus> value)
{
    m_Status = value;
    
}
std::shared_ptr<PortStats> Port::getStats() const
{
    return m_Stats;
}
void Port::setStats(std::shared_ptr<PortStats> value)
{
    m_Stats = value;
    
}

}
}
}

