#include <stdio.h>
#include <stdlib.h>

//############################
//#     MERGE SORT !!!!!!!   #
//############################

void merge(int tab[], int l_side, int middle, int r_side)   // deklaracja funkcji merge z argumentami:
                                                            // tablica sortowana, indeks pierwszego argumentu,
                                                            // indeks �rodkowego elementu i indeks oststniego elementu
{
    int i, j, k;    // deklaracja zmiennych i, j, k
    int n1 = middle - l_side + 1;   // deklaracja d�ugo�ci tablicy L_temp, r�wnej indeksowi
                                    // �rodkowego elementu zmniejszonego o indeks pierwszego elementu, zwi�kszonej o 1

    int n2 = r_side - middle;   // deklaracja d�ugo�ci tablicy R_temp, r�wnej indeksowi ostatniego elementu zmniejszonego
                                // o indeks �rodkowego elementu

    int L_temp[n1], R_temp[n2]; // deklaracja tablic tymczasowych zawieraj�cych elementy tablicy z lewej strony (L_temp)
                                // oraz prawej strony (R_temp)


    for (i = 0; i < n1; i++)    // p�tla for, kt�ra wykona przej�cia po wszystkich elementach tablicy L_temp
    {
        L_temp[i] = tab[l_side + i];    // przypisanie do tymczasowej tablicy, elementy sortowanej tablicy z lewej strony
    }

    for (j = 0; j < n2; j++)    // p�tla for, kt�ra wykona przej�cia po wszystkich elementach tablicy R_temp
    {
        R_temp[j] = tab[middle + 1 + j];    // przypisanie do tymczasowej tablicy, elementy sortowanej tablicy z prawej strony
    }


    i = 0;  // przypisanie zmiennej i warto�ci 0
    j = 0;  // przypisanie zmiennej j warto�ci 0
    k = l_side; // przypisanie zmiennej k warto�� indeksu pierwszego elementu sortowanej tablicy

    while (i < n1 && j < n2)    // p�tla while, wykonuj�ca przej�cia po wszystkich elementach tablic tymczasowych dop�ki zmienne
                                // i oraz j s� obie mniejsze od rozmiar�w tablic tymczasowych
        {
            if (L_temp[i] <= R_temp[j]) // sprawdzenie czy warto�� elementu lewej tymczasowej tablicy o indeksie i jest
                                        // mniejszy b�d� r�wny warto�ci elementu prawej tymczasowej tablicy o indeksie j
            {
                tab[k] = L_temp[i]; // przypisanie elementowi tablicy sortowanej o indeksie k, warto�ci elementu lewej tablicy
                                    // tymczasowej o indeksie i, je�li spe�niony warunek zdania warunkowego if
                i++;    // zwi�kszenie i o 1
            }
            else
            {
                tab[k] = R_temp[j]; // przypisanie elementowi tablicy sortowanej o indeksie k, warto�ci elementu prawej tablicy
                                    // tymczasowej o indeksie j, je�li nie zosta� spe�niony warunek zdania warunkowego if
                j++;    // zwi�kszenie j o 1
            }
        k++;    // zwi�kszenie k o 1
        }


    while (i < n1)  // p�tla while wykonuj�ca przej�cia po pozosta�ych elementach lewej tymczasowej tablicy
        {
            tab[k] = L_temp[i]; // przypisanie elementowi tablicy sortowanej o indeksie k, warto�ci elementu lewej tablicy
                                // tymczasowej o indeksie i
            i++;    // zwi�kszenie i o 1
            k++;    // zwi�kszenie k o 1
        }

    while (j < n2)  // p�tla while wykonuj�ca przej�cia po pozosta�ych elementach prawej tymczasowej tablicy
        {
            tab[k] = R_temp[j]; // przypisanie elementowi tablicy sortowanej o indeksie k, warto�ci elementu prawej tablicy
                                // tymczasowej o indeksie j
            j++;    // zwi�kszenie j o 1
            k++;    // zwi�kszenie k o 1
        }
}


void mergeSort(int tab[], int l_side, int r_side)   // deklaracja funkcji mergeSort z argumentami:
                                                    // tablica sortowana, indeks pierwszego elementu, indeks ostatniego elementu
{
    if (l_side < r_side) {  // sprawdzenie czy indeks pierwszego elementu jest mniejszy od ostatniego elementu

        int middle = l_side + (r_side - l_side) / 2;    // deklaracja zmiennej middle i przypisanie jej warto�ci indeksu
                                                        // �rodkowego elementu


        mergeSort(tab, l_side, middle); // wywo�anie funkcji mergeSort, kt�ra dzieli tablice po lewej stronie
        mergeSort(tab, middle + 1, r_side); // wywo�anie funkcji mergeSort, kt�ra dzieli tablice po prawej stronie
        merge(tab, l_side, middle, r_side); // wywo�anie funkcji merge, kt�ra sortuje tablic�
    }
}

int main()
{
    int tab[] = { 4, 13, 5325, 1231, 23, 5, 9, -1 };    // utworzenie tablicy 8-elementowej
    int tab_size = sizeof(tab) / sizeof(tab[0]);    // deklaracji zmiennej tab_size przechowuj�c� d�ugo�� tablicy

    mergeSort(tab, 0, tab_size - 1);    // wywo�anie funkcji mergeSort do posortowania tablicy

    printf("Wynik sortowania tablicy: \n");
    for (int i = 0; i < tab_size; i++)  // p�tla for przechodz�ca po wszystkich elementach posortowanej ju� tablicy
    {
        printf("%d ", tab[i]);  // wypisanie kolejnych element�w tablicy
    }

    return 0;
}
