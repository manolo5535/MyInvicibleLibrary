//
// Created by gacova on 22/05/19.
//

#ifndef DISK_IMAGEHANDLER_H
#define DISK_IMAGEHANDLER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <dirent.h>

#include "Singleton.h"
#include "DataStructures/LinkedList.h"

typedef unsigned char byte;

class ImageHandler {
public:
    /// Metodo que verifica el peso del file
/// \param filename
/// \return
    static int fileSize(const std::string filename);

    /// Metodo que verifica si el directorio esta vacio
/// \param dirname
/// \return
    static bool emptyFolder(std::string dirname);

    /// Metodo para encontrar un bloque este disponible
/// \param path
/// \return ruta
    static std::string freeBlock(std::string path);

    /// Metodo para dividir un file
/// \param vector
/// \return parte del archivo
    static LinkedList<std::vector<byte>> splitFile(std::vector<byte> vector);


    /// Metodo para almacenar en memoria la parte del video recibida
/// \param part String con la parte de la imagen
/// \param fileName Nombre de la imagen
    static void savePart(std::string part, std::string fileName);

    /// Metodo para obtener la parte del video que se encuentra almacenada
/// \param fileName Nombre del fichero
/// \return Un string con la parte del video
    static std::string getPart(std::string fileName);

    /// Metodo para dividir un string en elementos
/// \param string String a separar
/// \param splitCharacter Caracter utilizado para separar los elementos
/// \return LinkedList con los elementos obtenidos de la separacion
    static LinkedList<std::string> splitString(std::string string, char *splitCharacter);
};


#endif //DISK_IMAGEHANDLER_H
