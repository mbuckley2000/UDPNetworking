//
// Created by Matt on 10/09/2016.
//

#ifndef NETWORKING_TUTORIALS_UDPCONNECTION_H
#define NETWORKING_TUTORIALS_UDPCONNECTION_H
#include "UDPSocket.h"

class UDPSession {
public:
    UDPSession(UDPSocket* socket, UDPAddress* remoteAddress);
    int connect();
    char* encode(char* message);
    bool isConnected();

private:
    int protocolID = 24653;
    unsigned short sessionID;
    bool connected;
    UDPSocket* socket;
    UDPAddress* remoteAddress;
};


#endif //NETWORKING_TUTORIALS_UDPCONNECTION_H
