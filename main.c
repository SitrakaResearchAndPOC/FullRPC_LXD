#include <stdio.h>
#include <stdlib.h>
#include "tri.h"


int main()
{
    int tab[TAILLE] = {0};
    int taille = obtenir_taille_tableau();
    printf("la taille du tableau est %d \n", taille);
    obtenir_element_tableau(tab, taille);
    affiche_tableau(tab, taille);
    int tab_selection[TAILLE] = {0};
    copier_tableau(tab, tab_selection, taille);
    printf("tableau non trie selection\n");
    affiche_tableau(tab_selection, taille);
    insert_sort(tab_selection, taille);
    printf("tableau trie selection\n");
    affiche_tableau(tab_selection, taille);



    return 0;
}
