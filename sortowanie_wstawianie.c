#include <stdio.h>

void sortowanie_wstawianie()
{
    int cyfry[] = {4, 8, 4, 3, 9, 0, 1, 6, 2, 8, 5, 7, 2, 7, 0};
    insertionSort(cyfry);
    for (int i = 0; i < (sizeof cyfry / sizeof(int)); i++)
    printf("%d ", cyfry[i]);
}

void insertionSort(int tab[])

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
