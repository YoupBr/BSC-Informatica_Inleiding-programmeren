/* Naam: Y. Bronkhorst
   UvAnetID: 17006813
   Studie: BSc Informatica

   Dit programma bevat verschillende functies waarmee de Collatz-reeks
   onderzocht kan worden.
*/

// Hier worden de library's geïmporteerd.

#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * In deze functie wordt er bepaald of het gegeven getal even of oneven is, waarna het volgende Collatz-getal wordt berekend.
 * Wanneer de input ongeldig is (negatief) wordt er '-1' als return gegeven.
 * Getal: het (volgende) getal in de reeks die berekend moet worden.
 * Input: Getal in de reeks, door input van de gebruiker of bepaald door collatz_toon_reeks functie.
 * Output: Return waarde, die wordt geprint in collatz_info.
*/

int collatz_opvolger(int getal) {

    if (getal > 0) {

        if (getal%2 == 0) {
            return getal/2;
        }

        else {
            return getal*3 + 1;
        }
    }

    // Getal < 0
    else {
        return -1;
    }
}

/*
 * In deze functie wordt de stoptijd van de collatz reeks bepaald.
 * Het aantal getallen wordt opgeslagen in 'reeks', die uiteindelijk de hoeveelheid getallen als return geeft.
 * Dit wordt gedaan zolang de reeks geldig (> 0) is, en totdat de reeks gelijk is aan 1 (eind).
 * In deze functie wordt ook een waarde teruggegeven als de reeks niet geldig is (< 0): -1.
 * reeks = de waarde van het laatste getal van de reeks.
 * Output: Return waarde, die het aantal getallen in de gegeven reeks geeft en afgedrukt wordt in _info.
*/

int collatz_stoptijd(int reeks) {
    int teller = 1;

    if (reeks > 0) {

        while (reeks != 1) {
            reeks = collatz_opvolger(reeks);
            teller++;
        }
        return teller;
    }

    else {
        return -1;
    }
}

/*
 * In deze functie wordt de stoptijd van de collatz reeks bepaald.
 * Het aantal getallen wordt opgeslagen in 'reeks', die uiteindelijk de hoeveelheid getallen als return geeft.
 * Dit wordt gedaan zolang de reeks geldig (> 0) is, en totdat de reeks gelijk is aan 1 (eind).
 * In deze functie wordt ook een waarde teruggegeven als de reeks niet geldig is (< 0): -1.
 * Output: Return waarde, die het aantal getallen in de gegeven reeks geeft en afgedrukt wordt in _info.
*/

int collatz_maximum(int reeks) {
    int maximum = reeks;

    if (reeks == 1 || reeks == 2){
        maximum = 4;
    }

    if (reeks > 0) {

        while (reeks != 1){
            reeks = collatz_opvolger(reeks);

            if (reeks > maximum) {
                maximum = reeks;
            }
        }
        return maximum;
    }

    else {
        return -1;
    }
}

/*
 * In deze functie wordt de reeks bepaald, als basis voor de andere functies.
 * Zo krijgt de gebruiker de gehele reeks te zien, en niet enkel te volgende waarde.
 * De functie controleerd ook of de reeks nog voldoet, groter dan 0.
 * Output: Geprintte waardes.
*/

void collatz_toon_reeks(int reeks) {

    if (reeks > 0) {
        printf("%d", reeks);

        while (reeks != 1) {
            reeks = collatz_opvolger(reeks);
            printf(", %d", reeks);
        }
    }

    else {
        printf("-1");
    }

    printf("\n");
}

/*
 * In deze functie worden de uitkomsten van de meeste functies geprint.
 * De functie controleerd ook of de reeks nog voldoet, groter dan 0.
 * Output: Geprintte waardes.
*/

void collatz_info(int reeks) {

    if (reeks > 0) {
        printf("Reeks : ");
        collatz_toon_reeks(reeks);

        printf("Stoptijd : %d\n", collatz_stoptijd(reeks));
        printf("Maximum : %d\n", collatz_maximum(reeks));
    }

    else {
        printf("-1\n");
    }
}

/*
 * In deze functie wordt het langste getal van de reeks bepaald.
 * Dit wordt alleen gedaan als de gebruiker 2 waardes geeft.
 * De functie returned -1 als de waardes kleiner zijn dan 0, of a groter is dan b.
 * Output: Return waarde van het langste_getal.
*/

