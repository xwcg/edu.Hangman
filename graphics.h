#include <windows.h>

/*

    Faster console printing

    Keeps a buffer of the screen, as well as the last state (so you can revert)
    and prints only changed characters.

    Also allows to write to an exact location and set colors.

*/

#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

// Color definitions
#define G_COLOR_BLACK 0
#define G_COLOR_BLUE 1
#define G_COLOR_GREEN 2
#define G_COLOR_AQUA 3
#define G_COLOR_RED 4
#define G_COLOR_PURPLE 5
#define G_COLOR_YELLOW 6
#define G_COLOR_WHITE 7
#define G_COLOR_GRAY 8
#define G_COLOR_LBLUE 9
#define G_COLOR_LGREEN 10
#define G_COLOR_LAQUA 11
#define G_COLOR_LRED 12
#define G_COLOR_LPURPLE 13
#define G_COLOR_LYELLOW 14
#define G_COLOR_LWHITE 15

#define G_DEFAULT_HEIGHT 25
#define G_DEFAULT_WIDTH 80

// Black Magic
HANDLE _CONSOLE_HANDLE;
CONSOLE_SCREEN_BUFFER_INFO _CONSOLE_INFO;
WORD _CONSOLE_DEFAULTS;

// Current screen buffer
char G_ScreenBuffer[G_DEFAULT_WIDTH][G_DEFAULT_HEIGHT];
WORD G_ScreenBuffer_Color_FG[G_DEFAULT_WIDTH][G_DEFAULT_HEIGHT];
WORD G_ScreenBuffer_Color_BG[G_DEFAULT_WIDTH][G_DEFAULT_HEIGHT];

// Last Screen buffer
char G_ScreenBuffer_Last[G_DEFAULT_WIDTH][G_DEFAULT_HEIGHT];
WORD G_ScreenBuffer_Color_FG_Last[G_DEFAULT_WIDTH][G_DEFAULT_HEIGHT];
WORD G_ScreenBuffer_Color_BG_Last[G_DEFAULT_WIDTH][G_DEFAULT_HEIGHT];

WORD _g_current_fgcolor;
WORD _g_current_bgcolor;
int _g_current_x;
int _g_current_y;

// Prototypes
void G_Init();
void G_SetPosition(int x, int y);
void G_SetFGColor(WORD color);
void G_SetBGColor(WORD color);
int G_GetFGColor();
int G_GetBGColor();
int G_GetConsoleColor();
void G_ResetColors();
int G_GetHeight();
int G_GetWidth();

void Draw_RevertBuffer();
void Draw_FlushBuffer();
void Draw_SetPos(int x, int y);
void Draw_SetFGColor(WORD color);
void Draw_SetBGColor(WORD color);
void Draw_Write_Char(char e);
void Draw_Write(char *e);
void Draw_Write_Line(int line, char *e);
void Draw_Write_LineAt(int x, int y, char *e);
void Draw_Write_Line_Fill(int line, char *e);
void Draw_Clear();
void Draw_Fill();

#endif // GRAPHICS_H_INCLUDED
