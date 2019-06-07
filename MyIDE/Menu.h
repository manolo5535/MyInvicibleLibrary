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
    void itemsDelete();
    void itemsInsert();
    void itemsUpdate();
    void itemsSave();
    void itemsSaveGalery();
    void menuMetadata();
    void setDisplay(std::string string);
    std::string display = "";
    int GetPressdItem() {return  selectedItemIndex;}
    void search();
    void saveImagen();
    void saveGalery();
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
