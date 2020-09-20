#include "constants.hpp"

//  Bb0, Db1, Eb1, Gb1, Ab1, Bb1,


const std::map<sf::Keyboard::Key, Constants::Notes> Constants::white_key_to_note_map = 
    {
        {sf::Keyboard::F1, Notes::A0}, {sf::Keyboard::F2, Notes::B0},
        {sf::Keyboard::F3, Notes::C1}, {sf::Keyboard::F4, Notes::D1}, 
        {sf::Keyboard::F5, Notes::E1}, {sf::Keyboard::F6, Notes::F1}, {sf::Keyboard::F7, Notes::G1}, 
        {sf::Keyboard::F8, Notes::A1}, {sf::Keyboard::F9, Notes::B1}, 
        {sf::Keyboard::F10, Notes::C2}, {sf::Keyboard::F11, Notes::D2}, 
        {sf::Keyboard::F12, Notes::E2}, {sf::Keyboard::Num1, Notes::F2}, {sf::Keyboard::Num2, Notes::G2}, 
        {sf::Keyboard::Num3, Notes::A2}, {sf::Keyboard::Num4, Notes::B2},
        {sf::Keyboard::Num5, Notes::C3}, {sf::Keyboard::Num6, Notes::D3}, 
        {sf::Keyboard::Num7, Notes::E3}, {sf::Keyboard::Num8, Notes::F3}, {sf::Keyboard::Num9, Notes::G3}, 
        {sf::Keyboard::Num0, Notes::A3}, {sf::Keyboard::Dash, Notes::B3}, 
        {sf::Keyboard::Equal, Notes::C4}, {sf::Keyboard::Q, Notes::D4}, 
        {sf::Keyboard::W, Notes::E4}, {sf::Keyboard::E, Notes::F4}, {sf::Keyboard::R, Notes::G4}, 
        {sf::Keyboard::T, Notes::A4}, {sf::Keyboard::Y, Notes::B4}, 
        {sf::Keyboard::U, Notes::C5}, {sf::Keyboard::I, Notes::D5}, 
        {sf::Keyboard::O, Notes::E5}, {sf::Keyboard::P, Notes::F5}, {sf::Keyboard::LBracket, Notes::G5}, 
        {sf::Keyboard::RBracket, Notes::A5}, {sf::Keyboard::Backslash, Notes::B5},  
        {sf::Keyboard::A, Notes::C6}, {sf::Keyboard::S, Notes::D6}, 
        {sf::Keyboard::D, Notes::E6}, {sf::Keyboard::F, Notes::F6}, {sf::Keyboard::G, Notes::G6}, 
        {sf::Keyboard::H, Notes::A6}, {sf::Keyboard::J, Notes::B6}, 
        {sf::Keyboard::K, Notes::C7}, {sf::Keyboard::L, Notes::D7}, 
        {sf::Keyboard::Semicolon, Notes::E7}, {sf::Keyboard::Quote, Notes::F7}, {sf::Keyboard::Z, Notes::G7}, 
        {sf::Keyboard::X, Notes::A7}, {sf::Keyboard::C, Notes::B7}, 
        {sf::Keyboard::V, Notes::C8}
    };

