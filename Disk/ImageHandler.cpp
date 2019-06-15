//
// Created by gacova on 22/05/19.
//
#include <cstring>
#include "ImageHandler.h"


int ImageHandler::fileSize(const std::string filename) {
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    int size = in.tellg();
    return size;
}


bool ImageHandler::emptyFolder(std::string dirname) {
    DIR * dir;
    struct dirent * element;
    bool empty;
    int number = 0;
    if(dir = opendir(dirname.c_str()))
    {
        while(element = readdir((dir)))
        {
            if(++number > 2)
                break;
        }
    }
    closedir(dir);
    if(number <=2)
        empty = true;
    else
        empty = false;

    return empty;
}


std::string ImageHandler::freeBlock(std::string path) {
    std::string route;
    bool free = false;
    int number = 1;
    while(!free)
    {
        route = path + std::to_string(number);
        if(emptyFolder(route) == true)
            free = true;
        else
            number++;
    }
    return route;
}


LinkedList<std::vector<byte>> ImageHandler::splitFile(std::vector<byte> vector) {
    float fnumParts = (float)vector.size() / (float)10000000;
    int numParts = fnumParts;
    if(fnumParts > numParts)
        numParts += 1;
    int partSize = 10000000;
    int start = 0, end = partSize;
    LinkedList<std::vector<byte>> parts = LinkedList<std::vector<byte>>();

    for (int i = 0; i < numParts; ++i) {
        if(i == (numParts - 1))
            end = vector.size();

        std::vector<byte> sub(&vector[start], &vector[end]);
        parts.insertAtEnd(sub);

        start = end;
        end += partSize;
    }
    return parts;
}


void ImageHandler::savePart(std::string part, std::string fileName) {

    std::string path = Singleton::getDirectory() + "/Block";
    std::vector<byte> vector(part.begin(), part.end());

    LinkedList<std::vector<byte>> parts = splitFile(vector);
    Singleton::getInstance()->data += fileName + ";";
    for (int i = 0; i < parts.getSize(); i++) {
        std::vector<byte> vector = parts.getElement(i)->getData();
        std::string part(vector.begin(), vector.end());
        std::string block = freeBlock(path);
        Singleton::getInstance()->data += block + ";";
        std::ofstream file;
        file.open(block + "/" + fileName + ".bin", std::ios::out | std::ios::binary);
        file.write((const char *) &vector[0], vector.size());
        file.close();
    }

    Singleton::getInstance()->data += "*";
    std::cout << fileName << " saved" << std::endl;
}


std::string ImageHandler::getPart(std::string fileName) {
    LinkedList<std::string> elements = splitString(Singleton::data, "*");
    std::string videoData;

    for (int i = 0; i < elements.getSize(); ++i) {
        LinkedList<std::string> data =  splitString(elements.getElement(i)->getData(), ";");
        if(strcmp(data.getElement(0)->getData().c_str(), fileName.c_str()) == 0){
            videoData = elements.getElement(i)->getData();
            i = elements.getSize();
        }
    }

    std::string part = "";
    LinkedList<std::string> data =  splitString(videoData, ";");
    for (int j = 1; j < data.getSize(); ++j) {
        std::string path = data.getElement(j)->getData();
        std::ifstream file1(path + "/" + fileName + ".bin", std::ios::binary);
        std::vector<byte> vector((std::istreambuf_iterator<char>(file1)), std::istreambuf_iterator<char>());

        if(!file1.is_open()){
            std::cout << "Couldn't open the file " << fileName << ".bin" << std::endl;
        }

        file1.close();

        part += std::string(vector.begin(), vector.end());
    }

    return part;
}


LinkedList<std::string> ImageHandler::splitString(std::string string, char *splitCharacter) {
    LinkedList<std::string> list = LinkedList<std::string>(); //Lista en la que se guardan los elementos
    char* messageChar = strdup(string.c_str()); //Se transforma el mensaje a char*
    char* element = strtok(messageChar, splitCharacter); //Separa el char cuando lea el splitCharacter
    while (element != NULL) {
        std::string str(element);
        list.insertAtEnd(str); // Se guarda el dato en la lista
        element = strtok (NULL, splitCharacter);  // Separa el resto de la cadena cuando lea la coma
    }

    return list;
}
