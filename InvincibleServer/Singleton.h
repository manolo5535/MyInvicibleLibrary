#ifndef INVINCIBLESERVER_SINGLETON_H
#define INVINCIBLESERVER_SINGLETON_H

#include <SFML/Network/TcpSocket.hpp>
#include "DataStructures/LinkedList.h"
#include "Controller.h"

class Singleton {

private:
    //Constructor
    Singleton();

    static Singleton* instance;

    static LinkedList<sf::TcpSocket*>* clients;

    static LinkedList<sf::TcpSocket*>* disks;

public:
    /**
     * @brief metodo para instanciar un objeto si este no existe, si
     * existe devolver el puntero al ya vreado
     * @return Singleton*
     */
    static Singleton* getInstance();

    static LinkedList<sf::TcpSocket*>* getClients();

    static LinkedList<sf::TcpSocket*>* getDisks();

};


#endif //INVINCIBLESERVER_SINGLETON_H
