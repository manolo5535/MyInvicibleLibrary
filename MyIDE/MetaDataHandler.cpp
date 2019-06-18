//
// Created by jonathan on 15/06/19.
//

#include "MetaDataHandler.h"
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace std;
void MetaDataHandler::sendSelectData(std::string select, std::string from, std::string where) {

    sf::Packet actionPacket;
    actionPacket << "Select";
    actionPacket << select;
    Singleton::getServer()->send(actionPacket);


    sf::Packet actionPacket1;
    actionPacket1 << "SelectFrom";
    actionPacket1 << from;
    Singleton::getServer()->send(actionPacket1);


    sf::Packet actionPacket2;
    actionPacket1 << "SelectWhere";
    actionPacket2 << where;
    Singleton::getServer()->send(actionPacket2);


}

void MetaDataHandler::sendInsertData(std::string insert, std::string values) {
    sf::Packet actionPacket;
    actionPacket << "Insert";
    actionPacket << insert;
    Singleton::getServer()->send(actionPacket);
    cout<<insert<<endl;

    sf::Packet actionPacket1;
    actionPacket1 << "InsertValues";
    actionPacket1 << values;
    Singleton::getServer()->send(actionPacket1);
    cout<<values<<endl;
}

void MetaDataHandler::sendDeleteData(std::string del, std::string where) {
    sf::Packet actionPacket;
    actionPacket << "Delete";
    actionPacket << del;
    Singleton::getServer()->send(actionPacket);
    cout<<del<<endl;

    sf::Packet actionPacket1;
    actionPacket1 << "DeleteWhere";
    actionPacket1 << where;
    Singleton::getServer()->send(actionPacket1);
    cout<<where<<endl;
}

void MetaDataHandler::sendUpdateData(std::string update, std::string set, std::string where) {

    sf::Packet actionPacket;
    actionPacket << "Update";
    actionPacket << update;
    Singleton::getServer()->send(actionPacket);


    sf::Packet actionPacket1;
    actionPacket1 << "UpdateSet";
    actionPacket1 << set;
    Singleton::getServer()->send(actionPacket1);


    sf::Packet actionPacket2;
    actionPacket1 << "UpdateWhere";
    actionPacket2 << where;
    Singleton::getServer()->send(actionPacket2);


}

void MetaDataHandler::sendImageData(std::string name, std::string author, std::string year, std::string size,std::string description,std::string galery) {

    boost::property_tree::ptree pt2;
    pt2.put("ImageName",name);
    pt2.put("ImageAutho",author);
    pt2.put("ImagenYear",year;
    pt2.put("ImageSize",size);
    pt2.put("ImageDescription",description);
    pt2.put("ImageGalery",galery);

    sf::Packet actionPacket;
    actionPacket << pt2;
    Singleton::getServer()->send(actionPacket);

}
