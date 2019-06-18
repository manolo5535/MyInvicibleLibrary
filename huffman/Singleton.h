//
// Created by manolo on 17/06/19.
//

#ifndef HUFFMAN_SINGLETON_H
#define HUFFMAN_SINGLETON_H

#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/Packet.hpp>
#include <sys/stat.h>

class Singleton {
public:
    static std::string data;
    /**
     * obtiene la instancia del singleton
     */
    static Singleton* getInstance();

    /**
     * obtiene la direccion del server
     */
    static sf::TcpSocket* getServer();
    /**
     *
     */
    Singleton();
    /**
     * intancia del singleton
     */
    static Singleton* instance;
    /**
     * la direccion del servidor
     */
    static sf::TcpSocket* server;

};


#endif //HUFFMAN_SINGLETON_H
