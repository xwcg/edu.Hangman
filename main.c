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
 * °Ausgabe des Wortes ohne Herzen oder andere Sonderzeichen
 * °Bei richtig erratenem Wort goto einbinden (siehe Zeile 493)
 * °Statistik mit Name, Wort, Gewonnen/Verloren, Versuchen, Zeit in extra Datei schreiben und sortiert als Gesamtstatistik ausgeben
 * °Eingabe auf Länge prüfen, da auch "wo" / "to" ... als Treffer gezählt werden
 * °wenn ein wort eingeben wurde, auch auf Sonderzeichen prüfen
 * °Eine Hilfe mit einbauen
 * °Ä,Ü,Ö,ß in ae, ue, oe, ss umwandeln und eine meldung ausgeben
 * °ACHTUNG: AE, UE,OE können werden bisher nicht als einzelne Buchstaben gewertet.
 * °Bei der while-Schleife muss geratenWort überprüft werden, da sonst nicht überprüft wird, ob ein Wort schon doppelt geraten wurde
 * °Bei der while-Überprüfung eine Variable benutzen, welche aus ", " und $Eingabe besteht -> ist genauer
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
int Ausgabe(int i, int Reihenfolge, int error, char wort[100], char wortausgabe[100], char geraten[100], char geratenWort[500], char eingabe[100], char name [30], int treffer, int fehler, int gewonnen)
{

            system("cls");

    Grafik(fehler,0,name);

    if (i<=9)
    {
        printf("Das Wort lautet: %s\n",wortausgabe);
    }
    else
    {
        printf("Das Wort lautet: %s\n",wort);
    }
    printf("Bisher geratene Buchstaben: %s\n",geraten);
    printf("Bisher geratene Woerter: %s\n",geratenWort);
    if (i!=0)
    {
    printf("%i Treffer | %i Fehler | %i Versuch von 10 Versuchen\n",treffer,fehler, i);
    }
    if (i<=9)
    {printf("%i Versuch\n",i+1);
    }

    if (Reihenfolge==2)
    {
        if (strlen(eingabe)==1)
        {
           printf("Der eingegebene Buchstabe wurde schon geraten\n");
           printf("Geben Sie einen Buchstaben an, den Sie noch nicht geraten haben\n");
        }
        else
        {
           printf("Das eingegebene Wort wurde schon geraten\n");
           printf("Geben Sie ein Wort an, den Sie noch nicht geraten haben\n");
        }

        system("pause");
        system("cls");
    }

    if (Reihenfolge==3)
    {
        if (strlen(eingabe)==1)
        {
        printf("Kein zulaessiger Buchstabe.\n");
        printf("Probieren Sie es noch einmal\n");
        }
        else
        {
        printf("Kein zulaessiges Wort.\n");
        printf("Probieren Sie es noch einmal\n");
        }

        system("pause");
        system("cls");
    }

    if (Reihenfolge==4)
    {

    }

    if (Reihenfolge==5)
    {

    }

    if (Reihenfolge==6)
    {
printf("\n__________________________________________________________________________\n[1] = Wiederholen?\n");
    }

    if (Reihenfolge==7)
    {
        printf("Dies ist das gesuchte Wort\n");
        system("pause");
    }

    if (gewonnen ==1)
    {
        printf("Sie haben dieses Spiel erfolgreich abgeschlossen\n");
        i = 11;
    }

}
int main()
{
    int wied=0;
    do
    {
        int i=0, i2=0, i3=0, treffer=0, fehler=0, gewonnen=0, gewonnenWort, error;
        char wort[100]="Wort", wortausgabe[100]="", geraten[100]="", geratenWort[500]="", eingabe[100], name[30]="Julian Rörig";
        //wandlet das Wort in Kleinbuchstaben um
        for (i2 = 0; wort[i2]; i2++)
        {
            wort[i2] = tolower(wort[i2]);
        }

//10 Versuche bis Game Over
        for(i=0; i<10; i++)

        {



//wiederhole solange, bis ein Buchstabe angegeben wird, der noch nicht geraten wurde, und ein Buchstabe ist
            do
            {
Ausgabe(i,1,error,wort,wortausgabe,geraten,geratenWort,eingabe,name,treffer,fehler,gewonnen);
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
                        error =1;
                        Ausgabe(i,2,error,wort,wortausgabe,geraten,geratenWort,eingabe,name,treffer,fehler,gewonnen);


//Erstes Zeichen ist kein Buchstabe
                    }
                    else if(isalpha(eingabe[0])==0)
                    {
                        error =1;
                        Ausgabe(i,3,error,wort,wortausgabe,geraten,geratenWort,eingabe,name,treffer,fehler,gewonnen);

                    }
                    else
                    {
                        error = 0;
                    }




                }

            }
            while(isalpha(eingabe[0])==0 || strstr(geraten, eingabe));

//Buchstabe ist im Wort enthalten
//Zählt die richtigen Treffer
            if (strlen(eingabe)==1 && strstr(wort,eingabe))
            {
                treffer= treffer + 1;
                Ausgabe(i,0,error,wort,wortausgabe,geraten,geratenWort,eingabe,name,treffer,fehler,gewonnen);

            }
            else if (strlen(eingabe)==strlen(wort) && strcmp(wort,eingabe)==0)
            {
                treffer=treffer+1;
                Ausgabe(i,7,error,wort,wortausgabe,geraten,geratenWort,eingabe,name,treffer,fehler,gewonnen);
                gewonnen=1;
            }
//Buchstabe ist nicht im Wort enthalten
//Zählt die Fehlversuche

            else
            {
                fehler= fehler + 1;
                Ausgabe(i,0,error,wort,wortausgabe,geraten,geratenWort,eingabe,name,treffer,fehler,gewonnen);


            }

//schreibt die Eingaben hintereinander kommagetrennt in $geraten
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
                //schreibt die geratenen Worte kommagetrennt in $geratenWort
                if (strlen(geratenWort) != 0)
                {
                    strcat(geratenWort,", ");
                }
                strcat(geratenWort, eingabe);
            }


//Gibt die zu lösenden Buchstaben aus
            if (strlen(eingabe)==1)
            {
                //geht jeden Buchstaben in $wort durch und schreibt wenn die Eingabe einem Buchstaben entspricht, diesen in $wortausgabe, ansonsten "_"
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



            if (strcmp(wort, wortausgabe)==0)
            {
                gewonnen=1;
            }

            if (strcmp(wort, eingabe)==0)
            {
                gewonnen=1;
            }

            Ausgabe(i,0,error,wort,wortausgabe,geraten,geratenWort,eingabe,name,treffer,fehler,gewonnen);



        }



         Ausgabe(i,6,error,wort,wortausgabe,geraten,geratenWort,eingabe,name,treffer,fehler,gewonnen);
        scanf("%i",&wied);
        //setzt die eingaben wieder auf den Standard zurück

    }
    while(wied==1);
    return 0;
}
