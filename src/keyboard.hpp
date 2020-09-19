#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "key.hpp"
#include "constants.hpp"
#include "synthesizer.hpp"

class Keyboard : public sf::Sprite
{   
    private:
        std::vector<Key*> keys;
        std::vector<Key*> black_keys;
        std::vector<Key*> white_keys;
        Key* pressed_key;
        Synthesizer synthesizer;

    public:
        Keyboard();
        ~Keyboard();

    public:
        bool is_key_pressed(sf::Event event, Synthesizer synthesizer);
        void press_key(Constants::Notes note);
        void release_key(Constants::Notes note);
        void play();

    private:
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
        void set_key_color(Key* key);
        void set_keys_position();
       
};