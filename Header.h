//permet de répertorier toutes les fonctions et de les lier entres elles dans tous les fichiers

#ifndef PROJET_TAKUZU_HEADER_H
#define PROJET_TAKUZU_HEADER_H


void ChoisirDim();
void ChoixMasque(int k);

int** RemplirMasqueManu(int k);
int** RemplirMasqueAuto(int k);

int** CreeGrilleJeu(int** grille_masque,int k);
void Jeu(int** grille_jeu,int** grille_masque, int k);

void AfficherGrille(int** grille, int k);
int** CreeGrilleVide (int k);
int** GrilleEnLocal(int k, int num_grille);



void AfficherGrilleJeu(int** grille,int k);
int VeriTroisLigne(int**grille_jeu,int k,int choix);


int VerifLigneComp(int** grille_jeu, int k, int o);
int VerifColonneComp(int** grille_jeu, int k, int o);
int VeriComplet(int** grille_jeu,int k);

int VeriColonneLigne(int** grille_jeu,int k);
int VeriColonneLigneMemeNombre(int** grille_jeu,int k);

int Veri (int** grille_jeu, int k);

#endif //PROJET_TAKUZU_HEADER_H
