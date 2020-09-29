# 8-bit Grand Piano

This is my dubious attempt to create a simple 8-bit piano in C++/SFML. 
Key feature of this piano is that it doesn't play prerecorded samples but calculates them during compilation.

## Features
- key highlight,
- polyphonic,
- sine and square waveforms,
- 88 keys,
- poor coding

## Some screenshots

![](https://cdn.discordapp.com/attachments/702987071849234636/758007077439537242/SoundSynthesizer_Screenshot_00.png)

![](https://cdn.discordapp.com/attachments/702987071849234636/758007080954101867/SoundSynthesizer_Screenshot_01.png)

![](https://cdn.discordapp.com/attachments/702987071849234636/758007082552131584/SoundSynthesizer_Screenshot_02.png)

![](https://cdn.discordapp.com/attachments/702987071849234636/760612422850707456/Zrzut_ekranu_z_2020-09-29_23-21-48.png)

## How to play
 
First, You need SFML library installed. If you're a Linux user, it can be simply done by entering your terminal via <b>Ctrl+Alt+T</b> and typing
```bash
sudo apt-get install libsfml-dev
```
You'll need the program itself, so don't forget to 
```
git clone https://github.com/Sztakler/sound-synthesizer
```

Then you can <b>make</b> and execute this program typing
```
make && ./sound-synthesizer
```
Otherwise simple
```
g++ src/*.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && ./a.out
```
should do the work.

### Important note
I strongly recommend not playing any other sounds on your computer while using this synthesizer nor recording anything.
It may lead to some serious issues with sampling <i>(earrape warning)</i>.
