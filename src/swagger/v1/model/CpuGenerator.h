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
/*
 * CpuGenerator.h
 *
 * CPU generator
 */

#ifndef CpuGenerator_H_
#define CpuGenerator_H_


#include "ModelBase.h"

#include <string>
#include "CpuGeneratorConfig.h"

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// CPU generator
/// </summary>
class  CpuGenerator
    : public ModelBase
{
public:
    CpuGenerator();
    virtual ~CpuGenerator();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// CpuGenerator members

    /// <summary>
    /// Unique CPU generator identifier
    /// </summary>
    std::string getId() const;
    void setId(std::string value);
        /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<CpuGeneratorConfig> getConfig() const;
    void setConfig(std::shared_ptr<CpuGeneratorConfig> value);
        /// <summary>
    /// Indicates whether this generator is currently running.
    /// </summary>
    bool isRunning() const;
    void setRunning(bool value);
    
protected:
    std::string m_Id;

    std::shared_ptr<CpuGeneratorConfig> m_Config;

    bool m_Running;

};

}
}
}

#endif /* CpuGenerator_H_ */
