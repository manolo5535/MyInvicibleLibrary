//
// Created by jonathan on 22/05/19.
//

#include "Menu.h"

Menu::Menu(float width, float heigth) {
    this->width = width;
    this->height = heigth;

    if (!font.loadFromFile("../CCR.ttf"))
    {
        // handle error
    }
    this->typeOfWindow = 0;

}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{

    for(int i = 0; i < NumberOfItems; i++)
    {
        window.draw(menu[i]);
    }
}


void Menu::MoveUp()
{
    if(typeOfWindow == 0) {

        if (selectedItemIndex - 1 >= 0) {
            menu[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex--;
            menu[selectedItemIndex].setColor(sf::Color::Red);
        }
    }

    if(typeOfWindow == 1){

        if (selectedItemIndex - 1 >= 0 && selectedItemIndex != 1) {
            menu[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex--;
            menu[selectedItemIndex].setColor(sf::Color::Red);
        }
        if (selectedItemIndex == 1){
            menu[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex = 0;
            menu[selectedItemIndex].setColor(sf::Color::Red);
        }
    }
    if(typeOfWindow == 2){

        if (selectedItemIndex == 10) {
            menu[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex = 0;
            menu[selectedItemIndex].setColor(sf::Color::Red);
        }
    }
    if(typeOfWindow == 4){

    }
    else if(typeOfWindow == 3) {

        if (selectedItemIndex - 1 >= 0) {
            menu[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex--;
            menu[selectedItemIndex].setColor(sf::Color::Red);
        }
    }
}

void Menu::MoveDown()
{
    if(typeOfWindow == 0) {

        if (selectedItemIndex + 1 < 3) {
            menu[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex++;
            menu[selectedItemIndex].setColor(sf::Color::Red);
        }
    }

    if(typeOfWindow == 1){
        if (selectedItemIndex + 1 < 11 && selectedItemIndex != 0) {
            menu[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex++;
            menu[selectedItemIndex].setColor(sf::Color::Red);
        }

        if (selectedItemIndex == 0){
            menu[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex = 2;
            menu[selectedItemIndex].setColor(sf::Color::Red);
        }

    }
    if(typeOfWindow == 3) {

        if (selectedItemIndex + 1 < 5) {
            menu[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex++;
            menu[selectedItemIndex].setColor(sf::Color::Red);
        }
    }
    else if(typeOfWindow == 2){

        if (selectedItemIndex == 0) {
            menu[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex = 10;
            menu[selectedItemIndex].setColor(sf::Color::Red);
        }
    }
}

void Menu::itemsMenu()
{
    clearItems();
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Buscar");
    menu[0].setPosition(sf::Vector2f(width/4, height /(5) * 1));
    menu[0].setScale(1.5,1.5);

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Guardar imagen o galeria");
    menu[1].setPosition(sf::Vector2f(width/4, height /(5) * 2));
    menu[1].setScale(1.5,1.5);


    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Editar metadata");
    menu[2].setPosition(sf::Vector2f(width/4, height /(5) * 3));
    menu[2].setScale(1.5,1.5);



    selectedItemIndex = 0;

}
void Menu::itemsSearchImagen()
{
    clearItems();
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Buscar Imagen");
    menu[0].setPosition(sf::Vector2f(width/15, height /(14) * 1));
    menu[0].setScale(1,1);

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Escriba el nombre de la imagen");
    menu[1].setPosition(sf::Vector2f(width/15, height /(14) * 2));
    menu[1].setScale(1,1);

    menu[10].setFont(font);
    menu[10].setColor(sf::Color::White);
    menu[10].setString("Atras");
    menu[10].setPosition(sf::Vector2f(width/15, height /(14) * 11));
    menu[10].setScale(1,1);

    selectedItemIndex = 0;
}

void Menu::itemsSave()
{
    clearItems();
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Guardar Imagen");
    menu[0].setPosition(sf::Vector2f(width/15, height /(14) * 1));
    menu[0].setScale(1,1);

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Escribe el path con la extencion de la imagen (jpg, png)");
    menu[1].setPosition(sf::Vector2f(width/15, height /(14) * 2));
    menu[1].setScale(0.5,1);

    menu[10].setFont(font);
    menu[10].setColor(sf::Color::White);
    menu[10].setString("Atras");
    menu[10].setPosition(sf::Vector2f(width/15, height /(14) * 11));
    menu[10].setScale(0.5,1);

    selectedItemIndex = 0;
}

void Menu::itemsSelect()
{
    clearItems();
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Select");
    menu[0].setPosition(sf::Vector2f(width/15, height /(14) * 1));
    menu[0].setScale(1,1);

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Escriba los parametros que desea buscar");
    menu[1].setPosition(sf::Vector2f(width/15, height /(14) * 2));
    menu[1].setScale(0.5,1);

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("From");
    menu[2].setPosition(sf::Vector2f(width/15, height /(14) * 3));
    menu[2].setScale(1,1);

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Escriba donde desea buscar");
    menu[3].setPosition(sf::Vector2f(width/15, height /(14) * 4));
    menu[3].setScale(0.5,1);

    menu[4].setFont(font);
    menu[4].setColor(sf::Color::White);
    menu[4].setString("Where");
    menu[4].setPosition(sf::Vector2f(width/15, height /(14) * 5));
    menu[4].setScale(1,1);

    menu[5].setFont(font);
    menu[5].setColor(sf::Color::White);
    menu[5].setString("Escriba los valores de los parametros");
    menu[5].setPosition(sf::Vector2f(width/15, height /(14) * 6));
    menu[5].setScale(0.5,1);

    menu[10].setFont(font);
    menu[10].setColor(sf::Color::White);
    menu[10].setString("Atras");
    menu[10].setPosition(sf::Vector2f(width/15, height /(14) * 11));
    menu[10].setScale(0.5,1);

    selectedItemIndex = 0;
}

void Menu::itemsInsert()
{
    clearItems();
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Insert INTO");
    menu[0].setPosition(sf::Vector2f(width/15, height /(14) * 1));
    menu[0].setScale(1,1);

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Escriba el nombre de la tabla y sus datos");
    menu[1].setPosition(sf::Vector2f(width/15, height /(14) * 2));
    menu[1].setScale(0.5,1);

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Values");
    menu[2].setPosition(sf::Vector2f(width/15, height /(14) * 3));
    menu[2].setScale(1,1);

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Escriba los valores");
    menu[3].setPosition(sf::Vector2f(width/15, height /(14) * 4));
    menu[3].setScale(0.5,1);



    menu[10].setFont(font);
    menu[10].setColor(sf::Color::White);
    menu[10].setString("Atras");
    menu[10].setPosition(sf::Vector2f(width/15, height /(14) * 11));
    menu[10].setScale(0.5,1);

    selectedItemIndex = 0;
}

void Menu::itemsDelete()
{
    clearItems();
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Delete FROM");
    menu[0].setPosition(sf::Vector2f(width/15, height /(14) * 1));
    menu[0].setScale(1,1);

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Escriba donde desea eliminar");
    menu[1].setPosition(sf::Vector2f(width/15, height /(14) * 2));
    menu[1].setScale(0.5,1);

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("WHERE");
    menu[2].setPosition(sf::Vector2f(width/15, height /(14) * 3));
    menu[2].setScale(1,1);

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Informacion de la imagen o imagenes que desea eliminar");
    menu[3].setPosition(sf::Vector2f(width/15, height /(14) * 4));
    menu[3].setScale(0.5,1);

    menu[10].setFont(font);
    menu[10].setColor(sf::Color::White);
    menu[10].setString("Atras");
    menu[10].setPosition(sf::Vector2f(width/15, height /(14) * 11));
    menu[10].setScale(0.5,1);

    selectedItemIndex = 0;
}

void Menu::itemsUpdate()
{
    clearItems();
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Update");
    menu[0].setPosition(sf::Vector2f(width/15, height /(14) * 1));
    menu[0].setScale(1,1);

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Escriba donde quiere actualizar la informacion");
    menu[1].setPosition(sf::Vector2f(width/15, height /(14) * 2));
    menu[1].setScale(0.5,1);

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("SET");
    menu[2].setPosition(sf::Vector2f(width/15, height /(14) * 3));
    menu[2].setScale(1,1);

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Escriba parametro y valor que desea actualizar");
    menu[3].setPosition(sf::Vector2f(width/15, height /(14) * 4));
    menu[3].setScale(0.5,1);

    menu[4].setFont(font);
    menu[4].setColor(sf::Color::White);
    menu[4].setString("WHERE");
    menu[4].setPosition(sf::Vector2f(width/15, height /(14) * 5));
    menu[4].setScale(1,1);

    menu[5].setFont(font);
    menu[5].setColor(sf::Color::White);
    menu[5].setString("Escriba el criterio de busqueda");
    menu[5].setPosition(sf::Vector2f(width/15, height /(14) * 2));
    menu[5].setScale(0.5,1);

    menu[10].setFont(font);
    menu[10].setColor(sf::Color::White);
    menu[10].setString("Atras");
    menu[10].setPosition(sf::Vector2f(width/15, height /(14) * 11));
    menu[10].setScale(0.5,1);

    selectedItemIndex = 0;
}




void Menu::itemsSaveGalery()
{
    clearItems();
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Guardar galeria");
    menu[0].setPosition(sf::Vector2f(width/15, height /(14) * 1));
    menu[0].setScale(1,1);

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Escribe el nombre de la galeria");
    menu[1].setPosition(sf::Vector2f(width/15, height /(14) * 2));
    menu[1].setScale(0.5,1);

    menu[10].setFont(font);
    menu[10].setColor(sf::Color::White);
    menu[10].setString("Atras");
    menu[10].setPosition(sf::Vector2f(width/15, height /(14) * 11));
    menu[10].setScale(0.5,1);

    selectedItemIndex = 0;
}

void Menu::itemsMenuSave() {
    clearItems();
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Guardar imagen");
    menu[0].setPosition(sf::Vector2f(width/5, height /(5) * 1));
    menu[0].setScale(1.5,1.5);

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Guardar galeria");
    menu[1].setPosition(sf::Vector2f(width/5, height /(5) * 2));
    menu[1].setScale(1.5,1.5);

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Atras");
    menu[2].setPosition(sf::Vector2f(width/5, height /(5) * 4));
    menu[2].setScale(1.5,1.5);

    selectedItemIndex = 0;


}
void Menu::menuMetadata() {
    clearItems();
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Select");
    menu[0].setPosition(sf::Vector2f(width/5, height /(7) * 1));
    menu[0].setScale(1.5,1.5);

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Insert");
    menu[1].setPosition(sf::Vector2f(width/5, height /(7) * 2));
    menu[1].setScale(1.5,1.5);

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Delete");
    menu[2].setPosition(sf::Vector2f(width/5, height /(7) * 3));
    menu[2].setScale(1.5,1.5);

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Update");
    menu[3].setPosition(sf::Vector2f(width/5, height /(7) * 4));
    menu[3].setScale(1.5,1.5);


    menu[4].setFont(font);
    menu[4].setColor(sf::Color::White);
    menu[4].setString("Atras");
    menu[4].setPosition(sf::Vector2f(width/5, height /(7) * 5));
    menu[4].setScale(1.5,1.5);

    selectedItemIndex = 0;


}
void Menu::clearItems()
{
    for (int i = 0; i < NumberOfItems ; ++i) {
        menu[i].setString("");
    }
    this->display = "";
}

void Menu::setDisplay(std::string inputText)
{
    if(typeOfWindow == 2){
        menu[2].setString("");
    }

    menu[1].setString(inputText);
    display = inputText;
}

void Menu::search() {
    getTable();
    if(this->names.getSize() != 0)
    {
        LinkedList<std::string> cNames = coincidence();
        int size = cNames.getSize();
        if(size > 0) {
            for (int i = 0; i < size; ++i) {
                if (i < 8) {

                    int j = i + 2;
                    menu[j].setFont(font);
                    menu[j].setColor(sf::Color::White);
                    menu[j].setString(cNames.getElement(i)->getData());
                    menu[j].setPosition(sf::Vector2f(width/15, height/(11) * (i + 3)));
                    menu[j].setScale(0.5, 0.5);
                }
            }
            if (size < 8) {
                for (int i = 0; i < (8 - size); ++i) {

                    int j = size + i + 2;
                    menu[j].setFont(font);
                    menu[j].setColor(sf::Color::White);
                    menu[j].setString(" ");
                    menu[j].setPosition(sf::Vector2f(width / 15, height / (11) * (size + i + 3)));
                    menu[j].setScale(0.5, 0.5);
                }
            }
            this->typeOfWindow = 1;

        }else{
            menu[2].setFont(font);
            menu[2].setColor(sf::Color::White);
            menu[2].setString("No se encontro imagenes");
            menu[2].setPosition(sf::Vector2f(width/15, height /(14) * 3));
            menu[2].setScale(1,1);

            for (int i = 3; i < 10 ; ++i) {
                menu[i].setString("");
            }
        }
    }else{
        menu[2].setFont(font);
        menu[2].setColor(sf::Color::White);
        menu[2].setString("No se encontro imagenes");
        menu[2].setPosition(sf::Vector2f(width/15, height /(14) * 3));
        menu[2].setScale(1,1);

        for (int i = 3; i < 10 ; ++i) {
            menu[i].setString("");
        }
    }
}

void Menu::getTable() {
    sf::Packet packet;
    packet << "getTable";
    Singleton::getServer()->send(packet);

    //Se espera a recibir la respuesta del servidor
    sf::Packet receivePacket;
    std::string receiveMessage;
    if (Singleton::getServer()->receive(receivePacket) == sf::Socket::Done) {
        receivePacket >> receiveMessage;
    }

    LinkedList<std::string> elements = Singleton::splitString(receiveMessage, "/");
    LinkedList<std::string> names = LinkedList<std::string>();

    for (int i = 1; i < elements.getSize(); ++i) {
        std::string name = Singleton::splitString(elements.getElement(i)->getData(), ";").getElement(0)->getData();
        names.insertAtEnd(name);
    }

    this->names = names;
}

LinkedList<std::string> Menu::coincidence()
{

    LinkedList<std::string> coinNames;
    int size = this->display.length();

    for (int i = 0; i < this->names.getSize(); ++i) {
        if(size <= this->names.getElement(i)->getData().length()) {
            std::string subString = this->names.getElement(i)->getData().substr(0, (size));
            int bd = strncmp(display.c_str(), subString.c_str(), size);
            if (bd == 0) {
                coinNames.insertAtFirst(this->names.getElement(i)->getData());
            }
        }
    }


    return coinNames;
}



void Menu::saveImagen()  {
    {
        if (ImagenHandler::sendImagen(display) == 0)
        {
            menu[2].setFont(font);
            menu[2].setColor(sf::Color::White);
            menu[2].setString("La imagen se guardo con exito");
            menu[2].setPosition(sf::Vector2f(width/15, height /(14) * 3));
            menu[2].setScale(1,1);
        } else{
            menu[2].setFont(font);
            menu[2].setColor(sf::Color::White);
            menu[2].setString("No se encontro la imagen");
            menu[2].setPosition(sf::Vector2f(width/15, height /(14) * 3));
            menu[2].setScale(1,1);
        }
    }
}
void Menu::saveGalery() {
    if (ImagenHandler::sendDirectory(display) == 0)
    {
        menu[2].setFont(font);
        menu[2].setColor(sf::Color::White);
        menu[2].setString("El conjunto de imagenes \n se guardo con exito");
        menu[2].setPosition(sf::Vector2f(width/15, height /(14) * 3));
        menu[2].setScale(1,1);
    } else{
        menu[2].setFont(font);
        menu[2].setColor(sf::Color::White);
        menu[2].setString("No se encontro la galeria");
        menu[2].setPosition(sf::Vector2f(width/15, height /(14) * 3));
        menu[2].setScale(1,1);
    }

}

void Menu::run() {
    int numberOfWindow = 0;
    sf::RenderWindow window;
    window.create(sf::VideoMode(1200,800), "MyIDE");
    window.setPosition(sf::Vector2i(100,100));

    sf::Texture bg;
    sf::Sprite bgS;
    if(!bg.loadFromFile("../bg.jpg"))
        std::cout << "Error could not load nave image" << std::endl;
    bgS.setTexture(bg);
    bgS.setScale(0.5f,0.5f);

    Menu menu(window.getSize().x, window.getSize().y);
    menu.itemsMenu();
    std::string display;

    while (window.isOpen()){

        if (numberOfWindow == 0) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::KeyReleased:
                        switch (event.key.code) {
                            case sf::Keyboard::Up:
                                menu.MoveUp();
                                break;

                            case sf::Keyboard::Down:
                                menu.MoveDown();
                                break;

                            case sf::Keyboard::Tab:
                                switch (menu.GetPressdItem()) {
                                    case 0:
                                        numberOfWindow = 1;
                                        menu.itemsSearchImagen();
                                        menu.typeOfWindow = 2;
                                        display = "";
                                        break;

                                    case 1:
                                        numberOfWindow = 3;
                                        menu.itemsMenuSave();
                                        display = "";
                                        break;
                                    case 2:
                                        numberOfWindow = 5;
                                        menu.menuMetadata();
                                        menu.typeOfWindow = 3;
                                        display = "";
                                        break;

                                }
                                break;
                        }
                        break;

                    case sf::Event::Closed:
                        window.close();
                        break;
                }
            }

        } else if (numberOfWindow == 1) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::KeyReleased:
                        switch (event.key.code) {
                            case sf::Keyboard::Up:
                                menu.MoveUp();
                                break;

                            case sf::Keyboard::Down:
                                menu.MoveDown();
                                break;

                            case sf::Keyboard::Tab:
                                switch (menu.GetPressdItem()) {
                                    case 0:
                                        menu.search();
                                        break;

                                    case 2:
                                    case 3:
                                    case 4:
                                    case 5:
                                    case 6:
                                    case 7:
                                    case 8:
                                    case 9:
                                        window.close();

                                        break;
                                    case 10:
                                        numberOfWindow = 0;
                                        menu.itemsMenu();
                                        menu.typeOfWindow = 0;
                                        break;
                                }
                        }
                        break;

                    case sf::Event::TextEntered:
                        if (event.text.unicode >= 20 && event.text.unicode <= 126)
                            display += (char) event.text.unicode;
                        else if (event.text.unicode == 8)
                            display = display.substr(0, display.length() - 1);
                        menu.setDisplay(display);
                        break;

                    case sf::Event::Closed:
                        window.close();
                        break;

                }
            }
        }
            else if (numberOfWindow == 5) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    switch (event.type) {
                        case sf::Event::KeyReleased:
                            switch (event.key.code) {
                                case sf::Keyboard::Up:
                                    menu.MoveUp();
                                    break;

                                case sf::Keyboard::Down:
                                    menu.MoveDown();
                                    break;

                                case sf::Keyboard::Tab:
                                    switch (menu.GetPressdItem()) {
                                        case 0:
                                            menu.itemsSelect();
                                            menu.typeOfWindow = 1;
                                            break;

                                        case 1:
                                            menu.itemsInsert();
                                            menu.typeOfWindow = 2;
                                            break;
                                        case 2:
                                            menu.itemsDelete();
                                            menu.typeOfWindow = 2;
                                            break;
                                        case 3:
                                            menu.itemsUpdate();
                                            menu.typeOfWindow = 2;
                                            break;
                                        case 4:
                                            numberOfWindow = 0;
                                            menu.itemsMenu();
                                            menu.typeOfWindow=0;
                                            break;
                                        case 10:
                                            numberOfWindow = 5;
                                            menu.menuMetadata();
                                            menu.typeOfWindow = 3;
                                            break;

                                    }
                            }
                            break;

                        case sf::Event::TextEntered:
                            if (event.text.unicode >= 20 && event.text.unicode <= 126)
                                display += (char) event.text.unicode;
                            else if (event.text.unicode == 8)
                                display = display.substr(0, display.length() - 1);
                            menu.setDisplay(display);
                            break;

                        case sf::Event::Closed:
                            window.close();
                            break;

                    }
                }

        } if (numberOfWindow == 2) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::KeyReleased:
                        switch (event.key.code) {
                            case sf::Keyboard::Up:
                                menu.MoveUp();
                                break;

                            case sf::Keyboard::Down:
                                menu.MoveDown();
                                break;

                            case sf::Keyboard::Tab:
                                switch (menu.GetPressdItem()) {
                                    case 0:
                                        menu.saveImagen();
                                        break;
                                    case 1:
                                        menu.saveImagen();
                                        break;

                                    case 10:
                                        numberOfWindow = 3;
                                        menu.itemsMenuSave();
                                        menu.typeOfWindow = 0;
                                        break;
                                }
                        }
                        break;

                    case sf::Event::TextEntered:
                        if (event.text.unicode >= 20 && event.text.unicode <= 126)
                            display += (char) event.text.unicode;
                        else if (event.text.unicode == 8)
                            display = display.substr(0, display.length() - 1);
                        menu.setDisplay(display);
                        break;

                    case sf::Event::Closed:
                        window.close();
                        break;
                }
            }
        } else if (numberOfWindow == 3) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::KeyReleased:
                        switch (event.key.code) {
                            case sf::Keyboard::Up:
                                menu.MoveUp();
                                break;

                            case sf::Keyboard::Down:
                                menu.MoveDown();
                                break;

                            case sf::Keyboard::Tab:
                                switch (menu.GetPressdItem()) {
                                    case 0:
                                        numberOfWindow = 2;
                                        menu.itemsSave();
                                        menu.typeOfWindow = 2;
                                        display = "";
                                        break;

                                    case 1:
                                        numberOfWindow = 2;
                                        menu.itemsSaveGalery();
                                        menu.typeOfWindow = 2;
                                        display = "";
                                        break;

                                    case 2:
                                        numberOfWindow = 0;
                                        menu.itemsMenu();
                                        menu.typeOfWindow = 0;
                                        break;
                                }
                                break;
                        }
                        break;

                    case sf::Event::Closed:
                        window.close();
                        break;
                }
            }

        } else if (numberOfWindow == 4) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::KeyReleased:
                        switch (event.key.code) {
                            case sf::Keyboard::Up:
                                menu.MoveUp();
                                break;

                            case sf::Keyboard::Down:
                                menu.MoveDown();
                                break;

                            case sf::Keyboard::Tab:
                                switch (menu.GetPressdItem()) {
                                    case 0:
                                        menu.saveGalery();
                                        break;

                                    case 10:
                                        numberOfWindow = 3;
                                        menu.itemsMenuSave();
                                        menu.typeOfWindow = 0;
                                        break;
                                }
                        }
                        break;

                    case sf::Event::TextEntered:
                        if (event.text.unicode >= 20 && event.text.unicode <= 126)
                            display += (char) event.text.unicode;
                        else if (event.text.unicode == 8)
                            display = display.substr(0, display.length() - 1);
                        menu.setDisplay(display);
                        break;

                    case sf::Event::Closed:
                        window.close();
                        break;
                }
            }
        }

        window.clear();
        menu.draw(window);
        window.display();
    }
}
