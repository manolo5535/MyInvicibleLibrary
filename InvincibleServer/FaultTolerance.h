#ifndef INVINCIBLESERVER_FAULTTOLERANCE_H
#define INVINCIBLESERVER_FAULTTOLERANCE_H

#include <iostream>
#include <fstream>
#include <vector>

typedef unsigned char byte;

class FaultTolerance {

public:
    /**
     * @brief Metodo para calcular la paridad de un archivo utilizando el XOR
     * @param part1 Primera parte del archivo
     * @param part2 Segunda parte del archivo
     * @param part3 Tercera parte del archivo
     * @return std::vector Vector con el resultado de las operacion XOR a las tres partes
     */
    static std::vector<byte> calculateParity(std::vector<byte> part1, std::vector<byte> part2, std::vector<byte> part3);

    /**
     * @brief Metodo que utiliza la paridad para recuperar una parte perdida del archivo
     * @param partAString Parte del archivo
     * @param partBString Parte del archivo
     * @param parityString Paridad del archivo
     * @return std::vector La parte faltante del archivo
     */
    static std::string recoverData(std::string partAString, std::string partBString, std::string parityString);

};


#endif //INVINCIBLESERVER_FAULTTOLERANCE_H
