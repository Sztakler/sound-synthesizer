#pragma once

#include <SFML/Audio.hpp>
#include "constants.hpp"
#include <math.h>
#include <deque>
#include <vector>

class Synthesizer
{
    private:
        unsigned SAMPLES;
        unsigned NOTES = 88;
        unsigned SAMPLE_RATE = SAMPLES;

        Constants::WaveType wave_type;
        std::deque<sf::Int16*> raw_samples;
        sf::SoundBuffer* buffers = new sf::SoundBuffer[88];
        std::deque<sf::Sound*> note_samples;
        sf::Sound* current_note;
        std::vector<sf::Sound*> current_notes;
    
    public:
        Synthesizer();
        Synthesizer(Constants::WaveType wave_type);
        Synthesizer(Constants::WaveType wave_type, unsigned samples);
        ~Synthesizer();


    public:
        void generate_samples(Constants::WaveType wave_type);
        void play(Constants::Notes note);
        void stop(Constants::Notes note);

    private:
        void generate_sample(Constants::Notes note);
        void generate_sine_wave();
        void generate_square_wave();
};