#include <stdio.h>

void mainl()
{
    int pesel[] = {0, 2, 2, 3, 1, 9, 4, 3, 8, 7, 5};    /* utworzenie tablicy  z numerem pesel */
    selectionSort(pesel);   /* wywołanie funkcji selectionSort() */
    for (int i = 0; i < 11; i++)    /* pętla for do wypisania posortowanego peselu */
    printf("%d", pesel[i]);
}

void selectionSort(int tab[])   /* deklaracja funkcji */

{

    int min;
    int temp;
    for (int i = 0; i < 10; i++) {  /* pętla for do posortowania tabeli */
        for (int j = i + 1; j < 11; j++){
            if (tab[i] > tab[j]) {  /* if sprawdza czy dany element tablicy jest większy od kolejnych */
                min = j; /* zapisanie indeksu minimalnego elementu tablicy */
                temp = tab[i];  /* tymczasowa zmienna przyjmuje wartość sprawdzanego elementu */
            tab[i] = tab[min];  /* element tablicy jest zastepowany mniejszym */
            tab[min] = temp;    /* większy element przyjmuje wartość tymczasowej zmiennej */
            }
        }
    }
}
