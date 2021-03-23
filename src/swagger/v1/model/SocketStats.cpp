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


#include "SocketStats.h"

namespace swagger {
namespace v1 {
namespace model {

SocketStats::SocketStats()
{
    m_Pid = 0;
    m_PidIsSet = false;
    m_Sid = 0;
    m_SidIsSet = false;
    m_Protocol = "";
    m_ProtocolIsSet = false;
    m_Rxq_bytes = 0L;
    m_Rxq_bytesIsSet = false;
    m_Txq_bytes = 0L;
    m_Txq_bytesIsSet = false;
    m_Local_ip_address = "";
    m_Local_ip_addressIsSet = false;
    m_Remote_ip_address = "";
    m_Remote_ip_addressIsSet = false;
    m_Local_port = 0;
    m_Local_portIsSet = false;
    m_Remote_port = 0;
    m_Remote_portIsSet = false;
    m_State = "";
    m_StateIsSet = false;
    m_Send_queue_length = 0;
    m_Send_queue_lengthIsSet = false;
    
}

SocketStats::~SocketStats()
{
}

void SocketStats::validate()
{
    // TODO: implement validation
}

nlohmann::json SocketStats::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    if(m_PidIsSet)
    {
        val["pid"] = m_Pid;
    }
    if(m_SidIsSet)
    {
        val["sid"] = m_Sid;
    }
    if(m_ProtocolIsSet)
    {
        val["protocol"] = ModelBase::toJson(m_Protocol);
    }
    if(m_Rxq_bytesIsSet)
    {
        val["rxq_bytes"] = m_Rxq_bytes;
    }
    if(m_Txq_bytesIsSet)
    {
        val["txq_bytes"] = m_Txq_bytes;
    }
    if(m_Local_ip_addressIsSet)
    {
        val["local_ip_address"] = ModelBase::toJson(m_Local_ip_address);
    }
    if(m_Remote_ip_addressIsSet)
    {
        val["remote_ip_address"] = ModelBase::toJson(m_Remote_ip_address);
    }
    if(m_Local_portIsSet)
    {
        val["local_port"] = m_Local_port;
    }
    if(m_Remote_portIsSet)
    {
        val["remote_port"] = m_Remote_port;
    }
    if(m_StateIsSet)
    {
        val["state"] = ModelBase::toJson(m_State);
    }
    if(m_Send_queue_lengthIsSet)
    {
        val["send_queue_length"] = m_Send_queue_length;
    }
    