int collatz_zoek_langste(int a, int b) {

    if (a <= 0 || b <= 0 || a > b) {
        return -1;
    }

    int langste_getal = a;
    int langste_stoptijd = collatz_stoptijd(a);

    for (int i = a; i<=b; i++) {
        int huidige_stoptijd = collatz_stoptijd(i);

        if (huidige_stoptijd > langste_stoptijd) {
            langste_stoptijd = huidige_stoptijd;
            langste_getal = i;
        }
    }
    return langste_getal;
}

/*
 * In deze functie wordt het grootste getal van de reeks bepaald.
 * Dit wordt alleen gedaan als de gebruiker 2 waardes geeft.
 * De functie returned -1 als de waardes kleiner zijn dan 0, of a groter is dan b.
 * Output: Return waarde van het grootste_getal.
*/

int collatz_zoek_grootste(int a, int b) {

    if (a <= 0 || b <= 0 || a > b) {
        return -1;
    }

    int grootste_getal = a;
    int grootste_maximum = collatz_maximum(a);

    for (int i = a; i<=b; i++) {
        int huidige_maximum = collatz_maximum(i);

        if (huidige_maximum > grootste_maximum) {
            grootste_maximum = huidige_maximum;
            grootste_getal = i;
        }
    }
    return grootste_getal;
}

/*
 * In deze functie worden de functies _zoek_grootte en _zoek_langste bij elkaar gevoegd en geprint.
 * Dit wordt alleen gedaan als de gebruiker 2 waardes geeft.
 * Ook wordt deze functie niet volledig uitgevoerd als a of b < 0 of a >= b.
 * Output: Geprintte waardes.
*/

void collatz_onderzoek(int a, int b) {

    if (a > 0 && b > 0 && a <= b) {

        int langste = collatz_zoek_langste(a, b);
        int grootste = collatz_zoek_grootste(a, b);

        printf("Langste Collatz reeks tussen %d ", a); 
        printf("en %d:\n", b);
        collatz_info(langste);

        printf("\n");

        printf("Collatz reeks met de grootste waarde tussen %d ", a);
        printf("en %d:\n", b);
        collatz_info(grootste);
    }

    else {
        printf("-1\n");
    }
}

/*
 * In deze functie wordt gecontroleerd of de reeks nog binnen de maximale waarde van een integer past.
 * Dit wordt bepaald met INT_MAX, van library <limits.h>
 * Wanneer de waarde nog past wordt de volgende waarde geprint.
 * Wanneer de waarde niet past wordt de laatst passende waarde geprint.
 * Hiervoor wordt eerst nagegaan of de reeks oneven is.
 * Output: Geprinte waardes, gezien de void.
*/

void collatz_incorrect(void) {
    for (int i = 1; i<=1000000; i++) {
        int reeks = i;

        while (reeks != 1) {
            if (reeks%2 == 1 && reeks > (INT_MAX - 1) / 3) {
                printf("%d\n", i);
                break;
            }

            else {
                reeks = collatz_opvolger(reeks);
            }
        }
    }
}

/*
 * In het volgende deel worden de ingevoerde waardes van de gebruiker omgezet voor de verschillende functies.
 * Er wordt onderscheid gemaakt tussen de verschillende manieren van invoer:
 * De gebruiker geeft geen variabelen.
 * De gebruiker geeft 1 variabel.
 * De gebruiker geeft 2 variabelen, hierbij worden ook de laatste 2 opdrachten geprint.
*/

#ifndef COMPILE_MAIN
int main(int argc, char **argv) {

    if (argc == 1) {
        // Programma is aangeroepen zonder argumenten
        collatz_incorrect();
    } else if (argc == 2) {
        // Programma is aangeroepen met 1 argument.
        collatz_info(atoi(argv[1]));
    } else if (argc == 3) {
        // Programma is aangeroepen met 2 argumenten.
        collatz_onderzoek(atoi(argv[1]), atoi(argv[2]));
    } else {
        printf("gebruik: opdracht2 [getal [tweede getal]]\n");
        return 1;
    }

    return 0;
}
#endif
