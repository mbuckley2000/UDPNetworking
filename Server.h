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

class Server {
public:
    Server(UDPSocket *socket);

    bool update();

    bool isRunning();

    bool sendPacket(UDPAddress *addr, Packet *packet);

private:
    Packet *processIncomingPackets();

    void processPacketQueue();

    bool running;
    UDPSocket *socket;

    bool sendHandshake(UDPAddress *addr);

    std::map<UDPAddress *, Connection> connectionMap;
    std::queue<Packet *> packetQueue;
};


#endif //NETWORKING_TUTORIALS_SERVER_H
