//Fichier qui corresponnd à toutes les fonctions de la partie 1

#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int grille_4x4_1 [4][4] = {{1,0,0,1},
                           {1,1,0,0},
                           {0,1,1,0},
                           {0,0,1,1}};

int grille_8x8_1 [8][8] = {{0,0,1,0,1,1,0,1},
                           {1,1,0,1,0,1,0,0},
                           {1,0,0,0,0,0,1,1},
                           {0,1,1,0,1,0,0,1},
                           {0,1,1,0,0,1,1,0},
                           {1,0,0,1,1,0,0,1},
                           {1,1,0,0,1,0,1,0},
                           {0,0,1,1,0,1,1,0}};

//Fonction poour envoyer l'une des deux grilles dans la fonction pour pouvoir l'utiliser par la suite (donc la mettre en local)
// 7
int** GrilleEnLocal(int k, int num_grille){
    int **grille_local = NULL;
    grille_local = (int**) malloc(k * sizeof (int*));
    for (int i=0; i<k; i++){
        grille_local[i] = (int*) malloc(k * sizeof (int));}

    if (num_grille==1){

        for (int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                grille_local[i][j] = grille_4x4_1[i][j];
            }
        }
    }
    else if (num_grille==2){
        for (int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                grille_local[i][j] = grille_8x8_1[i][j];
            }
        }
    }
    return grille_local;
}

//Fonction pour afficher le masque entrain d'être rempli
// 5
void AfficherGrille(int** grille, int k){
    printf("\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            printf("%d",grille[i][j]);
            printf("\t");
        }
        printf("\n\n");
    }
}

//Fonction pour créer une grille de 0 de la dimension souhaitée
// 4
int** CreeGrilleVide (int k){
    int **masque_vide = NULL;
    masque_vide = (int**) malloc(k * sizeof (int*));
    for (int i=0; i<k; i++){
        masque_vide[i] = (int*) malloc(k * sizeof (int));}

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            masque_vide[i][j] = 0;
        }
    }
    return masque_vide;
}

//Fonction pour créer le masque manuellement
// 3
int** RemplirMasqueManu(int k){
    int maxi = k-1;
    int** grille_masque = CreeGrilleVide(k);

    printf("\n Veuillez saisir les cases que vous voulez faire apparaitre en rentrant leurs coordonnees de la maniere suivante : x,y\n");

    int x,y,nbcase=0,tour;

    if (k==4) tour=6; else tour=15;

    while (nbcase != tour){
        AfficherGrille(grille_masque,k);

        printf("\nRentrer les coordonnees de la case : ");
        scanf(" %d, %d",&x,&y);

        while(x < 0 || x > maxi || y < 0 || y > maxi){
            printf("\nMauvaises coordonnees veuillez recommencer : ");
            scanf(" %d, %d",&x,&y);
        }

        while(grille_masque[x][y]==1){
            printf("\nVous avez deja choisi cette case veuillez recommencer : ");
            scanf(" %d, %d",&x,&y);

            while(x < 0 || x > 7 || y < 0 || y > 7){
                printf("\nMauvaises coordonnees veuillez recommencer : ");
                scanf(" %d, %d",&x,&y);
            }
        }
        grille_masque[x][y] = 1;
        nbcase++;
    }
    printf("\nVoila votre masque :\n");
    AfficherGrille(grille_masque, k);
    return grille_masque;
}

//Fontion pour remplir le masque automatiquement
// 3
int** RemplirMasqueAuto(int k){
    int** grille_masque = CreeGrilleVide(k);
    int x,y,nbcase=0,tour;
    srand(time(NULL));

    if (k==4) tour=6; else tour=15;

    while (nbcase != tour){


        x = rand() % k;

        y = rand() % k;

        while(grille_masque[x][y]==1){

            x = rand() % k;

            y = rand() % k;
        }
        grille_masque[x][y] = 1;
        nbcase++;
    }
    return grille_masque;
}

//Fonction pour créer la grille de jeu
// 6
int** CreeGrilleJeu(int** grille_masque,int k){
    int n;

    if (k==4) {n=1;}
    else if (k==8) {n=2;}

    int **grille_res = GrilleEnLocal(k,n);
    int **grille_jeu = CreeGrilleVide(k);

    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){

            if (grille_masque[i][j]==1){
                grille_jeu[i][j] = grille_res[i][j];
            }
            else if (grille_masque[i][j]==0){
                grille_jeu[i][j] = 7;
            }
        }
    }
    return  grille_jeu;
}

