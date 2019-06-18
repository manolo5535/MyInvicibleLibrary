//
// Created by manolo on 17/06/19.
//

#ifndef HUFFMAN_PARSE_H
#define HUFFMAN_PARSE_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <SFML/Network.hpp>
#include <iostream>
#include <fstream>


using namespace std;

/**
 * obtiene la informacin del Json para la instancia
 * @param json referencia de la direccion del json
 * @param ip referencia de la ip
 */
void parse(std::string json, sf::IpAddress *ip, int *port)
{
    boost::property_tree::ptree pt2;

    boost::property_tree::read_json("../"+json,pt2);

    *ip = pt2.get<std::string>("ip");
    *port=atoi(pt2.get<std::string>("port").c_str());

}



#endif //HUFFMAN_PARSE_H
