//
// Created by jonathan on 15/06/19.
//

#ifndef MYIDE_METADATAHANDLER_H
#define MYIDE_METADATAHANDLER_H

#include <iostream>
#include <stdio.h>
#include <sys/stat.h>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/Socket.hpp>
#include <fstream>
#include <dirent.h>
#include "Singleton.h"
class MetaDataHandler {
public:
    static void sendSelectData(std::string select,std::string from,std::string where);
    static void sendUpdateData(std::string update,std::string set,std::string where);
    static void sendInsertData(std::string insert,std::string values);
    static void sendDeleteData(std::string dele, std::string where);
    static void sendImageData(std::string name,std::string author,std::string year,std::string size,std::string description);
};


#endif //MYIDE_METADATAHANDLER_H