const std::map<sf::Keyboard::Key, Constants::Notes> Constants::black_key_to_note_map = 
    {
        {sf::Keyboard::F1, Notes::Bb0}, 
        {sf::Keyboard::F3, Notes::Db1}, {sf::Keyboard::F4, Notes::Eb1}, {sf::Keyboard::F6, Notes::Gb1},
        {sf::Keyboard::F7, Notes::Ab1}, {sf::Keyboard::F8, Notes::Bb1},
        {sf::Keyboard::F10, Notes::Db2}, {sf::Keyboard::F11, Notes::Eb2}, {sf::Keyboard::Num1, Notes::Gb2},
        {sf::Keyboard::Num2, Notes::Ab2}, {sf::Keyboard::Num3, Notes::Bb2},
        {sf::Keyboard::Num5, Notes::Db3}, {sf::Keyboard::Num6, Notes::Eb3}, {sf::Keyboard::Num8, Notes::Gb3},
        {sf::Keyboard::Num9, Notes::Ab3}, {sf::Keyboard::Num0, Notes::Bb3},
        {sf::Keyboard::Equal, Notes::Db4}, {sf::Keyboard::Q, Notes::Eb4}, {sf::Keyboard::E, Notes::Gb4},
        {sf::Keyboard::R, Notes::Ab4}, {sf::Keyboard::T, Notes::Bb4},
        {sf::Keyboard::U, Notes::Db5}, {sf::Keyboard::I, Notes::Eb5}, {sf::Keyboard::P, Notes::Gb5},
        {sf::Keyboard::LBracket, Notes::Ab5}, {sf::Keyboard::RBracket, Notes::Bb5},
        {sf::Keyboard::A, Notes::Db6}, {sf::Keyboard::S, Notes::Eb6}, {sf::Keyboard::F, Notes::Gb6},
        {sf::Keyboard::G, Notes::Ab6}, {sf::Keyboard::H, Notes::Bb6},
        {sf::Keyboard::K, Notes::Db7}, {sf::Keyboard::L, Notes::Eb7}, {sf::Keyboard::Quote, Notes::Gb7},
        {sf::Keyboard::Z, Notes::Ab7}, {sf::Keyboard::X, Notes::Bb7} 
    };


const double Constants::FREQUENCIES[88] = {27.5, 29.13523509488062, 30.86770632850775, 32.70319566257483, 34.64782887210901,
                                        36.70809598967594, 38.890872965260115, 41.20344461410875, 43.653528929125486,
                                        46.2493028389543, 48.999429497718666, 51.91308719749314, 55.0, 58.27047018976124,
                                        61.7354126570155, 65.40639132514966, 69.29565774421802, 73.41619197935188, 77.78174593052023,
                                        82.4068892282175, 87.30705785825097, 92.4986056779086, 97.99885899543733, 103.82617439498628, 110.0,
                                        116.54094037952248, 123.47082531403103, 130.8127826502993, 138.59131548843604, 146.8323839587038,
                                        155.56349186104046, 164.81377845643496, 174.61411571650194, 184.9972113558172, 195.99771799087463,
                                        207.65234878997256, 220.0, 233.08188075904496, 246.94165062806206, 261.6255653005986, 
                                        277.1826309768721, 293.6647679174076, 311.1269837220809, 329.6275569128699, 349.2282314330039,
                                        369.9944227116344, 391.99543598174927, 415.3046975799451, 440.0, 466.1637615180899,
                                        493.8833012561241, 523.2511306011972, 554.3652619537442, 587.3295358348151, 622.2539674441618,
                                        659.2551138257398, 698.4564628660078, 739.9888454232688, 783.9908719634985, 830.6093951598903,
                                        880.0, 932.3275230361799, 987.7666025122483, 1046.5022612023945, 1108.7305239074883,
                                        1174.6590716696303, 1244.5079348883237, 1318.5102276514797, 1396.9129257320155,
                                        1479.9776908465376, 1567.981743926997, 1661.2187903197805, 1760.0, 1864.6550460723597,
                                        1975.533205024496, 2093.004522404789, 2217.4610478149766, 2349.31814333926, 2489.0158697766474,
                                        2637.02045530296, 2793.825851464031, 2959.955381693075, 3135.9634878539946, 3322.437580639561,
                                        3520.0, 3729.3100921447194, 3951.066410048992, 4186.009044809578};

const double Constants::TWO_PI = 2 * M_PI;
const double Constants::offset = 2;
const double Constants::white_key_width = 23.25;
const double Constants::black_key_width = 13.5;
const double Constants::black_key_length = 90;
const double Constants::white_key_length = 150;