#include <windows.h>
#include <stdio.h>

#include "graphics.h"
#include "game.h"
#include "menu.h"

/*

    Handles the menu

*/

int menu_is_setup = 0;

int menu_currentItem = MENU_START;
int menu_lastItem = 0;

char menu_title[MENU_TITLE_HEIGHT][MENU_TITLE_WIDTH];

void Menu_Setup()
{
    menu_currentItem = MENU_START;
    menu_lastItem = 0;

    // Clear buffer
    if(kbhit()) getch();

    if(menu_is_setup == 0)
    {
        /* Reference:
         _   _
        | | | |
        | |_| | __ _ _ __   __ _ _ __ ___   __ _ _ __
        |  _  |/ _` | '_ \ / _` | '_ ` _ \ / _` | '_ \
        | | | | (_| | | | | (_| | | | | | | (_| | | | |
        \_| |_/\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|
                            __/ |
                           |___/
        */

        strcpy(menu_title[0], " _   _");
        strcpy(menu_title[1], "| | | |");
        strcpy(menu_title[2], "| |_| | __ _ _ __   __ _ _ __ ___   __ _ _ __");
        strcpy(menu_title[3], "|  _  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\");
        strcpy(menu_title[4], "| | | | (_| | | | | (_| | | | | | | (_| | | | |");
        strcpy(menu_title[5], "\\_| |_/\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|");
        strcpy(menu_title[6], "                    __/ |");
        strcpy(menu_title[7], "                   |___/");

        menu_is_setup = 1;
    }
}

int Menu_Show()
{
    // Setup
    Menu_Setup();

    // Clear screen
    Draw_SetFGColor(G_COLOR_WHITE);
    Draw_SetBGColor(G_COLOR_BLACK);
    Draw_Fill();

    // No need to flush the buffer, let's draw the menu first
    //Draw_FlushBuffer();

    int showingMenu = 1;
    int keyPressed = -1;

    while(showingMenu)
    {
        if(kbhit())
        {
            // C is fucking weird
            /*
            Up = H
            down = P
            left = K
            right = M


            */

            // Get escape sequence
            keyPressed = getch();

            /*
            Draw_SetPos(0,0);
            char dbg[15];
            sprintf(dbg, "%d", keyPressed);
            Draw_Write(dbg);
            */

            // Arrow key escape sequence?
            if(keyPressed == 0 || keyPressed == 0xE0)
            {
                // Get key code
                keyPressed = getch();

                // And process the Actual key
                switch(keyPressed)
                {
                    // Arrow UP
                    case 'H':
                        Menu_Cycle(-1);
                        break;

                    // Arrow DOWN
                    case 'P':
                        Menu_Cycle(1);
                        break;

                    // Arrow RIGHT
                    case 'M':
                        break;

                    // Arrow LEFT
                    case 'K':
                        break;
                }
            }
            // Enter hit
            else if(keyPressed == 13)
            {
                showingMenu = 0;
            }
        }

        // Draw changes
        Menu_Draw();

        // Update screen
        Draw_FlushBuffer();
        Sleep(FRAMETIME);
    }

    return menu_currentItem;
}

void Menu_Cycle(int dir)
{
    // Change menu selection
    menu_currentItem += dir;

    // Boundary check
    if(menu_currentItem > MENU_QUIT)
        menu_currentItem = MENU_START;
    else if(menu_currentItem < MENU_START)
        menu_currentItem = MENU_QUIT;
}

void Menu_Draw()
{
    // if the menu selection changed
    if(menu_currentItem != menu_lastItem)
    {
        int i;

        // Title in green
        Draw_SetBGColor(G_COLOR_BLACK);
        Draw_SetFGColor(G_COLOR_GREEN);

        for(i = 0; i < MENU_TITLE_HEIGHT; i++)
        {
            Draw_Write_LineAt(5, i + 2, menu_title[i]);
        }

        // Menu items in white
        Draw_SetFGColor(G_COLOR_WHITE);

        Draw_Write_LineAt(7, 12, "   Start Game");
        Draw_Write_LineAt(7, 14, "   Statistics");
        Draw_Write_LineAt(7, 16, "   Quit");

        // Chevron in red
        Draw_SetFGColor(G_COLOR_RED);
        switch(menu_currentItem)
        {
            case MENU_START:
                Draw_Write_LineAt(7, 12, "->");
                break;
            case MENU_STATS:
                Draw_Write_LineAt(7, 14, "->");
                break;
            case MENU_QUIT:
                Draw_Write_LineAt(7, 16, "->");
                break;
        }

        // Hint in gray
        Draw_SetFGColor(G_COLOR_GRAY);
        Draw_Write_LineAt(1, G_DEFAULT_HEIGHT - 1, "Use [ARROW KEYS] to change selection, [ENTER] to confirm.");

        // and update values so we don't have any unnecessary redraws
        menu_lastItem = menu_currentItem;
    }
}
