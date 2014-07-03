#ifndef GAME_GRAPHICS_H_INCLUDED
#define GAME_GRAPHICS_H_INCLUDED

#define PLAY_INTRO_PART1 0
#define PLAY_INTRO_PART2 1
#define PLAY_INTRO_PART3 1
#define PLAY_INTRO_PART4 1

#define TYPE_TIME 100

// Game graphics functions
void GG_TypePrint(int line, char *e);
void GG_TypePrintAt(int x, int y, char *e, int speed);

// Animations
void PlayIntro();


#endif // GAME_GRAPHICS_H_INCLUDED
