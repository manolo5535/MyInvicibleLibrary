//
// Created by manolo on 17/06/19.
//

#include "MetaHandler.h"

std::string MetaHandler::searchIO(std::string text) {
    myfile.open(path);
    bool isFound==0;
    while(!myfile.eof()){
        string temp = "";
        getline(myfile,temp);
        temp = hf->descomprimir(hf->generarArchivo());
        for(int i=0;i<text.size();i++)
        {
            if(temp[i]==search[i])
                isFound = 1;
            else
            {
                isFound =0;
                break;
            }
        }

        if(isFound)
        {
            return temp;
        }
    }
    return "";
}

void MetaHandler::writeIO(std::string text) {
    hf->comprimir(text);
    std::string txtComp = hf->comprimido;
    myfile.open(path, ios::app);
    myfile << txtComp+"\n";
}

std::string MetaHandler::readIO() {
    std::string temp = "";
    getline(myfile, temp);
    temp = hf->descomprimir(hf->generarArchivo());
    return temp;
}

void MetaHandler::closeIO() {
    myfile.close();
}
