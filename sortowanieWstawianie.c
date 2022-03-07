#include <stdio.h>

void sortowanieWstawianie()
{
    int cyfry[] = {4, 8, 4, 3, 9, 0, 1, 6, 2, 8, 5, 7, 2, 7, 0};    /* tworzenie tablicy 15 - elementowej */
    insertionSort(cyfry);   /* wywołanie funkcji insertionSort() */
    for (int i = 0; i < (sizeof cyfry / sizeof(int)); i++) /* pętla wypisująca posortowane elementy tablicy */
    printf("%d ", cyfry[i]);
}

void insertionSort(int tab[])   /* deklaracja funkcji */

{
    int j, temp;  
    for (int i = 1; i < 15; i++) {
        temp = tab[i];
        j = i - 1;
        while (j >= 0 && tab[j] > temp){
            tab[j + 1] = tab[j];
            j--;
            }
            tab[j + 1] = temp;
        }
}
