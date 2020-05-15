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
 * BulkDeleteCapturesRequest.h
 *
 * Parameters for the bulk delete operation
 */

#ifndef BulkDeleteCapturesRequest_H_
#define BulkDeleteCapturesRequest_H_


#include "ModelBase.h"

#include <string>
#include <vector>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Parameters for the bulk delete operation
/// </summary>
class  BulkDeleteCapturesRequest
    : public ModelBase
{
public:
    BulkDeleteCapturesRequest();
    virtual ~BulkDeleteCapturesRequest();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// BulkDeleteCapturesRequest members

    /// <summary>
    /// List of packet captures
    /// </summary>
    std::vector<std::string>& getIds();
    
protected:
    std::vector<std::string> m_Ids;

};

}
}
}

#endif /* BulkDeleteCapturesRequest_H_ */