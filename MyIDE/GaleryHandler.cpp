//
// Created by jonathan on 06/06/19.
//

#include "GaleryHandler.h"

int GaleryHandler::createPrincipalGalery()  {

    int carpeta = mkdir("/home/manolo/Documentos/carpeta",0777);
    if (carpeta == 0){
        return 1;

    }else{
        return 0;
    }

}

int GaleryHandler::createGalery(std::string pathFile){
    // se hace un solo string de path
    std::string path = "/home/manolo/Documentos/carpeta"+pathFile;
    // se le indica al servidor que tiene que guardar una galeria
    sf::Packet actionPacket;
    actionPacket << "saveGalery";
    actionPacket << pathFile;
    Singleton::getServer()->send(actionPacket);


    char directory[path.size()+1];
    path.copy(directory,path.size()+1);
    directory[path.size()] = '\0';
    int carpeta = mkdir(directory,0777);
    if(carpeta == 0){
        return 1;
    }else{
        return 0;
    }


}
std::string GaleryHandler::getGalery(std::string imagenName) {
    sf::Packet actionPacket;
    actionPacket << "getGalery";
    actionPacket << imagenName;
    Singleton::getServer()->send(actionPacket);

    sf::Packet receivePacket;
    std::string receiveMessage;

    if (Singleton::getServer()->receive(receivePacket) == sf::Socket::Done) {
        receivePacket >> receiveMessage;
    }
    return receiveMessage;
}

