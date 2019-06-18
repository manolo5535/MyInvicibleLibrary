#ifndef INVINCIBLESERVER_DATABASE_H
#define INVINCIBLESERVER_DATABASE_H

#include <iostream>
#include <fstream>
#include <SFML/Network/Packet.hpp>
#include "Singleton.h"
#include "FaultTolerance.h"

class DataBase {

private:
    /**
     * @brief Almacena la tabla en los discos
     * @param string content
     * @param string action
     */
    static void send(std::string content, std::string action);

public:
    /**
     * @brief Crea una tabla para gurdar los datos de las imagenes
     */
    static void createTable();

    /**
     * @brief  agrega un nuevo elemento a la tabla
     * @param std::string content
     */
    static void addToTable(std::string content);

    /**
     * @brief Obtiene las partes de la tabla almacenada en los discos y reconstruir la tabla
     * @return std::string
     */
    static std::string getTable();

    /**
     * @brief Divide un string en elementos segun un caracter especificado
     * @param std::string
     * @param splitCharacter
     * @return LinkedList<std::string>
     */
    static LinkedList<std::string> splitString(std::string string, char *splitCharacter);

    /**
     * @brief Obtiene la informacion de la imagen almacenada
     * @param name Nombre de la imagen
     * @return LinkedList<std::string>
     */
    static LinkedList<std::string> getImageData(std::string name);

    /**
     * @brief Obtener una parte de la imagen almacenada en el disco
     * @param disk Numero del disco que se esta consultando
     * @return std::string
     */
    static std::string getPart(int disk);

};


#endif //INVINCIBLESERVER_DATABASE_H
