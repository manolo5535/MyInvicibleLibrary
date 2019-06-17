//
// Created by jonathan on 06/06/19.
//

#include "GaleryHandler.h"

int GaleryHandler::createPrincipalGalery()  {

    int carpeta = mkdir("/home/jonathan/Galeria Principal",0777);
    if (carpeta == 0){
        return 1;

    }else{
        return 0;
    }

}

int GaleryHandler::createGalery(std::string pathFile){
    // se hace un solo string de path
    std::string path = "/home/jonathan/Galeria Principal/"+pathFile;
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

