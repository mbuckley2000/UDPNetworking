//
// Created by Matt on 10/09/2016.
//

#ifndef NETWORKING_TUTORIALS_CONNECTION_H
#define NETWORKING_TUTORIALS_CONNECTION_H
#include "UDPSocket.h"

class Connection {
public:
    Connection(UDPSocket *socket);
    int connect();
    char* encode(char* message);
    bool isConnected();

    int accept();

private:
    int protocolID = 24653;
    unsigned short sessionID;
    bool connected;
    UDPSocket* socket;
    UDPAddress* remoteAddress;
};


#endif //NETWORKING_TUTORIALS_CONNECTION_H
