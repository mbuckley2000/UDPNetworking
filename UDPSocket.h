//
// Created by Matt on 10/09/2016.
//

#ifndef NETWORKING_TUTORIALS_UDPSOCKET_H
#define NETWORKING_TUTORIALS_UDPSOCKET_H

#include "UDPAddress.h"

class UDPSocket
{
public:
    UDPSocket();

    ~UDPSocket();
    bool open(unsigned short port);
    void close();
    bool isOpen() const;

    bool send(UDPAddress *destination,
              const void *data,
              int size);
    int receive();
    char* getReceivedData();
    bool initialiseSockets();

    int getReceivedDataSize() const;
    void shutDownSockets();
    UDPAddress* getLastSender();


private:
    unsigned int handle;
    bool opened;
    char* recvBuffer;
    int receivedDataSize;
    UDPAddress *lastSender;
};

#endif //NETWORKING_TUTORIALS_UDPSOCKET_H
