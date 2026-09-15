
/* 
 * Naam: Youp Bronkhorst.
 * UvAnetID: 17006813.
 * Studie: BSC Informatica.
 * 
 * deel1.c
 * Dit programma vraagt de gebruiker om 2 cijfers, waarna het een wiskundige formule op die twee getallen uitvoert.
 * Zo kan de gebruiker een waarde voor a en b kiezen, waarna er 2 berekeningen met die getallen worden gedaan:
 * x = (a + b)/2.
 * y = (a - b)/2.
 *
 * Opdracht 1 - Week 1.
 * Inleiding Programmeren.
 */

#include <stdio.h>
#include <math.h>

int main(void) {

    // Variabelen aanmaken.
    int x;
    int y;
    int code;

    // Gebruiker vragen om input.
        printf("Geef de waarde voor a:\n");
        code = scanf("%d", &x);

        printf("Geef de waarde voor b:\n");
        code = scanf("%d", &y);

            if(code == 0) {
                 printf("Het lezen van een getal is niet goed gelukt. Ik stop ermee.\n");
                 return 0;
             }

    // a = ((waarde a + waarde b) / 2)
    int a;
      a = (x + y)/2;
      printf("x = %d\n", a);
    
    // b = ((waarde a - waarde b) / 2)
    int b;
      b = (x - y)/2;
      printf("y = %d\n", b);
    
    return 0;

}
