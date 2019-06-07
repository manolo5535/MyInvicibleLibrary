//
// Created by jonathan on 22/05/19.
//

#ifndef MYIDE_SINGLETON_H
#define MYIDE_SINGLETON_H

#include <iostream>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/IpAddress.hpp>
#include "DataStructures/LinkedList.h"

class Singleton {
public:
    static Singleton* getInstance();

    static void connectToServer(std::string ip, int port);

    static sf::TcpSocket* getServer();

    static LinkedList <std::string> splitString(std::string string, char *splitCharacter);

private:
    static Singleton* instance;

    static sf::TcpSocket* server;
};


#endif //MYIDE_SINGLETON_H
