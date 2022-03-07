#include <stdio.h>

void main()
{
    int pesel[] = {0, 2, 2, 3, 1, 9, 4, 3, 8, 7, 5};    /* utworzenie tablicy  z numerem pesel */
    selectionSort(pesel);   /* wywo�anie funkcji selectionSort() */
    for (int i = 0; i < 11; i++)    /* p�tla for do wypisania posortowanego peselu */
    printf("%d", pesel[i]);
}

void selectionSort(int tab[])   /* deklaracja funkcji */

{

    int min;
    int temp;
    for (int i = 0; i < 10; i++) {  /* p�tla for do posortowania tabeli */
        for (int j = i + 1; j < 11; j++){
            if (tab[i] > tab[j]) {  /* if sprawdza czy dany element tablicy jest wi�kszy od kolejnych */
                min = j;
                temp = tab[i];
            tab[i] = tab[min];  /* element tablicy jest zastepowany mniejszym */
            tab[min] = temp;    /* wi�kszy element "wskakuje" na miejsce mniejszego */
            }
        }
    }
}
