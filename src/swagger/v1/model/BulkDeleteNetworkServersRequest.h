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
 * BulkDeleteNetworkServersRequest.h
 *
 * Parameters for the bulk delete operation
 */

#ifndef BulkDeleteNetworkServersRequest_H_
#define BulkDeleteNetworkServersRequest_H_


#include "ModelBase.h"

#include <string>
#include <vector>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Parameters for the bulk delete operation
/// </summary>
class  BulkDeleteNetworkServersRequest
    : public ModelBase
{
public:
    BulkDeleteNetworkServersRequest();
    virtual ~BulkDeleteNetworkServersRequest();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// BulkDeleteNetworkServersRequest members

    /// <summary>
    /// List of network server ids
    /// </summary>
    std::vector<std::string>& getIds();
    
protected:
    std::vector<std::string> m_Ids;

};

}
}
}

#endif /* BulkDeleteNetworkServersRequest_H_ */
