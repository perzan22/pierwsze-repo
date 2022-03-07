#include <stdio.h>

void sortowaniePesel()
{
    int pesel[] = {0, 2, 2, 3, 1, 9, 4, 3, 8, 7, 5};   
    selectionSort(pesel);   
    for (int i = 0; i < 11; i++)   
    printf("%d", pesel[i]);
}

void selectionSort(int tab[])   
{

    int min;
    int temp;
    for (int i = 0; i < 10; i++) {  
        for (int j = i + 1; j < 11; j++){
            if (tab[i] > tab[j]) {  
                min = j;
                temp = tab[i];
            tab[i] = tab[min];
            tab[min] = temp; 
            }
        }
    }
}
