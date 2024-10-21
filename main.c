//Fichier main, il est le commencement du programme la première fonction appelée qui représente le menu principal du programme

#include "Header.h"
#include <stdio.h>

int main(void) {

    while (1) {

        printf("\nBienvenue sur le jeu du Takuzu, veuillez choisir votre mode de jeu :\n  1- Jouer en mode classique\n  2- Resoudre automatiquement une grille\n  3- Generer une grille\n  4- Quitter le jeu\n");

        char Choix;

        do {
            printf("\nEntrer votre choix :");
            scanf(" %c", &Choix);
        } while (Choix != '1' && Choix != '2' && Choix != '3' && Choix != '4');

        if (Choix == '1')
        {
            printf("\n");
            ChoisirDim();
        }
        else if (Choix == '2')
        {
            printf("\nArrive bientot\n");
        }
        else if (Choix == '3')
        {
            printf("\nArrive bientot\n");
        }
        else if (Choix == '4')
        {
            printf("\n---------|Vous avez quitte le jeu|---------\n");
            break;
        }
    }

    return 0;
}