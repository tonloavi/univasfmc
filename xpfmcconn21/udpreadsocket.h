#ifndef UDPREADSOCKET_H
#define UDPREADSOCKET_H

#include <string>
#include "my_include.h"
#include "network_config.h"

class UDPReadSocket
{
public:
    UDPReadSocket();
    ~UDPReadSocket();
    void configure(const std::string& host, int port);
    long read(void* data, size_t maxsize);
private:
    int         sockId, charsReceived, port;
    uint32_t    address;
    char        msg[BUFF_LEN];
    struct sockaddr_in  myAddr, fromAddr;
    socklen_t   fromAddr_len;
    struct      ip_mreq multicast;
    bool        m_multicastActive;
};

#endif // UDPREADSOCKET_H
