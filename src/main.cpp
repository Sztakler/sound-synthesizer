#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "synthesizer.hpp"
#include "constants.hpp"
#include "key.hpp"
#include "keyboard.hpp"
#include <iostream>


int main()
{
    Synthesizer synthesizer = Synthesizer();
    Keyboard keyboard = Keyboard();

    int width = 1498.25;
    int heigth = 600;
    sf::RenderWindow window(sf::VideoMode(width,heigth),"8-bit Keyboard");
    window.setFramerateLimit(330);
    window.setKeyRepeatEnabled(false);

    // synthesizer.generate_samples();


    while(window.isOpen())
    {
        window.clear(sf::Color(50, 50, 50));
        window.draw(keyboard);  
        
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
                
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                {
                    Constants::Notes note = Constants::black_key_to_note_map.find(event.key.code)->second;
                    if (note!=Constants::Notes::A0) keyboard.press_key(note);
                }
                else
                {
                    Constants::Notes note = Constants::white_key_to_note_map.find(event.key.code)->second;
                    keyboard.press_key(note);
                }
            }
            else if(event.type == sf::Event::KeyReleased) 
            {
                Constants::Notes note = Constants::white_key_to_note_map.find(event.key.code)->second;
                keyboard.release_key(note);
            }
        }
        window.display();
    }
    return 0;
}