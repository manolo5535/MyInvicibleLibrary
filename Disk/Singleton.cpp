//
// Created by gacova on 22/05/19.
//

#include "Singleton.h"
#include "Parse.h"

Singleton* Singleton::instance = nullptr;
sf::TcpSocket* Singleton::server = nullptr;
std::string Singleton::directory = "disk";
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
        std::string PATH;
        parse(Json,&IP,&PORT,&PATH);
        directory = PATH;
        server->connect(IP,PORT);

        //Se le indica al servidor que se trata de un disco
        sf::Packet data;
        data << "Disk";
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

std::string Singleton::getDirectory() {
    return directory;
}


void Singleton::createDiskDirectory(int diskNum) {
    if(instance == nullptr){
        getInstance();
    }
    Singleton::directory += std::to_string(diskNum);
    mkdir(directory.c_str(),0777);
}


void Singleton::createDiskBlocks(std::string route) {
    std::string block = route + "/Block";
    for(int i = 1; i <= 30 ; i++) {
        std::string number = std::to_string(i);
        route = block;
        route = route + number;
        //std::cout << route << std::endl;
        if(mkdir(route.c_str(), 0777) == -1)
        {
            mkdir(route.c_str(),0777);
        }
    }

}


