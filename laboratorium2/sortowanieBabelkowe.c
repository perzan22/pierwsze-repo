#include <stdio.h>

void main()
{
    int cyfry[] = {6, 7, 2, 9, 0, 2, 5, 8, 1, 6, 9, 4, 5, 6, 3};    /* tworzenie tablicy 15 - elemenetowej */
    bubbleSort(cyfry);  /* wywołanie funkcji bubbleSort() */
    for (int i = 0; i < (sizeof cyfry / sizeof(int)); i++)  /* pętla wypisująca elementy tablicy */
    printf("%d ", cyfry[i]);
}

void bubbleSort(int tab[])  /* deklaracja funkcji bubbleSort */

{
    int temp;
    for (int i = 0; i < 14; i++) {  /* pętla for sortująca tablicę, przechodzi przez każdy element tablicy po kolei */
        for (int j = 0; j < 14 - i; j++){   /* pętla for sprawdzająca element z kolejnym elementem */   
            if (tab[j] > tab[j + 1]) {  /* sprawdzenie czy element jest większy od kolejnego */
                temp = tab[j];  /* zapisanie elementu do tymczasowej zmiennej */
                tab[j] = tab[j + 1];    /* zmiana wartości elementu na wartość kolejenego elementu */
                tab[j + 1] = temp;  /* zastąpienie kolejnego elementu tymczasową zmienną */
            }
        }
    }
}
