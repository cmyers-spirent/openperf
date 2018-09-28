/**
* Inception Core API
* REST API interface to the Inception Core
*
* OpenAPI spec version: 1
* Contact: support@spirent.com
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/swagger-api/swagger-codegen.git
* Do not edit the class manually.
*/


#include "Interface.h"

namespace swagger {
namespace v1 {
namespace model {

Interface::Interface()
{
    m_Id = "";
    
}

Interface::~Interface()
{
}

void Interface::validate()
{
    // TODO: implement validation
}

nlohmann::json Interface::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    val["id"] = ModelBase::toJson(m_Id);
    val["config"] = ModelBase::toJson(m_Config);
    val["stats"] = ModelBase::toJson(m_Stats);
    

    return val;
}

void Interface::fromJson(nlohmann::json& val)
{
    setId(val.at("id"));
    
}


std::string Interface::getId() const
{
    return m_Id;
}
void Interface::setId(std::string value)
{
    m_Id = value;
    
}
std::shared_ptr<Interface_config> Interface::getConfig() const
{
    return m_Config;
}
void Interface::setConfig(std::shared_ptr<Interface_config> value)
{
    m_Config = value;
    
}
std::shared_ptr<InterfaceStats> Interface::getStats() const
{
    return m_Stats;
}
void Interface::setStats(std::shared_ptr<InterfaceStats> value)
{
    m_Stats = value;
    
}

}
}
}
