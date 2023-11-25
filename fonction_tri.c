#include <stdio.h>
#include <stdlib.h>
#include "tri.h"

void tri_rapide(int *T, int inf, int sup){
    if(inf < sup){
        int q = partition(T, inf, sup);
        printf("partition %d vers %d \n", inf, sup);
        tri_rapide(T, inf, q-1);
        tri_rapide(T, q+1, sup);
    }

}




int partition(int *T, int inf,int sup){
    int x = T[sup];
    int i = inf -1;
    int j = inf;
    while(j <= sup-1){

        if(T[j]>x)
            j++;
        else{
            int temp = T[i+1];
            T[i+1] = T[j];
            T[j] = temp;
            i++;
            j++;
        }

        }

    int temp2 = T[i+1];
    T[i+1] = T[sup];
    T[sup] = temp2;

    return i+1;
}

void selection_sort(int *tab, int max){

    for(int i = 0; i < max; i++){
            // get min
            int min = tab[i];
            int indice_min = i;
            for(int j = i+1; j <max; j++){
                    if(tab[j] < min){
                        min = tab[j];
                        indice_min = j;
                    }

            }
            // mettre ç la bonne place le minim
            int temp = tab[i];
            tab[i] = tab[indice_min];
            tab[indice_min] = temp;

    }
}

void insert_sort(int *tab, int max){

    for(int i = 1; i < max; i++){
        int temp = tab[i];
        int j = i-1;
        while(j >= 0 && tab[j] > temp){
            tab[j+1] = tab[j];
            j--;
         }
         tab[j+1] = temp;
    }
}

