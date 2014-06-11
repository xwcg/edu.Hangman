// Includes
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>
#include "graphics.h"

/* * * * * * * * * * * * * * * * * * * * * *
 * Klasse:  IFA 31
 * Name:    Julian Roerig & Michael Schwarz
 * Datum:   2014-06-06
 * Beschreibung:
 * Hangman... blabla
 *
 * Muss ergänzt werden:
 * °Wort zufällig aus einer txt lesen
 * °Bei richtig erratenem Wort goto einbinden (siehe Zeile 493)
 * °Statistik mit Name, Wort, Gewonnen/Verloren, Versuchen, Zeit in extra Datei schreiben und sortiert als Gesamtstatistik ausgeben
 * °Eingabe auf Länge prüfen, da auch "wo" / "to" ... als Treffer gezählt werden
 * °wenn ein wort eingeben wurde, auch auf Sonderzeichen prüfen
 * °Eine Hilfe mit einbauen
 * °Ä,Ü,Ö,ß in ae, ue, oe, ss umwandeln und eine meldung ausgeben
 * °ACHTUNG: AE, UE,OE können werden bisher nicht als einzelne Buchstaben gewertet.
 * °Bei der while-Schleife muss geratenWort überprüft werden, da sonst nicht überprüft wird, ob ein Wort schon doppelt geraten wurde -> halb fertig: wenn beim 1. Versuch ein Wort geraten wird, kann es aufgrund des fehlenden Kommas nochmal geraten werden
 * °Bei der while-Überprüfung eine Variable benutzen, welche aus ", " und $Eingabe besteht -> ist genauer
 * °Durchlauf von 10 Versuchen auf 10 Fehlversuche limitieren
 * °Ein Spielende bei Gewonnen einbauen
 *
 * Quellenangaben: http://ascii.co.uk/art/hangman (Hangman Zeichnung)
 *                 http://www.peace-software.de/ckurs8.html (Arrays an Funktionen übergeben)
 *                 http://www.tutorials.at/c/09-arrays-strings.html (fgets (eingabe, 255, stdin);)
 *                 http://www.c-howto.de/ (Wissenswertes über Stringfunktionen)
 *                 http://www.roseindia.net/c-tutorials/c-string-lowercase.shtml (String in Kleinbuchstaben umschreiben)
 * * * * * * * * * * * * * * * * * * * * * */

#define TYPE_TIME 100;

#define PLAY_INTRO_PART1 0
#define PLAY_INTRO_PART2 1

int Anykey()
{

}

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

        int centerX = G_DEFAULT_WIDTH / 2;
        int centerY = G_DEFAULT_HEIGHT / 2;

        if(PLAY_INTRO_PART2)
        {

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
            Sleep(100);
            Draw_Write_Line_Fill(centerY - 4, "");
            Draw_FlushBuffer();
            Sleep(100);
            Draw_Write_Line_Fill(centerY - 3, ifa_line1);
            Draw_FlushBuffer();
            Sleep(100);
            Draw_Write_Line_Fill(centerY - 2, ifa_line2);
            Draw_FlushBuffer();
            Sleep(100);
            Draw_Write_Line_Fill(centerY - 1, ifa_line3);
            Draw_FlushBuffer();
            Sleep(100);
            Draw_Write_Line_Fill(centerY + 0, ifa_line4);
            Draw_FlushBuffer();
            Sleep(100);
            Draw_Write_Line_Fill(centerY + 1, ifa_line5);
            Draw_FlushBuffer();
            Sleep(100);
            Draw_Write_Line_Fill(centerY + 2, ifa_line6);
            Draw_FlushBuffer();
            Sleep(100);
            Draw_Write_Line_Fill(centerY + 3, ifa_line7);
            Draw_FlushBuffer();
            Sleep(100);
            Draw_Write_Line_Fill(centerY + 4, ifa_line8);
            Draw_FlushBuffer();
            Sleep(100);
            Draw_Write_Line_Fill(centerY + 5, "");
            Draw_FlushBuffer();
            Sleep(100);
            Draw_Write_Line_Fill(centerY + 6, "");
            Draw_FlushBuffer();

            Sleep(2000);

            // Hide class logo
            Draw_SetBGColor(G_COLOR_BLACK);

            int tempY;

            for(tempY = centerY - 5; tempY <= centerY + 6; tempY++)
            {
                Draw_Write_Line_Fill(tempY, "");
                Draw_FlushBuffer();
                Sleep(100);
            }
        }

        break;
    }

    // Clear screen
    Draw_SetBGColor(G_COLOR_BLACK);
    Draw_SetFGColor(G_COLOR_GRAY);
    Draw_Clear();
    Draw_FlushBuffer();
}

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

int main()
{
    G_Init();
    Draw_FlushBuffer();

    PlayIntro();
}


void UpdateGraphics()
{

}
