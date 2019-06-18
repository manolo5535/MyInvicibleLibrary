//
// Created by manolo on 17/06/19.
//

#include "Singleton.h"
#include "Parse.h"

Singleton* Singleton::instance = nullptr;
sf::TcpSocket* Singleton::server = nullptr;
std::string Singleton::data = "";

Singleton::Singleton() {

}


Singleton *Singleton::getInstance() {
    //Se crean las instancias si estan no existian previamente
    if(instance == nullptr){
        instance = new Singleton(); //Se crea la instancia de la clase
        server = new sf::TcpSocket(); //Se crea el servidor

        ///Lectura del JSON para obtener la ip del servidor
        std::string Json = "Data.json";
        sf::IpAddress IP;
        int PORT;
        parse(Json,&IP,&PORT);
        server->connect(IP,PORT);

        //Se le indica al servidor que se trata de un disco
        sf::Packet data;
        data << "MetaBD";
        server->send(data);
    }

    return instance;
}

sf::TcpSocket *Singleton::getServer() {
    if(instance == nullptr){
        getInstance();
    }

    return server;
}