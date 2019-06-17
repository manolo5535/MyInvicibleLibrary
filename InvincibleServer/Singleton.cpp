#include "Singleton.h"

Singleton* Singleton::instance = nullptr;
LinkedList<sf::TcpSocket*>* Singleton::clients = nullptr;
LinkedList<sf::TcpSocket*>* Singleton::disks = nullptr;

Singleton::Singleton() {}

Singleton *Singleton::getInstance() {
    //Se crean las instancias si estas no existian previamente
    if(instance == nullptr){
        instance = new Singleton();
        clients = new LinkedList<sf::TcpSocket*>();
        disks = new LinkedList<sf::TcpSocket*>();
    }

    return instance;
}

LinkedList<sf::TcpSocket*> *Singleton::getClients() {
    if(instance == nullptr){
        getInstance();
    }

    return clients;
}

LinkedList<sf::TcpSocket*> *Singleton::getDisks() {
    if(instance == nullptr){
        getInstance();
    }

    return disks;
}