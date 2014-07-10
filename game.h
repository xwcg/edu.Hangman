#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

// Game fps; Draw the screen 30 times per second
// i.e. sleep time = 1000/FPS
#define FPS 30
#define FRAMETIME 1000 / FPS

#define TIME_SECOND 1000
#define TIME_MINUTE TIME_SECOND * 60

#define TIME_EASY TIME_MINUTE * 3
#define TIME_NORMAL TIME_MINUTE + TIME_SECOND * 30
#define TIME_HARD TIME_MINUTE
#define TIME_LEGENDARY TIME_SECOND * 30

#define DIFF_EASY 1
#define DIFF_NORMAL 2
#define DIFF_HARD 3
#define DIFF_LEGENDARY 4

#define MENU_D_EASY 1
#define MENU_D_NORMAL 2
#define MENU_D_HARD 3
#define MENU_D_LEGENDARY 4
#define MENU_D_BACK 5

#define MENU_D_TITLE_HEIGHT 8
#define MENU_D_TITLE_WIDTH 43

void Stats_Show();

void Difficulty_Setup();
int Difficulty_Show();
void Difficulty_Cycle();
void Difficulty_Draw();

void Game_Run();
void Game_LoadWord(int difficulty);



#endif // GAME_H_INCLUDED
