//
// Created by Matt on 10/09/2016.
//

#include "UDPSession.h"

UDPSession::UDPSession(UDPSocket *socket, UDPAddress *remoteAddress) :
                                                                            socket(socket),
                                                                            remoteAddress(remoteAddress) {}

int UDPSession::connect() {
    unsigned short timeout = 10; //Seconds before aborting
    while(!connected) {
        //Connect
    }
}

char* UDPSession::encode(char *message) {
    char* output = strcat(message, message);
    free(message);
    return output;
}

bool UDPSession::isConnected() {
    return connected;
}