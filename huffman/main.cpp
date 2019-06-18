#include <iostream>
#include <cstring>
#include "Huffman.h"
#include "MetaHandler.h"
#include "Singleton.h"

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>


·

int main() {
/**

    boost::property_tree::ptree pt2;
    pt2.put("no","perro.jpg");
    pt2.put("an","2015");
    pt2.put("au","gacova");
    pt2.put("ta","2");
    pt2.put("de","un perro dalmata");


    std::ostringstream buf;
    write_json (buf, pt2, false);
    std::string json = buf.str();
    json.erase( std::remove(json.begin(), json.end(), '\n'), json.end() );
    std::cout <<  json << std::endl;

    Huffman h;
    h.comprimir(json);
    //genera el archivo con la compresion ya hecha
    std::string archComp=h.generarArchivo();

    std::cout <<  archComp << std::endl;
    //genera el string con la descompresion ya hecha
    std::cout <<  h.descomprimir(archComp) << std::endl;





    MetaHandler MDB;
    MDB.writeIO("Writing this to a file.\n");
    MDB.closeIO();
    cout << MDB.readIO();
*/

    sf::TcpSocket* server = Singleton::getServer();
    while(true){
        sf::Packet receivePacket;
        if(server->receive(receivePacket)==sf::Socket::Done){
            //Waits for information
            std::string act;
            receivePacket >> act;
            char* action = (char*) act.c_str();

            if(strcmp(action,"metadata")){
                std::string action2;
                receivePacket >> action2;
                std::string content;
                receivePacket >> content;

                //Se solicita la creacion de la tabla
                if(strcmp(action2.c_str(), "save") == 0){
                    MetaHandler::writeIO(content);

                    //Se solicita la informacion almacenada en el disco
                } else if(strcmp(action2.c_str(), "get") == 0){
                    std::string data = MetaHandler::searchIO(content);
                    sf::Packet packet;
                    packet << data;
                    server->send(packet);
                }

            }
        }
    }


    return 0;
}