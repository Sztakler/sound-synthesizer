#pragma once

#include <SFML/Audio.hpp>
#include "constants.hpp"
#include <math.h>
#include <deque>

class Synthesizer
{
    private:
        unsigned SAMPLES;
        unsigned NOTES = 88;
        unsigned SAMPLE_RATE = SAMPLES;

        std::deque<sf::Int16*> raw_samples;
        Constants::WaveType wave_type;
        sf::SoundBuffer* buffers = new sf::SoundBuffer[88];
        std::deque<sf::Sound*> note_samples;
        sf::Sound* current_note;

    
    public:
        Synthesizer();
        Synthesizer(Constants::WaveType wave_type);
        Synthesizer(Constants::WaveType wave_type, unsigned samples);
        ~Synthesizer();


    public:
        void generate_samples();
        void play(Constants::Notes note);
        void stop();

    private:
        void generate_sample(Constants::Notes note);
};