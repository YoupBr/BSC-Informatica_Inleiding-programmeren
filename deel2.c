
/* 
 * Naam: Youp Bronkhorst.
 * UvAnetID: 17006813.
 * Studie: BSC Informatica.
 * 
 * deel2.c
 * Dit programma maakt een driehoek van puntjes, ingesloten door *.
 * Hierbij wordt gebruik gemaakt van meerdere while-statements.
 * Verder wordt er een if-statement gebruikt om te controleren of de eerste * nodig is, zodat de laatste regel maar één * heeft.
 *
 * Opdracht 1 - Week 1.
 * Inleiding Programmeren.
 */

#include <stdio.h>

int main(void) {

    // Variabelen aanmaken.
    int rijpositief = 0;
    int rijnegatief = 9;
    int aantal;
    int spaties;
    int teller;

    spaties = 0;

    // Optellen van de punten per twee.
    while(rijpositief < 14) {

        teller = 0;
        aantal = 0;

        while(teller < spaties) {
            printf("  ");
            teller++;
        }
        
        printf("*");

        while(aantal < rijpositief) {
            printf("..");
            aantal++;
        }

        printf("*\n");

        rijpositief++;
        spaties++;
     }

    // Aflopen van de punten per 3
    aantal = 23;
    while(rijnegatief != 0) {

        teller = 0;

        while(teller < spaties) {
            printf("  ");
            teller++;
        }
        
        if (aantal >= 2) {
            printf("*");
        }

        teller = 0;

        while(teller < aantal) {
            printf(".");
            teller++;
        }
        
    // Laatste * wanneer er geen punten meer worden geprint.
        printf("*\n");

        rijnegatief--;
        spaties++;
        aantal -=3;

    }

    return 0;
}
