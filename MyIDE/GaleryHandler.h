//
// Created by jonathan on 06/06/19.
//

#ifndef MYIDE_GALERYHANDLER_H
#define MYIDE_GALERYHANDLER_H
#include <iostream>
#include <stdio.h>
#include <sys/stat.h>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/Socket.hpp>
#include <fstream>
#include <dirent.h>
#include "Singleton.h"
class GaleryHandler {
public:
    static  int createPrincipalGalery();
    static int createGalery(std::string pathFile);
};


#endif //MYIDE_GALERYHANDLER_H
