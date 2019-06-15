//
// Created by gacova on 22/05/19.
//

#ifndef DISK_DATABASEHANDLER_H
#define DISK_DATABASEHANDLER_H

#include <SFML/Network/Socket.hpp>
#include <SFML/Network/Packet.hpp>
#include <fstream>
class DataBaseHandler {
public:
    /// Metodo para crear el fichero con la parte correspondiente de la base de datos
/// \param content String que hay que almacenar
    static void createFile(std::string content);

    /// Metodo para obtener la parte de la base de datos que almacenada en el disco
/// \return Un string con la parte de la base de datos
    static std::string getData();
};


#endif //DISK_DATABASEHANDLER_H
