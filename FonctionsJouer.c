#include "Header.h"
#include <stdio.h>


//Fonction pour afficher la grille de jeu actualisée
// 1
void AfficherGrilleJeu(int** grille,int k){
    printf("\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if(grille[i][j]==7){
                printf("-\t");
            }
            else {
                printf("%d", grille[i][j]);
                printf("\t");
            }
        }
        printf("\n\n");
    }
}

//Fontion pour vérifier la première règle du jeu (donc pas trois 0 ou 1 d'affilée)
// 2
int VeriTroisLigne(int** grille_jeu,int k,int choix){
    int veri = 0;
    for (int i=0; i<k; i++){
        for (int j=0; j<k-2; j++){

            if (grille_jeu[i][j]==choix && grille_jeu[i][j+1]==choix && grille_jeu[i][j+2]==choix){
                veri = 1;
            }
        }
    }
    for (int j=0; j<k; j++){
        for (int i=0; i<k-2; i++){

            if (grille_jeu[i][j]==choix && grille_jeu[i+1][j]==choix && grille_jeu[i+2][j]==choix){
                veri = 1;
            }
        }
    }
    return veri;
}


//************************************

//Fonction qui vérifie que la ligne et complète
// 5
int VerifLigneComp(int** grille_jeu, int k, int o){
    int veri = 0;
    for (int j=0; j<k; j++){
        if (grille_jeu[o][j] != 0 && grille_jeu[o][j] != 1){
            veri = 1;
        }
    }
    return veri;
}

//Fonction qui vérifie que la colonne est complète
// 6
int VerifColonneComp(int** grille_jeu, int k, int o){
    int veri = 0;
    for (int j=0; j<k; j++){
        if (grille_jeu[j][o] != 0 && grille_jeu[j][o] != 1){
            veri = 1;
        }
    }
    return veri;
}

//Fonction pour savoir si il y a au moin plus d'une ligne ou d'une colonne de complétées
// 3
int VeriComplet(int** grille_jeu,int k){
    int veri =0, cpt = 0, veri2 = 0, cpt2 = 0;
    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            if (grille_jeu[i][j] == 7){
                cpt++;
            }
        }
        if (cpt > 0){
            veri++;
            cpt = 0;
        }
    }

    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            if (grille_jeu[j][i] == 7){
                cpt2++;
            }
        }
        if (cpt2 > 0){
            veri2++;
            cpt2 = 0;
        }
    }

    if ((k-veri) >= 2 || (k- veri2) >= 2){
        return 1;
    }
    else{
        return 0;
    }
}

//***************************************************

//Fonction qui vérifie qu'il n'y ait pas de lignes ou de colonnes identiques
// 4
int VeriColonneLigne(int** grille_jeu,int k){
    int veri, veriligne = 0, vericolonne = 0;

    for (int i=0;i<k-1;i++){

        if (VerifLigneComp(grille_jeu, k,i) == 0) {

            for (int j = i+1; j < k; j++) {

                if (VerifLigneComp(grille_jeu, k,j) == 0) {

                    for (int p = 0; p < k; p++) {

                        if (grille_jeu[i][p] != grille_jeu[j][p]) {
                            veriligne = 1;
                        }
                    }
                }
            }
        }
    }

    for (int i=0;i<k-1;i++){

        if (VerifColonneComp(grille_jeu,k,i) == 0) {

            for (int j = i+1; j < k; j++) {

                if (VerifColonneComp(grille_jeu,k,j) == 0) {

                    for (int p = 0; p < k; p++) {

                        if (grille_jeu[p][i] != grille_jeu[p][j]) {
                            vericolonne = 1;
                        }
                    }
                }
            }
        }
    }

    if (veriligne == 1 || vericolonne == 1){
        veri = 0;
    }
    else{
        veri = 1;
    }

    return veri;
}

//Fonction qui vérifie qu'il y ait le même nombre de 0 et de 1 dans chaque colonne et dans chaque ligne.
// 7
int VeriColonneLigneMemeNombre(int** grille_jeu,int k){
    int veri = 0, cptligne0 = 0, cptligne1 = 0, cptcolonne0 = 0, cptcolonne1 = 0;

    for (int i=0; i<k; i++){

        if (VerifLigneComp(grille_jeu,k,i) == 0) {

            for (int j = 0; j < k; j++) {
                if (grille_jeu[i][j] == 0) {
                    cptligne0++;
                } else if (grille_jeu[i][j] == 1) {
                    cptligne1++;
                }
            }

            if (cptligne0 != (k / 2) || cptligne1 != (k / 2)) {
                veri = 1;
            }

            cptligne0 = 0;
            cptligne1 = 0;
        }
    }

    for (int i=0; i<k; i++){

        if (VerifColonneComp(grille_jeu,k,i) == 0) {

            for (int j = 0; j < k; j++) {
                if (grille_jeu[j][i] == 0) {
                    cptcolonne0++;
                } else if (grille_jeu[j][i] == 1) {
                    cptcolonne1++;
                }
            }

            if (cptcolonne0 != (k / 2) || cptcolonne1 != (k / 2)) {
                veri = 1;
            }

            cptcolonne0 = 0;
            cptcolonne1 = 0;
        }
    }
    return veri;
}

//**********************************************

//Fonction qui vérifie que la grille est entièrement complétée
// 8
int Veri (int** grille_jeu, int k){
    int veri = 0;

    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            if (grille_jeu[i][j] != 0 && grille_jeu[i][j] != 1){
                veri = 1;
            }
        }
    }
    return veri;
}