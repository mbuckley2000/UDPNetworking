//
// Created by Matt on 12/09/2016.
//

#ifndef NETWORKING_TUTORIALS_SERVER_H
#define NETWORKING_TUTORIALS_SERVER_H


#include "UDPSocket.h"
#include "Packet.h"

class Server {
public:
    Server(UDPSocket *socket);

    bool update();

    bool isRunning();

private:
    Packet *getPacket();

    bool running;
    UDPSocket *socket;

    bool sendHandshake(UDPAddress *addr);

    bool sendPacket(UDPAddress *addr, Packet *packet);
};


#endif //NETWORKING_TUTORIALS_SERVER_H
