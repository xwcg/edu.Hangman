// Includes
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

/* * * * * * * * * * * * * * * * * * * * * *
 * Klasse:  IFA 31
 * Name:    Julian Roerig & Michael Schwarz
 * Datum:   2014-05-31
 * Beschreibung:
 * Hangman... blabla
 *
 * Muss ergänzt werden:
 * °Wort zufällig aus einer txt lesen
 * °Ausgabe des Wortes ohne Herzen
 * °Bei richtig erratenem Wort goto einbinden (siehe Zeile 493)
 * °Statistik mit Name, Wort, Gewonnen/Verloren, Versuchen, Zeit in extra Datei schreiben und sortiert als Gesamtstatistik ausgeben
 * °Eingabe auf Länge prüfen, da auch "wo" / "to" ... als Treffer gezählt werden
 *
 * Quellenangaben: http://ascii.co.uk/art/hangman (Hangman Zeichnung)
 *                 http://www.peace-software.de/ckurs8.html (Arrays an Funktionen übergeben)
 *                 http://www.tutorials.at/c/09-arrays-strings.html (fgets (eingabe, 255, stdin);)
 *                 http://www.c-howto.de/ (Wissenswertes über Stringfunktionen)
 *                 http://www.roseindia.net/c-tutorials/c-string-lowercase.shtml (String in Kleinbuchstaben umschreiben)
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
int GrafikTesten()
{
    //durchläuft die Grafischen Bilder des Hangman, damit man prüfen kann, ob die Darstellung gut ist
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
int FunktionenKennenlernen()
{
    //dient lediglich zu Übungszwecken und hat nichts mit dem eigentlichen Programm zu tun
    do
    {
        char string[10];
        char needle[10];
        scanf("%s",&string);
        scanf("%s",&needle);

        if(strstr(string, needle))
        {
            printf("String enthaelt %s\n",needle);;
        }


    }
    while(1);
    return 0;
}
int main()
{
    int wied=0;
    do
    {
        int i=0, i2=0, i3=0, treffer=0, fehler=0, gewonnen=0;
        char wort[100]="Wort", wortausgabe[100]="", geraten[100]="", geratenWort[500]="", eingabe[100], name[30]="Julian Rörig";
        //wandlet das Wort in Kleinbuchstaben um
        for (i2 = 0; wort[i2]; i2++)
        {
            wort[i2] = tolower(wort[i2]);
        }


        for(i=1; i<11; i++)

        {
            printf("Bisher geratene Buchstaben: %s\n",geraten);
            printf("Bisher geratene Woerter: %s\n",geratenWort);
            printf("%i Versuch\n",i);

//wiederhole solange, bis ein Buchstabe angegeben wird, der noch nicht geraten wurde, und ein Buchstabe ist
            do
            {

                scanf("%s",eingabe);
                //wandelt die Eingabe in Kleinbuchstaben um
                for (i2 = 0; eingabe[i2]; i2++)
                {
                    eingabe[i2] = tolower(eingabe[i2]);
                }

//es wurde nur ein Buchstabe eingegeben
                if(strlen(eingabe)==1)
                {
//Buchstabe wurde schon geraten
                    if(strstr(geraten, eingabe))
                    {
                        printf("Der gesuchte Buchstabe wurde schon geraten\n");
                        printf("Geben sie einen Buchstaben an, den sie noch nicht geraten haben\n");

//Erstes Zeichen ist kein Buchstabe
                    }
                    else if(isalpha(eingabe[0])==0)
                    {
                        printf("Bei der Eingabe handelt es sich um keinen Buchstaben.\n");
                        printf("Probieren Sie es noch einmal\n");
                    }




//es wurde mehr als ein Buchstabe eingegeben
//wird nicht benötigt, da unten das ganze Wort überprüft wird und so die Ausgabe erfolgt (siehe:   if (wortausgabe[i3] == wort [i3])  )          }
                    /*    else
                         {

                             if (eingabe == wort)
                             {
                                 printf("Sie haben das Wort erraten\n");
                                 //goto
                             }
                             else
                             {
                                 printf("Dies war nicht das zu erratene Wort\n");
                             }


                         }
                    */
                }
            }
            while(isalpha(eingabe[0])==0 || strstr(geraten, eingabe));

//Buchstabe ist im Wort enthalten
            if (strstr(wort,eingabe))
            {
                treffer= treffer + 1;
                printf("Bisher %i Treffer bei %i Versuchen\n",treffer, i);

//Buchstabe ist nicht im Wort enthalten
            }
            else
            {
                fehler= fehler + 1;
                printf("Bisher %i Fehler bei %i Versuchen\n",fehler, i);
            }

//schreibt die eingaben hintereinander kommagetrennt in $geraten
            //wenn es sich um den ersten Versuch handelt, lasse das Komma weg


            if (strlen(eingabe)==1)
            {
                if (strlen(geraten) != 0)
                {
                    strcat(geraten,", ");
                }
                strcat(geraten, eingabe);

            }
            else
            {
                if (strlen(geratenWort) != 0)
                {
                    strcat(geratenWort,", ");
                }
                strcat(geratenWort, eingabe);
            }

//Gibt die zu lösenden Buchstaben aus

            if (strlen(eingabe)==1)
            {
                for(i3=0; i3 < strlen(wort); i3++)
                {
                    if (wort[i3] == eingabe[0])
                    {
                        wortausgabe[i3] = eingabe [0];
                    }
                    else if (wort[i3] != eingabe[0] && isalpha(wortausgabe[i3])==0 )
                    {
                        wortausgabe[i3] = "_";

                    }

                }
            }

            printf("Das Wort lautet: %s\n",wortausgabe);

            if (strcmp(wort, wortausgabe)==0)
            {
                gewonnen=1;
            }


            if (gewonnen == 1)
            {
                printf("Sie haben gewonnen!\n");
            }


            Grafik(fehler,1,name);
            system("pause");
            system("cls");
        }



        printf("\n__________________________________________________________________________\n[1] = Wiederholen?\n");
        scanf("%i",&wied);
        //setzt die eingaben wieder auf den Standard zurück

    }
    while(wied==1);
    return 0;
}
