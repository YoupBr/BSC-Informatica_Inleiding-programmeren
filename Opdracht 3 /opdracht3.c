/*
 * opdracht3.c:
 * − Uitwerking opdracht 3.
 */


#include <stdio.h>
#include <stdlib.h>

#define MAX_OPDRACHT_LEN 100
#define BREEDTE 79
#define HOOGTE 40
#define LEVEND 1
#define DOOD 0

void initialiseer_grid(int grid[HOOGTE][BREEDTE], int patroon) {
    // Implementeer en documenteer deze functie
}

void toon(const int grid[HOOGTE][BREEDTE], int generatie) {
    // Implementeer en documenteer deze functie
}

void kopie(const int bron_grid[HOOGTE][BREEDTE], int doel_grid[HOOGTE][BREEDTE]) {
    // Implementeer en documenteer deze functie
}

int buren(const int grid[HOOGTE][BREEDTE], int x, int y) {
    // Implementeer en documenteer deze functie
    return 0;
}

void stap(const int oud_grid[HOOGTE][BREEDTE], int nieuw_grid[HOOGTE][BREEDTE]) {
    // Implementeer en documenteer deze functie
}

/* Hoofdprogramma.

   Het initialiseert en toont eerst de begintoestand van het grid. (Je kunt
   eventueel als je het programma opstart opgeven welk beginpatroon moet
   worden gebruikt.)

   Vervolgens kun je telkens opgeven hoeveel generaties de computer moet
   doorberekenen, door het aantal generaties in te typen dat er moet worden
   doorberekend.

   Als je op Enter drukt zonder een getal in te vullen zal de computer de
   eerstvolgende generatie tonen.

   Druk op Ctrl+D om het programma te beeindigen.
*/
#ifndef COMPILE_MAIN
int main(int argc, char *argv[]) {
    char buffer[MAX_OPDRACHT_LEN];
    int grid[HOOGTE][BREEDTE];
    int nieuw_grid[HOOGTE][BREEDTE];

    int patroon = argc == 1 ? 1 : atoi(argv[1]);
    initialiseer_grid(grid, patroon);
    int generatie = 0;

    printf("Conway's Game of life\n\n");
    toon(grid, generatie);
    while (1) {
        printf("\nGeef een opdracht:\n");
        char *res = fgets(buffer, MAX_OPDRACHT_LEN, stdin);
        if (res == NULL) {
            // Er is waarschijnlijk op Ctrl+D gedrukt.
            printf("Programma wordt beëindigd.\n");
            break;
        }
        int aantal_generaties = buffer[0] == '\n' ? 1 : atoi(buffer);
        for (int i = 0; i < aantal_generaties; i++) {
            stap(grid, nieuw_grid);
            kopie(nieuw_grid, grid);
        }
        generatie += aantal_generaties;
        toon(grid, generatie);
    }
    return 0;
}
#endif
