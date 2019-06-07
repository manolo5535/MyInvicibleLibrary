//
// Created by arturocv on 14/11/17.
//

#include "ImagenHandler.h"

/// Metodo para enviar una imagen al servidor
/// \param pathFile Ruta de la imagen
/// \return 0 si se realizo con exito, -1 si hubo un error
int ImagenHandler::sendImagen(std::string pathFile) {
    std::ifstream file(pathFile, std::ios::binary);

    //Se verifica que la imagen haya sido cargado de manera existosa
    if(!file.is_open()){
        std::cout << "Couldn't open the file" << std::endl;
        return -1;

    } else {
        //Se obtiene el nombre del video del path ingresado
        LinkedList<std::string> list = Singleton::splitString(pathFile, "/");
        std::string imagenName = list.getElement(list.getSize() -1)->getData();

        //Se le indica al servidor que se quiere almacenar una imagen
        sf::Packet actionPacket;
        actionPacket << "saveImagen";
        actionPacket << imagenName;
        Singleton::getServer()->send(actionPacket);

        //Se convierte la imagen a un string de <uchar>
        std::vector<byte> vector((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        std::string vectorString(vector.begin(), vector.end());
        file.close();

        //Se envia la imagen
        sf::Packet imagenPacket;
        imagenPacket << vectorString;
        Singleton::getServer()->send(imagenPacket);

        return 0;
    }
}

/// Metodo para obtener un video del servidor
/// \param fileName Nombre del video que se quiere obtener
std::string ImagenHandler::getImagen(std::string fileName){
    //Se envia al servidor la accion que se quiere realizar
    sf::Packet packet;
    packet << "getImagen";
    packet << fileName;
    Singleton::getServer()->send(packet);

    //Se espera a recibir la respuesta del servidor
    sf::Packet receivePacket;
    std::string receiveMessage;

    if (Singleton::getServer()->receive(receivePacket) == sf::Socket::Done) {
        receivePacket >> receiveMessage;
    }


    //Se guarda la imagen recibida
    std::string extension;
    receivePacket >> extension;

    std::vector<byte> vector(receiveMessage.begin(), receiveMessage.end());
    std::ofstream file;
    file.open("receive." + extension, std::ios::out | std::ios::binary);
    file.write((const char*) &vector[0], vector.size());
    file.close();

    return receiveMessage;
}

/// Metodo para enviar los archivos que se encuentren dentro de una carpeta
/// \param pathDirectory Path de la carpeta
/// \return 0 si no ocurrieron errores, -1 en caso contrario.
int ImagenHandler::sendDirectory(std::string pathDirectory) {
    DIR* dir;
    struct dirent *ent;
    //Se intenta abrir el directorio
    if((dir = opendir(pathDirectory.c_str())) != NULL){
        //Se lee cada archivo dentro del directorio
        while((ent = readdir(dir)) != NULL) {
            std::string fileName = ent->d_name;
            //Se verifica que sea un nombre de imagen valido
            if (fileName.size() > 4 && Singleton::splitString(fileName, ".").getSize() == 2) {
                sendImagen(pathDirectory + "/" + fileName);
            }
        }
        closedir(dir);
        return 0;

    } else{
        return -1;
    }
}
