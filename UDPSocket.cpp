//
// Created by Matt on 10/09/2016.
//

#include <iostream>
#include "UDPSocket.h"

bool UDPSocket::initialiseSockets() {
#if PLATFORM == PLATFORM_WINDOWS
    WSADATA WSAData;
    return WSAStartup(MAKEWORD(2, 2), &WSAData) == NO_ERROR;
#else
    return true;
#endif
}

void UDPSocket::shutDownSockets() {
#if PLATFORM == PLATFORM_WINDOWS
    WSACleanup();
#endif
}

UDPSocket::UDPSocket() {}

UDPSocket::~UDPSocket() {
    UDPSocket::close();
}

bool UDPSocket::open(unsigned short port) {
    bool error = false;

    //open Socket
    handle = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (handle <= 0) {
        std::cerr << "Failed to create socket" << std::endl;
        error = true;
    }

    //Set address + port
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons((unsigned short) port);

    //Bind socket
    if (bind(handle, (const sockaddr*) &address, sizeof(sockaddr_in)) < 0) {
        std::cerr << "Failed to bind socket" << std::endl;
        error = true;
    }

    //Set socket to non-blocking
    #if PLATFORM == PLATFORM_WINDOWS
        DWORD nonBlocking = 1;
        if (ioctlsocket(handle, FIONBIO, &nonBlocking) != 0) {
            std::cerr << "Failed to set socket to non-blocking mode" << std::endl;
            error = true;
        }
    #else //Mac or UNIX
        int nonBlocking = 1;
            if (fcntl(handle, F_SETFL, O_NONBLOCK, nonBlocking) == -1) {
                std::cerr << "Failed to set socket to non-blocking mode" << std::endl;
                error = true;
            }
    #endif

    opened = !error;
}

void UDPSocket::close() {
    #if PLATFORM == PLATFORM_MAC || PLATFORM == PLATFORM_UNIX
        close( socket );
    #elif PLATFORM == PLATFORM_WINDOWS
        closesocket(handle);
    #endif
}

bool UDPSocket::isOpen() const {
    return opened;
}

bool UDPSocket::send(UDPAddress destination, const void *data, int size) {
    int sentBytes = sendto(handle, (const char *) data, size, 0, (sockaddr *) destination.getIntegerIP(),
                           sizeof(sockaddr_in));
    return sentBytes == size;
}

int UDPSocket::receive() {
    //Clear and reallocate buffer
    if (recvBuffer != nullptr) {
        free(recvBuffer);
    }
    recvBuffer = (char*)calloc(sizeof(char), 50);

    int received = 0;

    while ( true )
    {
        #if PLATFORM == PLATFORM_WINDOWS
                typedef int socklen_t;
        #endif

        sockaddr_in sender;
        socklen_t fromLength = sizeof(sender); //lastSender

        int bytes = recvfrom(handle,
                              recvBuffer,
                              sizeof(char)*50,
                              0,
                              (sockaddr*)&sender,
                              &fromLength);

        if ( bytes <= 0 ) {
            break;
        } else {
            received = 1;
        }

        receivedDataSize = bytes;

        unsigned int from_address = ntohl(sender.sin_addr.s_addr);

        unsigned short from_port = ntohs(sender.sin_port);

        std::cout << "Size: " << bytes << std::endl;
        std::cout << "Data: " << recvBuffer << std::endl;
        std::cout << "From address: " << from_address << ":" << from_port << std::endl;

        std::cout << "Converting to human form" << std::endl;
        lastSender = UDPAddress(from_address, from_port);
    }
    return received;
}

char *UDPSocket::getReceivedData() {
    return recvBuffer;
}

UDPAddress UDPSocket::getLastSender() {
    return lastSender;
}

int UDPSocket::getReceivedDataSize() const {
    return receivedDataSize;
}
