//
// Created by gacova on 22/05/19.
//

#include "DataBaseHandler.h"
#include <iostream>
#include "Singleton.h"


void DataBaseHandler::createFile(std::string content) {
    std::string fileName = Singleton::getDirectory() + "/metadata.bin";

    std::ofstream file(fileName, std::ios::out | std::ios::binary);
    file.write(content.c_str(), content.size());
    file.close();
}


std::string DataBaseHandler::getData() {
    std::string fileName = Singleton::getDirectory() + "/metadata.bin";

    std::ifstream file(fileName, std::ios::binary);
    std::string data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    return data;
}
