#pragma once

#include "constants.hpp"
#include "synthesizer.hpp"
#include <SFML/Graphics.hpp>

class Key : public sf::Sprite
{
    public:
        sf::RectangleShape rectangle;
        Constants::Notes note = Constants::Notes::None;
        sf::Color color;
        bool pressed;

    public:
        Key();
        Key(sf::Vector2f size, sf::Vector2i position, Constants::Notes note);
        ~Key();

    public:
        Constants::Notes get_note();
        void play(Synthesizer* synthesizer);
        void stop(Synthesizer* synthesizer);

    public:
        void set_color();
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
        std::string string_color();

};