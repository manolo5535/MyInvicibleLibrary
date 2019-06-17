#ifndef INVINCIBLESERVER_DATABASE_H
#define INVINCIBLESERVER_DATABASE_H

#include <iostream>
#include <fstream>
#include <SFML/Network/Packet.hpp>
#include "Singleton.h"
#include "FaultTolerance.h"

class DataBase {

private:
    static void send(std::string content, std::string action);

public:
    static void createTable();

    static void addToTable(std::string content);

    static std::string getTable();

    static LinkedList<std::string> splitString(std::string string, char *splitCharacter);

    static LinkedList<std::string> getVideoData(std::string name);

    static std::string getPart(int disk);

};


#endif //INVINCIBLESERVER_DATABASE_H
