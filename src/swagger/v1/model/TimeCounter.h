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
 * TimeCounter.h
 *
 * A source of clock ticks
 */

#ifndef TimeCounter_H_
#define TimeCounter_H_


#include "ModelBase.h"

#include <string>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// A source of clock ticks
/// </summary>
class  TimeCounter
    : public ModelBase
{
public:
    TimeCounter();
    virtual ~TimeCounter();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// TimeCounter members

    /// <summary>
    /// Unique time counter identifier
    /// </summary>
    std::string getId() const;
    void setId(std::string value);
        /// <summary>
    /// Time counter name
    /// </summary>
    std::string getName() const;
    void setName(std::string value);
        /// <summary>
    /// Tick rate of the counter, in Hz.
    /// </summary>
    int64_t getFrequency() const;
    void setFrequency(int64_t value);
        /// <summary>
    /// Priority determines which counter to use in situations where there are multiple counters available (higher number &#x3D; higher priority). Priority is always positive. 
    /// </summary>
    int32_t getPriority() const;
    void setPriority(int32_t value);
    
protected:
    std::string m_Id;

    std::string m_Name;

    int64_t m_Frequency;

    int32_t m_Priority;

};

}
}
}

#endif /* TimeCounter_H_ */