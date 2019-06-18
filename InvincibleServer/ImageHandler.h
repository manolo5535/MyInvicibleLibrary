#ifndef INVINCIBLESERVER_IMAGEHANDLER_H
#define INVINCIBLESERVER_IMAGEHANDLER_H

#include <iostream>
#include <SFML/Network.hpp>
#include <cstring>
#include <fstream>
#include "Singleton.h"

typedef unsigned char byte;

class ImageHandler {

public:
    /**
     * @brief Recibe la Imagen
     * @param sf::TcpSocket* client
     * @return std::vector<byte>
     */
    static std::vector<byte> receiveImage(sf::TcpSocket *client);

    /**
     * @brief Divide el vector en tres partes
     * @param std::vector<bytes>
     * @return LinkedList<std::vector<byte>>
     */
    static LinkedList<std::vector<byte>> splitImage(std::vector<byte> vector);

    /**
     * @brief Une las partes de la imagen
     * @param std::string part1 de la imagen
     * @param std::string  part2 de la imagen
     * @param std::string  part3de la imagen
     * @return std::string
     */
    static std::string joinImage(std::string part1, std::string part2, std::string part3);

};


#endif //INVINCIBLESERVER_IMAGEHANDLER_H
