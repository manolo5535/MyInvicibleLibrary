//
// Created by jonathan on 22/05/19.
//

#ifndef MYIDE_MENU_H
#define MYIDE_MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Network/Packet.hpp>
#include <dirent.h>
#include <cstring>
#include "DataStructures/LinkedList.h"
#include "Singleton.h"
#include "ImagenHandler.h"
#include "GaleryHandler.h"
#include "MetaDataHandler.h"
#include "Image.h"
#define NumberOfItems 11


class Menu {

public:
    Menu(float width, float heigth);
    int typeOfWindow;
    ~Menu();
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();

    void itemsMenu();
    void itemsMenuSave();
    void itemsSearchImagen();

    void itemsSelect();
    void itemsSelectFrom();
    void itemsSelectWhere();
    void sendMetaDataSelect();

    void crearCarpetaPrincipal();
    void crearCarpeta();

    void itemsDelete();
    void itemsDeleteWhere();
    void sendMetaDataDelete();

    void itemsInsert();
    void itemsInsertValue();
    void sendMetaDataInsert();

    void itemsUpdate();
    void itemsUpdateSet();
    void itemsUpdateWhere();
    void sendMetaDataUpdate();

    void itemsSave();
    void itemsSaveGalery();
    void menuMetadata();
    void setDisplay(std::string string);
    void setDisplay1(std::string inputText);
    void setDisplay2(std::string inputText);
    void setDisplay3(std::string inputText);
    void setDisplay4(std::string inputText);
    void setDisplay5(std::string inputText);
    void setDisplay6(std::string inputText);

    std::string display = "";
    std::string display1 = "";
    std::string display2 = "";
    std::string display3 = "";
    std::string display4 = "";
    std::string display5 = "";
    std::string display6 = "";
    int GetPressdItem() {return  selectedItemIndex;}
    void search();

    int saveImagen();
    void imagenName();
    void imagenYear();
    void imagenAuthor();
    void imagenSize();
    void imagenDescription();
    void imagenGalery();

    void imagen(int i);

    void saveGalery();
    void sendMetaDataImage();

    static void run();

private:
    float width;
    float height;
    sf::Font font;

    int selectedItemIndex;
    sf::Text menu[NumberOfItems];
    LinkedList<std::string> names;
    void clearItems();
    void getTable();
    LinkedList<std::string> coincidence();
};


#endif //MYIDE_MENU_H
