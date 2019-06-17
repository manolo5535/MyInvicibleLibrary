#include <iostream>
#include <SFML/Graphics.hpp>
#include "Singleton.h"
#include "Menu.h"
#include "ImagenHandler.h"
#include "GaleryHandler.h"
int main()
{

    std::string ip;
    std::cout << "Ingrese la IP del servidor: ";
    std::cin >> ip;
    Singleton::connectToServer(ip,2001);
    Menu::run();
    return 0;
}