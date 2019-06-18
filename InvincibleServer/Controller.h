#ifndef INVINCIBLESERVER_CONTROLLER_H
#define INVINCIBLESERVER_CONTROLLER_H

#include <iostream>
#include <vector>
#include <fstream>
#include "DataStructures/LinkedList.h"
#include "Singleton.h"
#include "FaultTolerance.h"
#include "DataBase.h"
#include "ImageHandler.h"

class Controller {

private:
    int parityDisc = 0;

    /**
     * @brief Metodo para obtener a que disco le corresponde la paridad
     * @return int Numero del disco
     */
    int getParityDisk();

    /**
     * @brief Obtiene la parte de la... imagen buscada en un disco especifico
     * @param name Nombre de la imagen
     * @param diskNum Numero del diaco a buscar
     * @return std::string Parte de la imagen que estaba en ese disco
     */
    std::string getPart(std::string name, int diskNum);

    /**
     * @brief Metodo para restaurar la data que se encontraba en un disco
     * @param diskNum posicion en la lista del disco que hay que restaurar
     */
    void restoreDisk(int diskNum);

public:
    /**
     * @brief Divide la imagen y lo envia a los discos
     * @param data vector con la imagen
     * @param filename nombr3 del archivo
     */
    void sendParts(std::vector<byte> data, std::string filename);

    /**
     * @brief Metodo para obtener las partes de la imagen almacenadas en los discos
     * @param name nombre de la imagen
     * @return std::string con la imagen
     */
    std::string getImage(std::string name);


    /**
     * @brief Annade un disco a la lista de discos
     * @param socket
     */
    void addDisk(sf::TcpSocket *socket);

};


#endif //INVINCIBLESERVER_CONTROLLER_H
