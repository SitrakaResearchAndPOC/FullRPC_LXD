#ifndef TRI_H_INCLUDED
#define TRI_H_INCLUDED
#define TAILLE 1000

void tri_rapide(int *T, int inf, int sup);
int partition(int *T, int inf,int sup);
void selection_sort(int *tab, int max);
void insert_sort(int *tab, int max);

/*void affiche_tableau(int *tab, int taille);
int obtenir_taille_tableau();
*/
#endif // TRI_H_INCLUDED
