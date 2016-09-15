//
// Created by Matt on 15/09/2016.
//

#ifndef NETWORKING_TUTORIALS_CONNECTIONHANDLER_H
#define NETWORKING_TUTORIALS_CONNECTIONHANDLER_H


#include <list>
#include "Packet.h"
#include "Connection.h"

class ConnectionHandler {
public:
    ConnectionHandler(UDPSocket *socket);

    int processPacket(Packet *packet);

private:
    std::list<Connection> connections;
    UDPSocket *socket;
};


#endif //NETWORKING_TUTORIALS_CONNECTIONHANDLER_H
