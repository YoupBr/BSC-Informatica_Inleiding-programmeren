
/* 
 * Naam: Youp Bronkhorst.
 * UvAnetID: 17006813.
 * Studie: BSC Informatica.
 * 
 * deel3.c
 * Dit programma is bedoeld als gokspelletje, waar de computer 'valsspeelt' zodat het spel zolang mogelijk duurt.
 * Hierbij wordt er gebruik gemaakt van een stukje logica, die per gok de grenzen van het spel aanpast.
 * Zo bepaalt de computer niet van de voren een getal, maar per gok zodat er zoveel mogelijk pogingen nodig zijn.
 *
 * Opdracht 1 - Week 1.
 * Inleiding Programmeren.
 */

#include <stdio.h>

int main(void) {

    // Variabelen aanmaken en sommige basiswaardes toekennen.
    int bezig = 1;

    int maximum = 100;
    int minimum = 0;

    int gok;
    int code;

    int hoger;
    int lager;

    // Een while-loop maken zodat het script pas stopt wanneer het juiste getal is geraden.
        while (bezig == 1) {

            printf("Doe een gok:\n");
            code = scanf("%d", &gok);
            
            if (code == 0 || gok < 0 || gok > 100) {
                printf("Ik begrijp de invoer niet.\n");
                return 0;
            }

            if (maximum == minimum) {
                printf("Je hebt het geraden!\n");
                bezig = 0; 
            }

    // De rekenkundige logica achter het 'valsspelen'.
            else {
                hoger = maximum - gok;
                lager = gok - minimum;

                if (lager>=hoger) {
                    printf("Te hoog.\n");
                    maximum = gok - 1;
                    printf("\n");
                }

                else {
                    printf("Te laag.\n");
                    minimum = gok + 1;
                    printf("\n");
                }
          }
     }

    return 0;
}
