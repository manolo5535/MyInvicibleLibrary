//
// Created by manolo on 17/06/19.
//

#ifndef HUFFMAN_METAHANDLER_H
#define HUFFMAN_METAHANDLER_H

#include "Huffman.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class MetaHandler {
public:
    string path = "/home/manolo/CLionProjects/huffman/NoSQL.txt";
    Huffman* hf = new Huffman();
    fstream myfile;
    void writeIO(string text);
    string readIO();
    std::string searchIO(string text);
    void closeIO();

};


#endif //HUFFMAN_METAHANDLER_H
