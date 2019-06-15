//
// Created by gacova on 22/05/19.
//

#ifndef DISK_SINGLETON_H
#define DISK_SINGLETON_H

#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/Packet.hpp>

#include "DataBaseHandler.h"
#include <sys/stat.h>

class Singleton {
public:
    static std::string data;
    /**
     * obtiene la instancia del singleton
     */
    static Singleton* getInstance();

    /**
     * obtiene la direccion del server
     */
    static sf::TcpSocket* getServer();

    /**
     * obtiene el directorio de los discos
     */

    static std::string getDirectory();


    /**
     * crear el directorio de discos
     * @param diskNum numerodeñ disco
     */
    static void createDiskDirectory(int diskNum);
    /**
     * crear los bloques de discos
     * @param path dirrecion para cerar los bloques
     */
    static void createDiskBlocks(std::string path);

private:
    /**
     *
     */
    Singleton();
    /**
     * intancia del singleton
     */
    static Singleton* instance;
    /**
     * la direccion del servidor
     */
    static sf::TcpSocket* server;
    /**
     * el direcctorio donse crea el disco
     */
    static std::string directory;
};


#endif //DISK_SINGLETON_H
