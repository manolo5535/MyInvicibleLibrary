//
// Created by jonathan on 17/06/19.
//

#ifndef MYIDE_IMAGE_H
#define MYIDE_IMAGE_H
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cstdlib>

class Image {
public:
    static void createImage(std::string nombre,std::vector<char> buffer);
};


#endif //MYIDE_IMAGE_H
