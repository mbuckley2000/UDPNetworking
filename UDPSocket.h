//
// Created by Matt on 10/09/2016.
//

#ifndef NETWORKING_TUTORIALS_UDPSOCKET_H
#define NETWORKING_TUTORIALS_UDPSOCKET_H

#include "UDPAddress.h"

class UDPSocket
{
public:
    UDPSocket(UDPAddress lastSender);

    ~UDPSocket();
    bool open(unsigned short port);
    void close();
    bool isOpen() const;
    bool send(UDPAddress &destination,
              const void *data,
              int size);
    int receive();
    char* getReceivedData();
    bool initialiseSockets();
    void shutDownSockets();
    UDPAddress* getLastSender();


private:
    unsigned int handle;
    bool opened;
    char* recvBuffer;
    UDPAddress lastSender;
};

#endif //NETWORKING_TUTORIALS_UDPSOCKET_H
