//
// Created by gacova on 22/05/19.
//

#ifndef DISK_PARSE_H
#define DISK_PARSE_H

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
 * @param path referencia de la dirrecion del directorio de las carpetas
 */
void parse(std::string json, sf::IpAddress *ip, int *port, std::string *path)
{
    boost::property_tree::ptree pt2;

    boost::property_tree::read_json("../"+json,pt2);

    *ip = pt2.get<std::string>("ip");
    *port=atoi(pt2.get<std::string>("port").c_str());
    *path =pt2.get<std::string>("path");
}

#endif //DISK_PARSE_H
