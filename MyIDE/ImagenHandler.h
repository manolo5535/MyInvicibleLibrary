//
// Created by arturocv on 14/11/17.
//

#ifndef TECFS_TEST_VIDEOHANDLER_H
#define TECFS_TEST_VIDEOHANDLER_H

#include <iostream>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/Socket.hpp>
#include <fstream>
#include <dirent.h>
#include "Singleton.h"

typedef unsigned char byte;

class ImagenHandler {
public:
    static int sendImagen(std::string pathFile);

    static int sendDirectory(std::string pathDirectory);

    static std::string getImagen(std::string fileName);
};


#endif //TECFS_TEST_VIDEOHANDLER_H
