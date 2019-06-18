//
// Created by raxzers on 6/16/18.
//

#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H


#include <iostream>
#include <map>
#include <bitset>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
class Huffman {
public:
    /**
     *
     * @param s tira de carateres por comprimir
     */
    void comprimir(std::string s);
    std::string comprimido;
    /**
     * crea el JSON con la info comprimida
     */
    std::string generarArchivo();
    /**
     * metodo principal para descomprimir el JSON serializado
     * @param serial JSON serializado
     */
    std::string descomprimir(std::string serial);
    /**
     * dicionario de caracteres y su codigo en el arbol, respectivamente
     */
    std::map <std::string,std::string > diccionario;





private:
    /**
     * estructura interna para crear el arbol para huffman
     */
    struct MinHeapNode{

        // One of the input characters
        std::string data;

        // Frequency of the character
        unsigned freq;

        // Left and right child
        MinHeapNode *left, *right;

        MinHeapNode(char data, unsigned freq)

        {

            left = right = nullptr;
            this->data = data;
            this->freq = freq;
        }
    };
    /**
     * este compara las frecuencia de los caracteres
     */
    struct compare{

        bool operator()(MinHeapNode* l, MinHeapNode* r)

        {
            return (l->freq > r->freq);
        }
    };
    /**
     *
     * @tparam T1 cualquier variable que soporte el std map
     * @tparam T2 cualquier variable que soporte el std map
     * @param m mapa el cual se quiere intercambiar
     * @return el mapa intercambiado
     */
    template <class T1, class T2>std::map<T2, T1> swapPairs(std::map<T1, T2> m);
    /**
    * @param arr lista de enteros para convertirse en el codificado
    * @param tan tamaño real del codificado
    * con la lista de ints se pega la lista para crear otra vez el mensaje
    * @return el archivo cortado en la seccion correcta
    */
    std::string  unirCompreso(int arr[16],int tan);
    /**
     * lista de enteros para intoducir la codificacion
     */
    int compEnt[16];
    /**
     * largo de la codificacion
     */
    int sizeComp;
    /**
     * este proceso es recursivo donde le da los codigos alos caracteresy los agrega al diccionario
     * @param root el arbol de hufman
     * @param str codigo del caracter
     */
    void printCodes(struct MinHeapNode* root, std::string str);
    /**
     * este con la tabla de frecuencias crea el arbol
     * @param refer tabla de frecuencias
     * @param tamaño del la tira de caracteres
     */
    void HuffmanCodes(std::map<char, int> refer, int size);
    /**
     * contador para la tabla de frecuencias
     * @param s tira de carateres
     */
    void counter(std::string s);
    /**
     * tabla de frecuencias
     */
    std::map <char, int> refer;
    /**
     *
     * @param arr lista de enteros para convertirse en el codificado
     * @param tan tamaño real del codificado
     * @param dicci diciionario entre los codigos y los varores
     * @return la informacion descomprimida
     */
    std::string descomprimir(int arr[16],int tan,std::map<std::string, std::string> dicci);
    /**
     * con la informacion copmrimida esta se divide en 16 partes de 32 bits y se meten un lista de ints
    */
    void  partirCompreso();
};


#endif //HUFFMAN_HUFFMAN_H
