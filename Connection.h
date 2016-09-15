//
// Created by Matt on 10/09/2016.
//

#ifndef NETWORKING_TUTORIALS_CONNECTION_H
#define NETWORKING_TUTORIALS_CONNECTION_H

#include <queue>
#include "UDPSocket.h"
#include "Packet.h"

class Connection {
public:
    Connection(UDPAddress remoteAddress, UDPSocket *socket);
    int connect();
    bool isConnected();

    void addPacket(Packet *packet);

    void sendPacket(Packet *packet);

    bool hasPacket();

    Packet *getPacket();

    UDPAddress getAddress();

private:
    unsigned short sessionID;
    bool connected;
    UDPAddress remoteAddress;
    std::queue<Packet *> packetQueue;
    UDPSocket *socket;
};


#endif //NETWORKING_TUTORIALS_CONNECTION_H
