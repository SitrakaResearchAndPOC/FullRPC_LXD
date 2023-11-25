#include <stdio.h>
#include <stdlib.h>
#include "tri.h"

void affiche_tableau(int *tab, int taille){
    int i;
    for(i = 0; i < taille; i++){
        printf("%d -> ", tab[i]);
    }
    printf("\n");
}


int obtenir_taille_tableau(){
    int taille;
    printf("Entrer la taille du tableau\n");
    scanf("%d", &taille);
    return taille;
}



void obtenir_element_tableau(int *tab, int taille){
    int i = 0;
    for(i = 0; i < taille; i++){
        printf("Entrer l'element numéro %d \n", (i+1));
        scanf("%d", &tab[i]);
    }
}


void copier_tableau(int *tab1, int *tab2, int taille){
    int i = 0;
    for(i = 0; i <taille;i++){
        tab2[i] = tab1[i];
    }

}
