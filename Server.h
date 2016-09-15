//
// Created by Matt on 12/09/2016.
//

#ifndef NETWORKING_TUTORIALS_SERVER_H
#define NETWORKING_TUTORIALS_SERVER_H


#include <map>
#include <queue>
#include "UDPSocket.h"
#include "Packet.h"
#include "Connection.h"
#include "ConnectionHandler.h"

class Server {
public:
    Server(UDPSocket *socket);

    bool update();

    bool isRunning();
private:
    void processIncomingPackets();

    bool running;
    UDPSocket *socket;
    ConnectionHandler *connectionHandler;
};


#endif //NETWORKING_TUTORIALS_SERVER_H
