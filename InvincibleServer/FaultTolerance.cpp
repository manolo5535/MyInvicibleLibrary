#include "FaultTolerance.h"

std::vector<byte> FaultTolerance::calculateParity(std::vector<byte> part1, std::vector<byte> part2, std::vector<byte> part3) {
    std::vector<byte> vectorParity;

    //Por cada byte de las partes se aplica el XOR y se añade el resultado al vector de paridad
    for(int i = 0; i < part3.size(); i++) {
        vectorParity.push_back(part1[i] ^ part2[i] ^ part3[i]);
    }

    return vectorParity;
}

std::string FaultTolerance::recoverData(std::string partAString, std::string partBString, std::string parityString) {
    std::vector<byte> vectorFault;

    //Se transforman los strings a vectores
    std::vector<byte> partA(partAString.begin(), partAString.end());
    std::vector<byte> partB(partBString.begin(), partBString.end());
    std::vector<byte> parity(parityString.begin(), parityString.end());

    //Por cada byte del vector se utiliza el XOR para obtener la parte perdida
    for(int i = 0; i < parity.size(); i++) {
        vectorFault.push_back(partA[i] ^ partB[i] ^ parity[i]);
    }

    if(partA.size() != partB.size()) {
        for (int j = 0; j < (parity.size() - partA.size()); ++j) {
            vectorFault.erase(vectorFault.begin() + (vectorFault.size() - 1));
        }
    }

    //Se transforma el vector obtenido en un string
    std::string reconstructedPart(vectorFault.begin(), vectorFault.end());
    return reconstructedPart;
}