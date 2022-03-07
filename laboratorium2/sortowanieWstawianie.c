#include <stdio.h>

void main()
{
    int cyfry[] = {4, 8, 4, 3, 9, 0, 1, 6, 2, 8, 5, 7, 2, 7, 0};    /* tworzenie tablicy 15 - elementowej */
    insertionSort(cyfry);   /* wywołanie funkcji insertionSort() */
    for (int i = 0; i < (sizeof cyfry / sizeof(int)); i++) /* pętla wypisująca posortowane elementy tablicy */
    printf("%d ", cyfry[i]);
}

void insertionSort(int tab[])   /* deklaracja funkcji */

{
    int j, temp;  
    for (int i = 1; i < 15; i++) {  /* pętla sortująca każdy element po kolei od drugiego elementu */
        temp = tab[i];  /* ustawienie tymczasowej zmiennej na wartość sprawdzanego argumentu */
        j = i - 1; 
        while (j >= 0 && tab[j] > temp){    /* pętla wykonująca instrukcje jeśli j wieksze lub równe 0 i element talicy z indeksem j wiekszy od tymczasowej zmiennej */
            tab[j + 1] = tab[j];    /* zamiana sprawdzanego elementu tablicy z argumentem z prawej strony */
            j--;    /* zmniejszenie j o 1 */
            }
            tab[j + 1] = temp; /* ustawienie elementu z prawej strony na zmienną tymczasową */
        }
}
