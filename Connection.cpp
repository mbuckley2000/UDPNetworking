//
// Created by Matt on 10/09/2016.
//

#include "Connection.h"

Connection::Connection(UDPSocket *socket) :
        socket(socket) {}

int Connection::connect() {
    unsigned short timeout = 10; //Seconds before aborting
    while(!connected) {
        //Connect
    }
}

int Connection::accept() {
    if (socket->isOpen()) {
        if (socket->receive()) {

        }
    }
}

char *Connection::encode(char *message) {
    char* output = strcat(message, message);
    free(message);
    return output;
}

bool Connection::isConnected() {
    return connected;
}