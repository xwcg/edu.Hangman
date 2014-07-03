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
			Draw_SetBGColor(G_COLOR_BLACK);
			Draw_SetFGColor(G_COLOR_GRAY);

			Draw_Write_Line(G_DEFAULT_HEIGHT -1, "Press any key to skip...");
			Draw_FlushBuffer();

			Draw_SetBGColor(G_COLOR_WHITE);
			Draw_SetFGColor(G_COLOR_BLACK);

			char ifa_line1[] = "                     00 000000 000000   000000   000000                         ";
			char ifa_line2[] = "                     00 00     00  00       00  00   00                         ";
			char ifa_line3[] = "                     00 0000   000000   00000        00                         ";
			char ifa_line4[] = "                     00 00     00  00       00       00                         ";
			char ifa_line5[] = "                     00 00     00  00       00       00                         ";
			char ifa_line6[] = "                     00 00     00  00   00000        00                         ";
			char ifa_line7[] = "                                                                                ";
			char ifa_line8[] = "                                 PRESENTS                                       ";

			// Show Class Logo
			Draw_Write_Line_Fill(centerY - 5, "");
			Draw_FlushBuffer();
			if(_kbhit()) break;
			Sleep(100);
			if(_kbhit()) break;
			Draw_Write_Line_Fill(centerY - 4, "");
			Draw_FlushBuffer();
			if(_kbhit()) break;
			Sleep(100);
			if(_kbhit()) break;
			Draw_Write_Line_Fill(centerY - 3, ifa_line1);
			Draw_FlushBuffer();
			if(_kbhit()) break;
			Sleep(100);
			if(_kbhit()) break;
			Draw_Write_Line_Fill(centerY - 2, ifa_line2);
			Draw_FlushBuffer();
			if(_kbhit()) break;
			Sleep(100);
			if(_kbhit()) break;
			Draw_Write_Line_Fill(centerY - 1, ifa_line3);
			Draw_FlushBuffer();
			if(_kbhit()) break;
			Sleep(100);
			if(_kbhit()) break;
			Draw_Write_Line_Fill(centerY + 0, ifa_line4);
			Draw_FlushBuffer();
			if(_kbhit()) break;
			Sleep(100);
			if(_kbhit()) break;
			Draw_Write_Line_Fill(centerY + 1, ifa_line5);
			Draw_FlushBuffer();
			if(_kbhit()) break;
			Sleep(100);
			if(_kbhit()) break;
			Draw_Write_Line_Fill(centerY + 2, ifa_line6);
			Draw_FlushBuffer();
			if(_kbhit()) break;
			Sleep(100);
			if(_kbhit()) break;
			Draw_Write_Line_Fill(centerY + 3, ifa_line7);
			Draw_FlushBuffer();
			if(_kbhit()) break;
			Sleep(100);
			if(_kbhit()) break;
			Draw_Write_Line_Fill(centerY + 4, ifa_line8);
			Draw_FlushBuffer();
			if(_kbhit()) break;
			Sleep(100);
			if(_kbhit()) break;
			Draw_Write_Line_Fill(centerY + 5, "");
			Draw_FlushBuffer();
			if(_kbhit()) break;
			Sleep(100);
			if(_kbhit()) break;
			Draw_Write_Line_Fill(centerY + 6, "");
			Draw_FlushBuffer();

			if(_kbhit()) break;
			Sleep(2000);
			if(_kbhit()) break;

			// Hide class logo
			Draw_SetBGColor(G_COLOR_BLACK);

			// fancy fade out effect
			for(tempY = centerY - 5; tempY <= centerY + 6; tempY++)
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

			GG_TypePrintAt(centerX - 1, centerY - 1, production_1, 100);
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