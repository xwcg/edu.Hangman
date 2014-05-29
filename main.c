// Includes
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/* * * * * * * * * * * * * * * * * * * * * *
 * Klasse:  IFA 31
 * Name:    Julian Roerig & Michael Schwarz
 * Datum:   2014-05-29
 * Beschreibung:
 * Hangman... blabla
 * Quellenangaben: http://ascii.co.uk/art/hangman (Hangman Zeichnung)
 *                 http://www.peace-software.de/ckurs8.html (Arrays an Funktionen übergeben)
 *                 http://www.tutorials.at/c/09-arrays-strings.html (fgets (eingabe, 255, stdin);)
 * * * * * * * * * * * * * * * * * * * * * */

int Grafik (int i, int leicht, char name[])
{

    if (i == 0)      /*leere Fläche*/
    {
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
    }
    else if (i == 1) /*Hügel*/
    {
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf("      _________________________         \n");
        printf("     /                         \\       \n");
        printf("    /                           \\      \n");
        printf("   /                             \\     \n");
        printf("  /                               \\    \n");
        printf(" /                                 \\   \n");
        printf("/                                   \\  \n");
    }
    else if (i == 2) /*Hügel, Stamm*/
    {
        printf("       _                                \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      |_|______________________         \n");
        printf("     /                         \\       \n");
        printf("    /                           \\      \n");
        printf("   /                             \\     \n");
        printf("  /                               \\    \n");
        printf(" /                                 \\   \n");
        printf("/                                   \\  \n");
    }
    else if (i == 3) /*Hügel, Stamm, Balken*/
    {
        printf("       ________________________         \n");
        printf("      |  ______________________|        \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      |_|______________________         \n");
        printf("     /                         \\       \n");
        printf("    /                           \\      \n");
        printf("   /                             \\     \n");
        printf("  /                               \\    \n");
        printf(" /                                 \\   \n");
        printf("/                                   \\  \n");
    }
    else if (i == 4) /*Hügel, Stamm, Balken, Stütze*/
    {
        printf("       ________________________         \n");
        printf("      |  ______________________|        \n");
        printf("      | | / /                           \n");
        printf("      | |/ /                            \n");
        printf("      | | /                             \n");
        printf("      | |/                              \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      |_|______________________         \n");
        printf("     /                         \\       \n");
        printf("    /                           \\      \n");
        printf("   /                             \\     \n");
        printf("  /                               \\    \n");
        printf(" /                                 \\   \n");
        printf("/                                   \\  \n");
    }
    else if (i == 5) /*Hügel, Stamm, Balken, Stütze, Fußstütze1*/
    {
        printf("       ________________________         \n");
        printf("      |  ______________________|        \n");
        printf("      | | / /                           \n");
        printf("      | |/ /                            \n");
        printf("      | | /                             \n");
        printf("      | |/                              \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                    _          \n");
        printf("      | |                   | |         \n");
        printf("      | |                   | |         \n");
        printf("      | |                   | |         \n");
        printf("      | |                   | |         \n");
        printf("      |_|___________________|_|         \n");
        printf("     /                         \\       \n");
        printf("    /                           \\      \n");
        printf("   /                             \\     \n");
        printf("  /                               \\    \n");
        printf(" /                                 \\   \n");
        printf("/                                   \\  \n");
    }
    else if (i == 6) /*Hügel, Stamm, Balken, Stütze, Fußstütze1, Fußstütze2*/
    {
        printf("       ________________________         \n");
        printf("      |  ______________________|        \n");
        printf("      | | / /                           \n");
        printf("      | |/ /                            \n");
        printf("      | | /                             \n");
        printf("      | |/                              \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |_______ _________ ___          \n");
        printf("      | |_______|_________|___|         \n");
        printf("      | |                   | |         \n");
        printf("      | |                   | |         \n");
        printf("      | |                   | |         \n");
        printf("      | |                   | |         \n");
        printf("      |_|___________________|_|         \n");
        printf("     /                         \\       \n");
        printf("    /                           \\      \n");
        printf("   /                             \\     \n");
        printf("  /                               \\    \n");
        printf(" /                                 \\   \n");
        printf("/                                   \\  \n");
    }
    else if (i == 7) /*Hügel, Stamm, Balken, Stütze, Fußstütze1, Fußstütze2, Strick*/
    {
        printf("       ___________..___________         \n");
        printf("      |  __________))__________|        \n");
        printf("      | | / /      ||                   \n");
        printf("      | |/ /       ||                   \n");
        printf("      | | /        ||                   \n");
        printf("      | |/         ||                   \n");
        printf("      | |          ||                   \n");
        printf("      | |         /_ \\                 \n");
        printf("      | |        ||_| |                 \n");
        printf("      | |         \\__/                 \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |                               \n");
        printf("      | |_______ _________ ___          \n");
        printf("      | |_______|_________|___|         \n");
        printf("      | |                   | |         \n");
        printf("      | |                   | |         \n");
        printf("      | |                   | |         \n");
        printf("      | |                   | |         \n");
        printf("      |_|___________________|_|         \n");
        printf("     /                         \\       \n");
        printf("    /                           \\      \n");
        printf("   /                             \\     \n");
        printf("  /                               \\    \n");
        printf(" /                                 \\   \n");
        printf("/                                   \\  \n");
    }
    else if (i == 8) /*Hügel, Stamm, Balken, Stütze, Fußstütze1, Fußstütze2, Strick, Mann*/
    {
        printf("       ___________..___________         \n");
        printf("      |  __________))__________|        \n");
        printf("      | | / /      ||                   \n");
        printf("      | |/ /       ||                   \n");
        printf("      | | /        ||.-''.              \n");
        printf("      | |/   (')   |/  _  \ (')         \n");
        printf("      | |     \\\\   ||  `/,|//         \n");
        printf("      | |      \\\\  (\\`_.' //         \n");
        printf("      | |       \\\\.-`--'.//           \n");
        printf("      | |        \\_ . . _/             \n");
        printf("      | |          |   |                \n");
        printf("      | |          | . |                \n");
        printf("      | |          |   |                \n");
        printf("      | |          ||'||                \n");
        printf("      | |          || ||                \n");
        printf("      | |          || ||                \n");
        printf("      | |          || ||                \n");
        printf("      | |_______ _/_|_|_\\_ ___         \n");
        printf("      | |_______|_________|___|         \n");
        printf("      | |                   | |         \n");
        printf("      | |                   | |         \n");
        printf("      | |                   | |         \n");
        printf("      | |                   | |         \n");
        printf("      |_|___________________|_|         \n");
        printf("     /                         \\       \n");
        printf("    /                           \\      \n");
        printf("   /                             \\     \n");
        printf("  /                               \\    \n");
        printf(" /                                 \\   \n");
        printf("/                                   \\  \n");
    }
    else if (i == 9) /*Hügel, Stamm, Balken, Stütze, Fußstütze1, Fußstütze2, Strick, Mann, Klappe auf*/
    {
        printf("       ___________..___________         \n");
        printf("      |  __________))__________|        \n");
        printf("      | | / /      ||                   \n");
        printf("      | |/ /       ||                   \n");
        printf("      | | /        ||.-''.              \n");
        printf("      | |/   (')   |/  _  \ (')         \n");
        printf("      | |     \\\\   ||  `/,|//         \n");
        printf("      | |      \\\\  (\\`_.' //         \n");
        printf("      | |       \\\\.-`--'.//           \n");
        printf("      | |        \\_ . . _/             \n");
        printf("      | |          |   |                \n");
        printf("      | |          | . |                \n");
        printf("      | |          |   |                \n");
        printf("      | |          ||'||                \n");
        printf("      | |          || ||                \n");
        printf("      | |          || ||                \n");
        printf("      | |          || ||                \n");
        printf("      | |_______  / | | \\  ___         \n");
        printf("      | |_______|\\`-' `-' |___|        \n");
        printf("      | |       \\ \\         | |       \n");
        printf("      | |        \\ \\        | |       \n");
        printf("      | |         \\ \\       | |       \n");
        printf("      | |          `'       | |         \n");
        printf("      |_|___________________|_|         \n");
        printf("     /                         \\       \n");
        printf("    /                           \\      \n");
        printf("   /                             \\     \n");
        printf("  /                               \\    \n");
        printf(" /                                 \\   \n");
        printf("/                                   \\  \n");
    }
    else if (i == 10)/*Hügel, Stamm, Balken, Stütze, Fußstütze1, Fußstütze2, Strick, Mann, Klappe auf, Mann tot*/
    {
        printf("       ___________..___________         \n");
        printf("      |  __________))__________|        \n");
        printf("      | | / /      ||                   \n");
        printf("      | |/ /       ||                   \n");
        printf("      | | /        ||.-''.              \n");
        printf("      | |/         |/  _  \             \n");
        printf("      | |          ||  `/,|             \n");
        printf("      | |          (\\`_.'              \n");
        printf("      | |         .-`--'.               \n");
        printf("      | |        /_ . . _\\             \n");
        printf("      | |       // |   | \\\\           \n");
        printf("      | |      //  | . |  \\\\          \n");
        printf("      | |     ')   |   |   (`           \n");
        printf("      | |          ||'||                \n");
        printf("      | |          || ||                \n");
        printf("      | |          || ||                \n");
        printf("      | |          || ||                \n");
        printf("      | |_______  / | | \\  ___         \n");
        printf("      | |_______|\\`-' `-' |___|        \n");
        printf("      | |       \\ \\         | |       \n");
        printf("      | |        \\ \\        | |       \n");
        printf("      | |         \\ \\       | |       \n");
        printf("      | |          `'       | |         \n");
        printf("      |_|___________________|_|         \n");
        printf("     /                         \\       \n");
        printf("    /                           \\      \n");
        printf("   /                             \\     \n");
        printf("  /             GAMEOVER          \\    \n");
        printf(" /                                 \\   \n");
        printf("/                R.I.P              \\  \n");
        printf("                %s                      \n",name);
    }
    return 0;
}

int main()
{
    int wied =0, i=0;
    char name[20];
    printf("Geben Sie bitte Ihren Namen ein.\n");
    fgets (name, 20, stdin);

    do
    {
        for(i=0; i<11; i++)
        {
            system("cls");
            Grafik(i,1,name);
            system("pause");
        }
        printf("\n__________________________________________________________________________\n[1] = Wiederholen?\n");
        scanf("%i",&wied);

    }
    while(wied==1);


    return 0;
}
