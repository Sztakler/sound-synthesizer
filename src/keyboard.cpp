#include "keyboard.hpp"
#include "constants.hpp"
#include <iostream>
#include <algorithm>

Keyboard::Keyboard()
{
    this->synthesizer = new Synthesizer();
    this->synthesizer->generate_samples(Constants::WaveType::Square);


    for(int i = 0; i < 88; i++)
    {
        sf::Vector2f size(11.75, 90);
        sf::Vector2i position(75 + i * (11.75 + 2), 200);
        Key* key = new Key(size, position, Constants::Notes(i));
        this->set_key_color(key);
        this->keys.push_back(key);
    }

    this->set_keys_position();
}

Keyboard::~Keyboard() 
{

}

void Keyboard::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(Key* key : this->white_keys)
    {
        key->draw(target, states);
    }

    for(Key* key : this->black_keys)
    {
        key->draw(target, states);
    }
}

void Keyboard::set_key_color(Key* key)
{
    Constants::Notes note = key->note;
    for(int i = 0; i < 8; i++)
    {
        int n = note - i * 12;
        if(n == 1 ||
           n == 4 ||
           n == 6 ||
           n == 9 ||
           n == 11)
           {
                key->rectangle.setFillColor(sf::Color((255, 255, 255)));
                this->black_keys.push_back(key);
                return;
           }
    }
    this->white_keys.push_back(key);
    return;
}

void Keyboard::set_keys_position()
{   
    
    double previous_key_x = 80;
    for(int i = 0; i < 88; i++)
    {   
        Key* key = this->keys[i];
        if(key->rectangle.getFillColor() == sf::Color(0, 0, 0))
        {
            key->rectangle.setPosition(previous_key_x - Constants::black_key_width/2 + Constants::offset, 200);
            key->rectangle.setSize(sf::Vector2f(Constants::black_key_width, Constants::black_key_length));
        }
        else
        {
            key->rectangle.setPosition(previous_key_x + Constants::offset, 200);
            key->rectangle.setSize(sf::Vector2f(Constants::white_key_width, Constants::white_key_length));

            previous_key_x += Constants::white_key_width + 2;
        }
        
    }
}


void Keyboard::press_key(Constants::Notes note)
{
    Key* pressed_key = this->keys[note];

    if(!pressed_key->pressed)
    {
        pressed_key->pressed = true;
        this->pressed_keys.push_back(pressed_key);
        this->play();

        if(pressed_key->rectangle.getFillColor() == sf::Color(0, 0, 0))
        {
            pressed_key->rectangle.setFillColor(sf::Color(3, 175, 11, 150));
        }
        else 
        {
            pressed_key->rectangle.setFillColor(sf::Color(70, 251, 79, 255));
        }    
    }
    // if(!this->key_pressed)
    // {
    //     this->key_pressed = true;
    //     this->pressed_key = this->keys[note];
    //     this->playing_notes.push_back(this->pressed_key);
    //     this->play();

    //     if(this->pressed_key->rectangle.getFillColor() == sf::Color(0, 0, 0))
    //     {
    //         this->pressed_key->rectangle.setFillColor(sf::Color(3, 175, 11, 150));
    //     }
    //     else 
    //     {
    //         this->pressed_key->rectangle.setFillColor(sf::Color(70, 251, 79, 255));
    //     }    
    // }
        
}

void Keyboard::release_key(Constants::Notes note)
{
    for(Key* key : this->pressed_keys)
    {
            key->pressed = false;
            
            int index = 0;

            for(Key* pressed_key : this->pressed_keys)
            {
                if(key == pressed_key)
                {
                    key->stop(this->synthesizer);
                    if(key->rectangle.getFillColor() == sf::Color(70, 251, 79, 255))
                    {
                        key->rectangle.setFillColor(sf::Color(255, 255, 255, 255));
                    }
                    else 
                    {
                        key->rectangle.setFillColor(sf::Color(0, 0, 0, 255));
                    } 

                    this->pressed_keys.erase(this->pressed_keys.begin() + index);
                }
                else index++;
            }


            // this->synthesizer->stop(note);

            // if(key->rectangle.getFillColor() == sf::Color(70, 251, 79, 255))
            // {
            //     key->rectangle.setFillColor(sf::Color(255, 255, 255, 255));
            // }
            // else 
            // {
            //     key->rectangle.setFillColor(sf::Color(0, 0, 0, 255));
            // } 
    }

    // if(this->key_pressed)
    // {
    //     this->key_pressed = false;
    //     this->synthesizer.stop();

    //     if(this->pressed_key->rectangle.getFillColor() == sf::Color(70, 251, 79, 255))
    //     {
    //         this->pressed_key->rectangle.setFillColor(sf::Color(255, 255, 255, 255));
    //     }
    //     else 
    //     {
    //         this->pressed_key->rectangle.setFillColor(sf::Color(0, 0, 0, 255));
    //     } 

    //     this->pressed_key = NULL;
    // }

}

void Keyboard::play()
{
    for(Key* key : this->pressed_keys)
    {
        key->play(this->synthesizer);
    }

}

void Keyboard::stop()
{
    for(Key* key : this->pressed_keys)
    {
        key->stop(this->synthesizer);
    }
}


// bool Keyboard::is_key_pressed(sf::Event event, Synthesizer synthesizer)
// {
//     if(event.type == sf::Event::KeyPressed)
//     {
//         switch (event.key.code)
//         {
//             case sf::Keyboard::Num1:
//                 // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
//                     synthesizer.play(Constants::A4);
//                 // synthesizer.stop();
//                 break;
//             case sf::Keyboard::Num2:
//                 while(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
//                     synthesizer.play(Constants::Bb4);
//                 synthesizer.stop();
//             case sf::Keyboard::Num3:
//                 while(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
//                     synthesizer.play(Constants::B4);
//                 synthesizer.stop();
//             case sf::Keyboard::Num4:
//                 while(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
//                     synthesizer.play(Constants::C4);
//                 synthesizer.stop();
//             case sf::Keyboard::Num5:
//                 while(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
//                     synthesizer.play(Constants::Db4);
//                 synthesizer.stop();
//         }
//     }
    
        
// }

//Black keys Bb0, Db1, Eb1, Gb1, Ab1, Bb1, Db2, Eb2, Gb2, Ab2, Bb2, Db3, Eb3, Gb3, Ab3, Bb3, Db4, Eb4, Gb4, Ab4, Bb4, Db5, Eb5, Gb5, Ab5, Bb5, Db6, Eb6, Gb6, Ab6, Bb6, Db7, Eb7, Gb7, Ab7, Bb7