//Fonction pour que l'utilisateur puisse jouer une partie
// 8
void Jeu(int** grille_jeu,int** grille_masque, int k){
    printf("\nA vous de jouer !...Voici les commandes :\n\n 1- Pour placer un 0, taper 0;x,y\n 2- Pour placer un 1, taper 1;x,y\n 3- Pour supprimer une reponse 2;x,y\n 4- Pour quitter la partie taper 3 et les coordonnees d'une case au choix (3;x,y)\n(!)Attention vous n'avez le droit qu'a trois erreurs...\n\n");

    int maxi = k-1;
    int choix,x,y;
    int vie=3;

    while (vie != 0){
        AfficherGrilleJeu(grille_jeu,k);
        printf("\nQue voulez-vous faire ? : ");
        scanf(" %d;%d,%d",&choix,&x,&y);

        while (choix<0 || choix >3 || x < 0 || x > maxi || y < 0 || y > maxi){
            printf("\nReponse incorrecte...Que voulez-vous faire ? : ");
            scanf(" %d;%d,%d",&choix,&x,&y);
        }

        while (grille_masque[x][y]==1){
            printf("\nVous de pouvez pas modifier cette case...Que voulez-vous faire ? : ");
            scanf(" %d;%d,%d",&choix,&x,&y);

            while (choix<0 || choix >3 ||x < 0 || x > maxi || y < 0 || y > maxi){
                printf("\nReponse incorrecte...Que voulez-vous faire ? : ");
                scanf(" %d;%d,%d",&choix,&x,&y);
            }
        }

        if (choix==0 || choix==1) {
            int svg = grille_jeu[x][y], fin = 0;
            grille_jeu[x][y] = choix;

            if (VeriTroisLigne(grille_jeu, k, choix) == 1) {
                printf("\n(!)Attention vous avez trois 0 ou trois 1 d'affiles");
                fin = 1;
            }
            if (VeriComplet(grille_jeu, k) == 1){
                if (VeriColonneLigne(grille_jeu, k) == 1) {
                    printf("\n(!)Attention vous avez deux voire plusieurs colonne/ligne identiques");
                    fin = 1;
                }
            }
            if(VeriColonneLigneMemeNombre(grille_jeu,k)  == 1){
                printf("\n(!)Attention vous n'avez pas le meme nombre de 1 et de 0 dans une de vos lignes ou dans l'une de vos colonnes");
                fin = 1;
            }

            if (fin == 1){
                printf("\n");
                AfficherGrilleJeu(grille_jeu,k);
                vie--;
                printf(" [:] Vie restante : %d\n",vie);
                grille_jeu[x][y] = svg;
            }
        }

        else if(choix==2){
            grille_jeu[x][y] = 7;
        }

        else if(choix == 3){
            printf("\n---------|Vous avez quitte la partie|----------\n");
            break;
        }

        if (Veri(grille_jeu,k) == 0){
            if (VeriTroisLigne(grille_jeu,k,choix) == 0 && VeriColonneLigne(grille_jeu,k) == 0 && VeriColonneLigneMemeNombre(grille_jeu,k)  == 0){
                AfficherGrilleJeu(grille_jeu,k);
                printf("\n---------|Vous avez remporte la parite... Bravo !!!|------------\n");
                break;
            }
        }
        else if (vie == 0){
            printf("\n-----|Vous avez perdu, vous avez consomme l'integralite de vos vies...|-----\n");
            break;
        }
    }
}

//Fonction pour savoir si l'utilistateur veut remplir lui même son masque ou alors de lui en donner un automatiquement
// 2
void ChoixMasque(int k){
    printf("\nVoulez-vous choisir le masque de la grille ?\n  1- Oui\n  2- Non\n  3- Retour en arriere\n");

    char Choix;

    do{
        printf("\nEntrer votre choix :");
        scanf(" %c",&Choix);
    }while(Choix != '1' && Choix != '2' && Choix != '3');

    if (Choix == '1')
    {
        int** grille_masque = RemplirMasqueManu(k);
        int ** grille_jeu = CreeGrilleJeu(grille_masque,k);
        Jeu(grille_jeu,grille_masque,k);
    }
    else if (Choix == '2')
    {
        int** grille_masque = RemplirMasqueAuto(k);
        int ** grille_jeu = CreeGrilleJeu(grille_masque,k);
        Jeu(grille_jeu,grille_masque,k);
    }
    else if (Choix == '3')
    {
        printf("\n-Retour en arriere-\n");
        ChoisirDim();
    }
}

//Fonction pour choisir les dimensions de la grille
// 1
void ChoisirDim(void){
    printf("\nEn quelle dimension voulez-vous jouer ?\n  1- 4x4\n  2- 8x8\n  3- Retourner en arriere\n");

    char Choix;

    do {
        printf("\nEntrer votre choix :");
        scanf(" %c",&Choix);
    }while(Choix != '1' && Choix != '2' && Choix != '3');

    if (Choix == '1')
    {
        ChoixMasque(4);
    }
    else if (Choix == '2')
    {
        ChoixMasque(8);
    }
    else if (Choix == '3')
    {
        printf("\n-Retour en arriere-\n");
    }
}