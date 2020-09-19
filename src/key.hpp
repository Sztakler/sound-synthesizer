#pragma once

#include "constants.hpp"
#include <SFML/Graphics.hpp>

class Key : public sf::Sprite
{
    public:
        sf::RectangleShape rectangle;
        Constants::Notes note;
        sf::Color color;

    public:
        Key();
        Key(sf::Vector2f size, sf::Vector2i position, Constants::Notes note);
        ~Key();

    public:
        Constants::Notes get_note();

    public:
        void set_color();
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
        std::string string_color();

};