#include "graphics.h"
#include "game_graphics.h"
#include <windows.h>

// Writes the given string (e) letter by letter at (line)
void GG_TypePrint(int line, char *e)
{
	int i, len;
	len = strlen(e);
	for(i = 0; i < len; i++)
	{
		Draw_SetPos(i, line);
		Draw_Write_Char(e[i]);
		Draw_FlushBuffer();
		Sleep(100);
		if(_kbhit()) break;
	}
}

// Writes the given string (e) at position (x) and (y) letter by letter at (speed)
void GG_TypePrintAt(int x, int y, char *e, int speed)
{
	int i, len;
	len = strlen(e);
	for(i = 0; i < len; i++)
	{
		Draw_SetPos(x + i, y);
		Draw_Write_Char(e[i]);
		Draw_FlushBuffer();
		Sleep(speed);
		if(_kbhit()) break;
	}
}


// Animations

void PlayIntro()
{
	while(1)
	{
		Draw_SetBGColor(G_COLOR_BLACK);
		Draw_SetFGColor(G_COLOR_GRAY);

		Draw_Write_Line(G_DEFAULT_HEIGHT -1, "Press any key to skip...");

		if(PLAY_INTRO_PART1)
		{
			GG_TypePrint(0, "Starting WarOS 1.0 ...");
			if(_kbhit()) break;
			Sleep(1000);
			if(_kbhit()) break;
			GG_TypePrint(1, "System Initialized");
			if(_kbhit()) break;

			Draw_SetFGColor(G_COLOR_GREEN);
			GG_TypePrint(3, "Would you like to play a game?");
			if(_kbhit()) break;

			Sleep(1000);
			if(_kbhit()) break;
			Draw_SetFGColor(G_COLOR_WHITE);
			GG_TypePrint(4, "Yes");
			if(_kbhit()) break;

			Sleep(500);
			if(_kbhit()) break;
			Draw_SetFGColor(G_COLOR_GREEN);
			GG_TypePrint(5, "What game do you want to play?");
			if(_kbhit()) break;

			Sleep(1000);
			if(_kbhit()) break;
			Draw_SetFGColor(G_COLOR_WHITE);
			GG_TypePrint(6, "What games do you have?");
			if(_kbhit()) break;

			Sleep(500);
			if(_kbhit()) break;
			Draw_SetFGColor(G_COLOR_GREEN);
			GG_TypePrint(7, "Just hangman actually. They deleted the Wargame program. :(");
			if(_kbhit()) break;

			Sleep(1000);
			if(_kbhit()) break;
			Draw_SetFGColor(G_COLOR_WHITE);
			GG_TypePrint(8, "Okay then. Let's Play Hangman!");
			if(_kbhit()) break;

			Sleep(500);
			if(_kbhit()) break;
			Draw_SetFGColor(G_COLOR_GREEN);
			GG_TypePrint(9, "Episode 1");
			if(_kbhit()) break;

			Sleep(1000);
			if(_kbhit()) break;
			Draw_SetFGColor(G_COLOR_WHITE);
			GG_TypePrint(10, "Don't forget to like, share and subscribe!");
			if(_kbhit()) break;

			Sleep(500);
			if(_kbhit()) break;
			Draw_SetFGColor(G_COLOR_GREEN);
			GG_TypePrint(11, "It'll help the channel!");
			if(_kbhit()) break;

			Sleep(1500);
		}

		Draw_SetBGColor(G_COLOR_BLACK);
		Draw_SetFGColor(G_COLOR_GRAY);
		Draw_Clear();
		Draw_FlushBuffer();

		int centerX = G_DEFAULT_WIDTH / 2;
		int centerY = G_DEFAULT_HEIGHT / 2;
		int tempY;
		int tempX;

		if(PLAY_INTRO_PART2)
		{

			Draw_SetFGColor(G_COLOR_BLACK);

            // fancy fade in effect
            int i;

            for(i = 0; i < 3; i++)
            {
                if(i == 0)
                    Draw_SetBGColor(G_COLOR_GRAY);
                else if(i == 1)
                    Draw_SetBGColor(G_COLOR_WHITE);
                else
                    Draw_SetBGColor(G_COLOR_LWHITE);

                for(tempY = 0; tempY < G_DEFAULT_HEIGHT; tempY++)
                {
                    for(tempX = 0; tempX < G_DEFAULT_WIDTH / 2; tempX++)
                    {
                        Draw_SetPos(tempX, tempY);
                        Draw_Write_Char(' ');

                        Draw_SetPos((G_DEFAULT_WIDTH - 1) - tempX, tempY);
                        Draw_Write_Char(' ');

                        Draw_FlushBuffer();
                        if(_kbhit()) break;
                        Sleep(1);
                        if(_kbhit()) break;
                    }
                    if(_kbhit()) break;
                }
                Draw_Write_Line(G_DEFAULT_HEIGHT -1, "Press any key to skip...");
            }

			Draw_Write_Line(G_DEFAULT_HEIGHT -1, "Press any key to skip...");
			Draw_FlushBuffer();

			if(_kbhit()) break;
            Sleep(500);
            if(_kbhit()) break;

/*
$$$$$$\ $$$$$$$$\  $$$$$$\         $$$$$$\    $$\
\_$$  _|$$  _____|$$  __$$\       $$ ___$$\ $$$$ |
  $$ |  $$ |      $$ /  $$ |      \_/   $$ |\_$$ |
  $$ |  $$$$$\    $$$$$$$$ |        $$$$$ /   $$ |
  $$ |  $$  __|   $$  __$$ |        \___$$\   $$ |
  $$ |  $$ |      $$ |  $$ |      $$\   $$ |  $$ |
$$$$$$\ $$ |      $$ |  $$ |      \$$$$$$  |$$$$$$\
\______|\__|      \__|  \__|       \______/ \______|
*/

            char ifa_logo[10][53];

			strcpy(ifa_logo[0], "$$$$$$\\ $$$$$$$$\\  $$$$$$\\         $$$$$$\\    $$\\");
			strcpy(ifa_logo[1], "\\_$$  _|$$  _____|$$  __$$\\       $$ ___$$\\ $$$$ |");
			strcpy(ifa_logo[2], "  $$ |  $$ |      $$ /  $$ |      \\_/   $$ |\\_$$ |");
			strcpy(ifa_logo[3], "  $$ |  $$$$$\\    $$$$$$$$ |        $$$$$ /   $$ |");
			strcpy(ifa_logo[4], "  $$ |  $$  __|   $$  __$$ |        \\___$$\\   $$ |");
			strcpy(ifa_logo[5], "  $$ |  $$ |      $$ |  $$ |      $$\\   $$ |  $$ |");
			strcpy(ifa_logo[6], "$$$$$$\\ $$ |      $$ |  $$ |      \\$$$$$$  |$$$$$$\\");
			strcpy(ifa_logo[7], "\\______|\\__|      \\__|  \\__|       \\______/ \\______|");
			strcpy(ifa_logo[8], "");
			strcpy(ifa_logo[9], "                      PRESENTS                  ");

			// Show Class Logo
			for(tempY = 0; tempY < 10; tempY++)
            {
                Draw_Write_LineAt(centerX - (53 / 2), (centerY - 5) + tempY, ifa_logo[tempY]);
                Draw_FlushBuffer();

                if(_kbhit()) break;
                Sleep(100);
                if(_kbhit()) break;
            }

			if(_kbhit()) break;
			Sleep(2000);
			if(_kbhit()) break;

			// Hide class logo
			Draw_SetBGColor(G_COLOR_BLACK);

			// fancy fade out effect
			for(tempY = 0; tempY < G_DEFAULT_HEIGHT; tempY++)
			{
				for(tempX = 0; tempX < G_DEFAULT_WIDTH / 2; tempX++)
				{
					Draw_SetPos(tempX, tempY);
					Draw_Write_Char(' ');

					Draw_SetPos((G_DEFAULT_WIDTH - 1) - tempX, tempY);
					Draw_Write_Char(' ');

					Draw_FlushBuffer();
                    if(_kbhit()) break;
					Sleep(2);
                    if(_kbhit()) break;
				}
                if(_kbhit()) break;
			}
			if(_kbhit()) break;
		}

		if(PLAY_INTRO_PART3)
		{
			Draw_SetBGColor(G_COLOR_BLACK);
			Draw_SetFGColor(G_COLOR_GRAY);

			Draw_Write_Line(G_DEFAULT_HEIGHT -1, "Press any key to skip...");
			Draw_FlushBuffer();

			Draw_SetBGColor(G_COLOR_BLACK);
			Draw_SetFGColor(G_COLOR_WHITE);

			char production_1[] = "A";
			char production_2[] = "MICHAEL SCHWARZ";
			char production_3[] = "PRODUCTION";

			GG_TypePrintAt(centerX, centerY - 1, production_1, 100);
			if(_kbhit()) break;
			GG_TypePrintAt(centerX - (strlen(production_2) / 2), centerY, production_2, 100);
			if(_kbhit()) break;
			GG_TypePrintAt(centerX - (strlen(production_3) / 2), centerY + 1, production_3, 100);
			if(_kbhit()) break;

			Sleep(2000);
			if(_kbhit()) break;
		}

		if(PLAY_INTRO_PART4)
		{
			Draw_SetBGColor(G_COLOR_BLACK);
			Draw_SetFGColor(G_COLOR_GRAY);
			Draw_Clear();
			Draw_Write_Line(G_DEFAULT_HEIGHT -1, "Press any key to skip...");
			Draw_FlushBuffer();

			char game_title[] = "H   A   N   G   M   A   N";
			Draw_SetFGColor(G_COLOR_WHITE);
			if(_kbhit()) break;
			GG_TypePrintAt(centerX - (strlen(game_title) / 2), centerY, game_title, 100);
			if(_kbhit()) break;
			Sleep(2000);

			Draw_SetBGColor(G_COLOR_RED);
			Draw_SetFGColor(G_COLOR_BLACK);

			for(tempX = 0; tempX < G_DEFAULT_WIDTH; tempX++)
			{
				for(tempY = 0; tempY < G_DEFAULT_HEIGHT; tempY++)
				{
					Draw_SetPos(tempX, tempY);
					Draw_Write_Char(' ');
                    if(_kbhit()) break;
				}
                if(_kbhit()) break;
			}

			Draw_SetPos(centerX - (strlen(game_title) / 2), centerY);
			Draw_Write(game_title);
			Draw_FlushBuffer();
			G_SetPosition(0,0);

			if(_kbhit()) break;
			Sleep(2000);
		}

		break;
	}

	// Clear screen
	Draw_SetBGColor(G_COLOR_BLACK);
	Draw_SetFGColor(G_COLOR_GRAY);
	Draw_Clear();
	Draw_FlushBuffer();
}
