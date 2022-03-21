#include <stdio.h>
#include <stdlib.h>

//############################
//#     MERGE SORT !!!!!!!   #
//############################

void merge(int tab[], int l_side, int middle, int r_side)   // deklaracja funkcji merge z argumentami:
                                                            // tablica sortowana, indeks pierwszego argumentu,
                                                            // indeks środkowego elementu i indeks oststniego elementu
{
    int i, j, k;    // deklaracja zmiennych i, j, k
    int n1 = middle - l_side + 1;   // deklaracja długości tablicy L_temp, równej indeksowi
                                    // środkowego elementu zmniejszonego o indeks pierwszego elementu, zwiększonej o 1

    int n2 = r_side - middle;   // deklaracja długości tablicy R_temp, równej indeksowi ostatniego elementu zmniejszonego
                                // o indeks środkowego elementu

    int L_temp[n1], R_temp[n2]; // deklaracja tablic tymczasowych zawierających elementy tablicy z lewej strony (L_temp)
                                // oraz prawej strony (R_temp)


    for (i = 0; i < n1; i++)    // pętla for, która wykona przejścia po wszystkich elementach tablicy L_temp
    {
        L_temp[i] = tab[l_side + i];    // przypisanie do tymczasowej tablicy, elementy sortowanej tablicy z lewej strony
    }

    for (j = 0; j < n2; j++)    // pętla for, która wykona przejścia po wszystkich elementach tablicy R_temp
    {
        R_temp[j] = tab[middle + 1 + j];    // przypisanie do tymczasowej tablicy, elementy sortowanej tablicy z prawej strony
    }


    i = 0;  // przypisanie zmiennej i wartości 0
    j = 0;  // przypisanie zmiennej j wartości 0
    k = l_side; // przypisanie zmiennej k wartość indeksu pierwszego elementu sortowanej tablicy

    while (i < n1 && j < n2)    // pętla while, wykonująca przejścia po wszystkich elementach tablic tymczasowych dopóki zmienne
                                // i oraz j są obie mniejsze od rozmiarów tablic tymczasowych
        {
            if (L_temp[i] <= R_temp[j]) // sprawdzenie czy wartość elementu lewej tymczasowej tablicy o indeksie i jest
                                        // mniejszy bądź równy wartości elementu prawej tymczasowej tablicy o indeksie j
            {
                tab[k] = L_temp[i]; // przypisanie elementowi tablicy sortowanej o indeksie k, wartości elementu lewej tablicy
                                    // tymczasowej o indeksie i, jeśli spełniony warunek zdania warunkowego if
                i++;    // zwiększenie i o 1
            }
            else
            {
                tab[k] = R_temp[j]; // przypisanie elementowi tablicy sortowanej o indeksie k, wartości elementu prawej tablicy
                                    // tymczasowej o indeksie j, jeśli nie został spełniony warunek zdania warunkowego if
                j++;    // zwiększenie j o 1
            }
        k++;    // zwiększenie k o 1
        }


    while (i < n1)  // pętla while wykonująca przejścia po pozostałych elementach lewej tymczasowej tablicy
        {
            tab[k] = L_temp[i]; // przypisanie elementowi tablicy sortowanej o indeksie k, wartości elementu lewej tablicy
                                // tymczasowej o indeksie i
            i++;    // zwiększenie i o 1
            k++;    // zwiększenie k o 1
        }

    while (j < n2)  // pętla while wykonująca przejścia po pozostałych elementach prawej tymczasowej tablicy
        {
            tab[k] = R_temp[j]; // przypisanie elementowi tablicy sortowanej o indeksie k, wartości elementu prawej tablicy
                                // tymczasowej o indeksie j
            j++;    // zwiększenie j o 1
            k++;    // zwiększenie k o 1
        }
}


void mergeSort(int tab[], int l_side, int r_side)   // deklaracja funkcji mergeSort z argumentami:
                                                    // tablica sortowana, indeks pierwszego elementu, indeks ostatniego elementu
{
    if (l_side < r_side) {  // sprawdzenie czy indeks pierwszego elementu jest mniejszy od ostatniego elementu

        int middle = l_side + (r_side - l_side) / 2;    // deklaracja zmiennej middle i przypisanie jej wartości indeksu
                                                        // środkowego elementu


        mergeSort(tab, l_side, middle); // wywołanie funkcji mergeSort, która dzieli tablice po lewej stronie
        mergeSort(tab, middle + 1, r_side); // wywołanie funkcji mergeSort, która dzieli tablice po prawej stronie
        merge(tab, l_side, middle, r_side); // wywołanie funkcji merge, która sortuje tablicę
    }
}

int main()
{
    int tab[] = { 4, 13, 5325, 1231, 23, 5, 9, -1 };    // utworzenie tablicy 8-elementowej
    int tab_size = sizeof(tab) / sizeof(tab[0]);    // deklaracji zmiennej tab_size przechowującą długość tablicy

    mergeSort(tab, 0, tab_size - 1);    // wywołanie funkcji mergeSort do posortowania tablicy

    printf("Wynik sortowania tablicy: \n");
    for (int i = 0; i < tab_size; i++)  // pętla for przechodząca po wszystkich elementach posortowanej już tablicy
    {
        printf("%d ", tab[i]);  // wypisanie kolejnych elementów tablicy
    }

    return 0;
}
