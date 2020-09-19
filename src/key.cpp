#include "key.hpp"
#include <iostream>

Key::Key() : color(sf::Color((255, 255, 255))), note(Constants::A4)
{
    this->rectangle = sf::RectangleShape(sf::Vector2f(30, 10));
    this->rectangle.move(0, 0);
    this->rectangle.setFillColor(sf::Color((255, 255, 255)));
}

Key::Key(sf::Vector2f size, sf::Vector2i position, Constants::Notes note) 
{
    this->note = note;
    this->rectangle = sf::RectangleShape(sf::Vector2f(size.x, size.y));
    this->rectangle.move(position.x, position.y);

    this->rectangle.setFillColor(sf::Color(255, 255, 255));
    return;
}

void Key::set_color()
{
    for(int i = 0; i < 8; i++)
    {
        int n = note - i * 12;
        if(n == 1 ||
           n == 4 ||
           n == 6 ||
           n == 9 ||
           n == 11)
           {
                std::cout << "black\n";
                this->rectangle.setFillColor(sf::Color((0, 0, 0)));
                return;
           }
    }
}

Constants::Notes Key::get_note()
{
    return this->note;
}

Key::~Key() {}

void Key::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform = getTransform();
    target.draw(this->rectangle, states);
}

std::string Key::string_color()
{
    if (this->color == sf::Color((0, 0, 0))) return "black";
    return "white";
}