/*  Name : sequentiel.h
    Purpose : Ensemble des sous-programmes se rapportant
            � la manipulation et la gestion du fichier .txt cr��
    Authors : TCHAMIE Bindounow Gnimdou Jepht� & AGBAKOSSI Ekou� Seyram R�n�
    Date    : 29/11/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <math.h>


#include "random.h"

#define MAX_TENTATIVES 10
#define MAX_PSEUDO_LENGTH 20
#define FILENAME "tentatives.txt"

// Fonction pour v�rifier si le pseudo existe d�j� dans le fichier
int pseudo_existe(const char *pseudo) {
    FILE *fichier = fopen(FILENAME, "r");
    if (fichier == NULL) {
        return 0; // Le fichier n'existe pas encore, pas de doublon
    }

    char ligne[100];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        if (strstr(ligne, pseudo) != NULL) {
            fclose(fichier);
            return 1; // Pseudo trouv�
        }
    }

    fclose(fichier);
    return 0; // Pseudo non trouv�
}

void afficher_scores() {
    FILE *fichier = fopen(FILENAME, "r");
    if (fichier == NULL) {
        printf("Aucun historique trouv�.\n");
        return;
    }

    char ligne[100];
    printf("Historique des parties :\n");
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        printf("%s", ligne);
    }

    fclose(fichier);
}

