//
// Created by jonathan on 17/06/19.
//

#include "Image.h"

void Image::createImage(std::string nombre, std::vector<char> buffer) {
    sf::ContextSettings glsettings;
    glsettings.antialiasingLevel = 2;
    sf::RenderWindow window{sf::VideoMode{800, 600}, "loadFromMemory Example", sf::Style::Titlebar | sf::Style::Close, glsettings};

    const auto desktop = sf::VideoMode::getDesktopMode();
    window.setPosition({static_cast<int>(desktop.width / 2 - window.getSize().x / 2),
                        static_cast<int>(desktop.height / 4 - window.getSize().y / 4)});

    window.setMouseCursorVisible(false);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    std::ifstream texture_file{nombre, std::ifstream::binary};

    if (texture_file) {
        // get length of file:
        texture_file.seekg(0, texture_file.end);
        const auto length = texture_file.tellg();
        if (!length) {
            std::cerr << "Cannot load zero byte texture file" << std::endl;

        }
        buffer.resize(length); // reserve space

        texture_file.seekg(0, texture_file.beg);

        auto start = &*buffer.begin();
        texture_file.read(start, length);
        texture_file.close();
    } else {
        std::cerr << "Could not open texture file" << std::endl;

    }

    sf::Texture texture;
    if (!texture.loadFromMemory(&buffer[0], buffer.size())) {
        std::cerr << "Texture load failed" << std::endl;

    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }


}

