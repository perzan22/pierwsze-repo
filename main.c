#include <stdio.h>
#include <stdlib.h>

// ###################
// #     QUICKSORT   #
// ###################

void quickSort(int tab[], int start_element, int last_element)  // deklaracja funkcji quickSort z argumentami:
                                                                // tablica sortowana, indeks pierwszego elementu, indeks
                                                                // ostatniego elementu
{
    if (last_element <= start_element) return;  // sprawdzenie, czy indeks ostatniego elementu jest mniejszy,
                                                // b�d� r�wny indeksowi pierwszego elementu i
                                                // zwr�cenie tablicy w takim przypadku

    int pivot = partitionFunction(tab, start_element, last_element);    // deklaracja zmiennej pivot o warto�ci zwr�conej przez
                                                                        // funkcj� partitionFunction

    quickSort(tab,start_element, pivot - 1);    // wywo�anie funkcji quickSort sortuj�c� elementy tablicy
                                                // po lewej stronie od zmiennej pivot

    quickSort(tab, pivot + 1, last_element);    // wywo�anie funkcji quickSort sortuj�c� elementy tablicy
                                                // po prawej stronie od zmiennej pivot
}

int partitionFunction(int tab[], int start_element, int last_element)   // deklaracja funkcji partitionFunction z argumentami:
                                                                        // sortowana tablica, indeks pierwszego elementu,
                                                                        // indeks ostatniego elementu
{
    int i = start_element - 1;  // deklaracja zmiennej i o warto�ci indeksu pierwszego elementu zmniejszonego o 1
    int pivot = tab[last_element];  // deklaracja zmiennej pivot o warto�ci ostatniego elementu tablicy sortowanej

    for(int k = start_element; k <= last_element; k++)  // p�tla for, kt�ra przechodzi po wszystkich elementach tablicy
        {
        if(tab[k] < pivot)  // sprawdzenie czy warto�� elementu o indeksie k jest mniejszy od warto�ci zmiennej pivot
         {
            i++;    // zwi�kszenie i o 1
			int temp = tab[i];  // deklaracja tymczasowej zmiennej przechowuj�c� warto�� elementu tablicy o indeksie i
			tab[i] = tab[k];    // tablica o indeksie i przyjmuje warto�ci tablicy o indeksie k
			tab[k] = temp;  // tablica o indeksie k przyjmuje warto�� tymczasow�
         }
        }
        i++;    // zwi�kszenie i o 1
        int temp = tab[i];  // deklaracja tymczasowej warto�ci zmiennej przyjmuj�c� warto�� elementu tablicy o indeksie i
        tab[i] = tab[last_element]; // element o indeksie i przyjmuje warto�� ostatniego elementu
        tab[last_element] = temp;   // ostatni element przyjmuje tymczasow� warot��

        return i;   // zwr�cenie warto�ci i
}

int main()
{
    int tab[] = {2, 4, 5, 10, 23, 65, 1000, 13, -982};  // deklaracja tablicy 9-elementowe
    int tab_size = sizeof(tab) / sizeof(tab[0]);    // stworzenie zmiennej tab_size przechowujac� d�ugo�� tablicy

    quickSort(tab,0,tab_size - 1);  // wywo�anie funkcji quickSort sortuj�c� tablic�

    printf("Wynik sortowania tablicy: \n");
    for (int i = 0; i < tab_size; i++)  // p�tla for przechodz�ca przez wszystkie elementy posortowanej tablicy
    {
        printf("%d ", tab[i]);  // wypisanie ka�dego elementu posortowanej tablicy
    }
    return 0;
}