    return val;
}

void SocketStats::fromJson(nlohmann::json& val)
{
    if(val.find("pid") != val.end())
    {
        setPid(val.at("pid"));
    }
    if(val.find("sid") != val.end())
    {
        setSid(val.at("sid"));
    }
    if(val.find("protocol") != val.end())
    {
        setProtocol(val.at("protocol"));
        
    }
    if(val.find("rxq_bytes") != val.end())
    {
        setRxqBytes(val.at("rxq_bytes"));
    }
    if(val.find("txq_bytes") != val.end())
    {
        setTxqBytes(val.at("txq_bytes"));
    }
    if(val.find("local_ip_address") != val.end())
    {
        setLocalIpAddress(val.at("local_ip_address"));
        
    }
    if(val.find("remote_ip_address") != val.end())
    {
        setRemoteIpAddress(val.at("remote_ip_address"));
        
    }
    if(val.find("local_port") != val.end())
    {
        setLocalPort(val.at("local_port"));
    }
    if(val.find("remote_port") != val.end())
    {
        setRemotePort(val.at("remote_port"));
    }
    if(val.find("state") != val.end())
    {
        setState(val.at("state"));
        
    }
    if(val.find("send_queue_length") != val.end())
    {
        setSendQueueLength(val.at("send_queue_length"));
    }
    
}


int32_t SocketStats::getPid() const
{
    return m_Pid;
}
void SocketStats::setPid(int32_t value)
{
    m_Pid = value;
    m_PidIsSet = true;
}
bool SocketStats::pidIsSet() const
{
    return m_PidIsSet;
}
void SocketStats::unsetPid()
{
    m_PidIsSet = false;
}
int32_t SocketStats::getSid() const
{
    return m_Sid;
}
void SocketStats::setSid(int32_t value)
{
    m_Sid = value;
    m_SidIsSet = true;
}
bool SocketStats::sidIsSet() const
{
    return m_SidIsSet;
}
void SocketStats::unsetSid()
{
    m_SidIsSet = false;
}
std::string SocketStats::getProtocol() const
{
    return m_Protocol;
}
void SocketStats::setProtocol(std::string value)
{
    m_Protocol = value;
    m_ProtocolIsSet = true;
}
bool SocketStats::protocolIsSet() const
{
    return m_ProtocolIsSet;
}
void SocketStats::unsetProtocol()
{
    m_ProtocolIsSet = false;
}
int64_t SocketStats::getRxqBytes() const
{
    return m_Rxq_bytes;
}
void SocketStats::setRxqBytes(int64_t value)
{
    m_Rxq_bytes = value;
    m_Rxq_bytesIsSet = true;
}
bool SocketStats::rxqBytesIsSet() const
{
    return m_Rxq_bytesIsSet;
}
void SocketStats::unsetRxq_bytes()
{
    m_Rxq_bytesIsSet = false;
}
int64_t SocketStats::getTxqBytes() const
{
    return m_Txq_bytes;
}
void SocketStats::setTxqBytes(int64_t value)
{
    m_Txq_bytes = value;
    m_Txq_bytesIsSet = true;
}
bool SocketStats::txqBytesIsSet() const
{
    return m_Txq_bytesIsSet;
}
void SocketStats::unsetTxq_bytes()
{
    m_Txq_bytesIsSet = false;
}
std::string SocketStats::getLocalIpAddress() const
{
    return m_Local_ip_address;
}
void SocketStats::setLocalIpAddress(std::string value)
{
    m_Local_ip_address = value;
    m_Local_ip_addressIsSet = true;
}
bool SocketStats::localIpAddressIsSet() const
{
    return m_Local_ip_addressIsSet;
}
void SocketStats::unsetLocal_ip_address()
{
    m_Local_ip_addressIsSet = false;
}
std::string SocketStats::getRemoteIpAddress() const
{
    return m_Remote_ip_address;
}
void SocketStats::setRemoteIpAddress(std::string value)
{
    m_Remote_ip_address = value;
    m_Remote_ip_addressIsSet = true;
}
bool SocketStats::remoteIpAddressIsSet() const
{
    return m_Remote_ip_addressIsSet;
}
void SocketStats::unsetRemote_ip_address()
{
    m_Remote_ip_addressIsSet = false;
}
int32_t SocketStats::getLocalPort() const
{
    return m_Local_port;
}
void SocketStats::setLocalPort(int32_t value)
{
    m_Local_port = value;
    m_Local_portIsSet = true;
}
bool SocketStats::localPortIsSet() const
{
    return m_Local_portIsSet;
}
void SocketStats::unsetLocal_port()
{
    m_Local_portIsSet = false;
}
int32_t SocketStats::getRemotePort() const
{
    return m_Remote_port;
}
void SocketStats::setRemotePort(int32_t value)
{
    m_Remote_port = value;
    m_Remote_portIsSet = true;
}
bool SocketStats::remotePortIsSet() const
{
    return m_Remote_portIsSet;
}
void SocketStats::unsetRemote_port()
{
    m_Remote_portIsSet = false;
}
std::string SocketStats::getState() const
{
    return m_State;
}
void SocketStats::setState(std::string value)
{
    m_State = value;
    m_StateIsSet = true;
}
bool SocketStats::stateIsSet() const
{
    return m_StateIsSet;
}
void SocketStats::unsetState()
{
    m_StateIsSet = false;
}
int32_t SocketStats::getSendQueueLength() const
{
    return m_Send_queue_length;
}
void SocketStats::setSendQueueLength(int32_t value)
{
    m_Send_queue_length = value;
    m_Send_queue_lengthIsSet = true;
}
bool SocketStats::sendQueueLengthIsSet() const
{
    return m_Send_queue_lengthIsSet;
}
void SocketStats::unsetSend_queue_length()
{
    m_Send_queue_lengthIsSet = false;
}

}
}
}

