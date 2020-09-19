#include "synthesizer.hpp"
#include "math.h"
#include <iostream>

Synthesizer::Synthesizer() : wave_type(Constants::Sinus), SAMPLES(82000) {}

Synthesizer::Synthesizer(Constants::WaveType wave_type) : wave_type(wave_type), SAMPLES(82000) {}

Synthesizer::Synthesizer(Constants::WaveType wave_type, unsigned samples) : wave_type(wave_type), SAMPLES(samples) {}

Synthesizer::~Synthesizer() 
{
    for(sf::Int16* raw : this->raw_samples)
    {
        delete[](raw);
    }
}

void Synthesizer::generate_sample(Constants::Notes note)
{
    double x = 0;
    double frequency = Constants::FREQUENCIES[note];
    double increment = frequency / this->SAMPLE_RATE;
    sf::Int16* raw = new sf::Int16[SAMPLES];
    for (unsigned i = 0; i < SAMPLES; i++)
    {
        int sgn = sin(x * Constants::TWO_PI) > 0 ? 1 : -1;
        // raw[i] = Constants::AMPLITUDE *sin(x * Constants::TWO_PI);
        raw[i] = sgn * 5;
        x += increment;
    }
    this->raw_samples.push_back(raw);

    for(int i = 0; i < SAMPLES; i++)
    {
        std::cout << raw[i];
    }
}

void Synthesizer::generate_samples()
{
    double x = 0;
    Constants::Notes note = Constants::A0;
    double frequency = Constants::FREQUENCIES[note];
    double increment = frequency / this->SAMPLE_RATE;
    int sgn;
    for(unsigned i = 0; i < NOTES; i++)
    {

        
        sf::Int16* raw = new sf::Int16[SAMPLES];

        for (unsigned j = 0; j < SAMPLES; j++)
        {
            raw[j] = Constants::AMPLITUDE * sin(x * Constants::TWO_PI);
            // sgn = sin(x * Constants::TWO_PI) > 0 ? 1 : -1;
            // raw[j] = sgn * 15000;
            x += increment;
        }

        x = 0;
        frequency = Constants::FREQUENCIES[i];
        increment = frequency / this->SAMPLE_RATE;
        
        this->raw_samples.push_back(raw);

        if (!this->buffers[i].loadFromSamples(this->raw_samples[i], this->SAMPLES, 1, this->SAMPLE_RATE))
        {
            throw std::invalid_argument("Loading failed");
        }
        sf::Sound* sound = new sf::Sound(this->buffers[i]);
        sound->setLoop(true);
        this->note_samples.push_back(sound);
    }
}

void Synthesizer::play(Constants::Notes note)
{
    this->current_note = this->note_samples[note];
    if(this->current_note->getStatus() == sf::Sound::Status::Stopped)
    {
        this->current_note = this->note_samples[note];
        this->current_note->setPlayingOffset(sf::seconds(0.1));
        this->current_note->play();
    }
}

void Synthesizer::stop()
{
    this->current_note->stop();
}