#include <stdio.h>

void sortowanieBabelkowe()
{
    int cyfry[] = {6, 7, 2, 9, 0, 2, 5, 8, 1, 6, 9, 4, 5, 6, 3};
    bubbleSort(cyfry);
    for (int i = 0; i < (sizeof cyfry / sizeof(int)); i++)
    printf("%d ", cyfry[i]);
}

void bubbleSort(int tab[])

{
    int temp;
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14 - i; j++){
            if (tab[j] > tab[j + 1]) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}
