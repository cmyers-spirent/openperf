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
/*
 * PortConfig_dpdk.h
 *
 * DPDK-specific configuration information
 */

#ifndef PortConfig_dpdk_H_
#define PortConfig_dpdk_H_


#include "ModelBase.h"

#include <string>

namespace icp {
namespace api {
namespace v1 {
namespace model {

/// <summary>
/// DPDK-specific configuration information
/// </summary>
class  PortConfig_dpdk
    : public ModelBase
{
public:
    PortConfig_dpdk();
    virtual ~PortConfig_dpdk();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// PortConfig_dpdk members

    /// <summary>
    /// Enable link auto-negotiation
    /// </summary>
    bool isAutoNegotiation() const;
    void setAutoNegotiation(bool value);
        /// <summary>
    /// Manually-configured port speed (in Mbps)
    /// </summary>
    int64_t getSpeed() const;
    void setSpeed(int64_t value);
    bool speedIsSet() const;
    void unsetSpeed();
    /// <summary>
    /// Manually-configured port duplex
    /// </summary>
    std::string getDuplex() const;
    void setDuplex(std::string value);
    bool duplexIsSet() const;
    void unsetDuplex();

protected:
    bool m_Auto_negotiation;

    int64_t m_Speed;
    bool m_SpeedIsSet;
    std::string m_Duplex;
    bool m_DuplexIsSet;
};

}
}
}
}

#endif /* PortConfig_dpdk_H_ */
