#include "ImageHandler.h"

std::vector<byte> ImageHandler::receiveImage(sf::TcpSocket *client) {
    std::vector<byte> vector;

    //Se espera el mensaje con la imagen enviada por el cliente
    sf::Packet receivePacket;
    std::string receiveString;

    //Se recibe un packet con un string de la imagen
    if (client->receive(receivePacket) == sf::Socket::Done) {
        receivePacket >> receiveString;
        vector = std::vector<byte>(receiveString.begin(), receiveString.end());
    }

    return vector;
}

LinkedList<std::vector<byte>> ImageHandler::splitImage(std::vector<byte> vector) {
    int partSize = vector.size() / 3;

    LinkedList<std::vector<byte>> parts = LinkedList<std::vector<byte>>();

    int start = 0, end = partSize;

    //Se divide la imagen en partes iguales
    for (int i = 0; i < 3; ++i) {
        if(i == 2)
            end = vector.size();

        std::vector<byte> sub(&vector[start], &vector[end]);
        parts.insertAtEnd(sub);

        start = end;
        end += partSize;
    }

    return parts;
}

std::string ImageHandler::joinImage(std::string part1, std::string part2, std::string part3) {
    //Se transforman los strings a vectores
    std::vector<byte> vector1(part1.begin(), part1.end());
    std::vector<byte> vector2(part2.begin(), part2.end());
    std::vector<byte> vector3(part3.begin(), part3.end());

    //Se funcionan los tres vectores en uno solo
    vector1.insert(vector1.end(), vector2.begin(), vector2.end());
    vector1.insert(vector1.end(), vector3.begin(), vector3.end());

    //Se transforma el vector de la imagen de nuevo en un string
    std::string imagen = std::string(vector1.begin(), vector1.end());
    return imagen;
}
