cmake_minimum_required(VERSION 3.6)
project(Networking_Tutorials)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lws2_32 -std=gnu++11")

link_libraries(ws2_32 wsock32)

set(SOURCE_FILES main.cpp UDPAddress.cpp UDPAddress.h UDPSocket.cpp UDPSocket.h Connection.cpp Connection.h BitPacker.cpp BitPacker.h Packet.cpp Packet.h Server.cpp Server.h)
add_executable(Networking_Tutorials ${SOURCE_FILES})