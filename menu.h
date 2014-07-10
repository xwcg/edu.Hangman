#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#define MENU_START 1
#define MENU_STATS 2
#define MENU_QUIT 3

#define MENU_TITLE_HEIGHT 8
#define MENU_TITLE_WIDTH 48

void Menu_Setup();
int Menu_Show();
void Menu_Cycle();
void Menu_Draw();

void Stop();

#endif // MENU_H_INCLUDED
