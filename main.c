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
                                                // b¹dŸ równy indeksowi pierwszego elementu i
                                                // zwrócenie tablicy w takim przypadku

    int pivot = partitionFunction(tab, start_element, last_element);    // deklaracja zmiennej pivot o wartoœci zwróconej przez
                                                                        // funkcjê partitionFunction

    quickSort(tab,start_element, pivot - 1);    // wywo³anie funkcji quickSort sortuj¹c¹ elementy tablicy
                                                // po lewej stronie od zmiennej pivot

    quickSort(tab, pivot + 1, last_element);    // wywo³anie funkcji quickSort sortuj¹c¹ elementy tablicy
                                                // po prawej stronie od zmiennej pivot
}

int partitionFunction(int tab[], int start_element, int last_element)   // deklaracja funkcji partitionFunction z argumentami:
                                                                        // sortowana tablica, indeks pierwszego elementu,
                                                                        // indeks ostatniego elementu
{
    int i = start_element - 1;  // deklaracja zmiennej i o wartoœci indeksu pierwszego elementu zmniejszonego o 1
    int pivot = tab[last_element];  // deklaracja zmiennej pivot o wartoœci ostatniego elementu tablicy sortowanej

    for(int k = start_element; k <= last_element; k++)  // pêtla for, która przechodzi po wszystkich elementach tablicy
        {
        if(tab[k] < pivot)  // sprawdzenie czy wartoœæ elementu o indeksie k jest mniejszy od wartoœci zmiennej pivot
         {
            i++;    // zwiêkszenie i o 1
			int temp = tab[i];  // deklaracja tymczasowej zmiennej przechowuj¹c¹ wartoœæ elementu tablicy o indeksie i
			tab[i] = tab[k];    // tablica o indeksie i przyjmuje wartoœci tablicy o indeksie k
			tab[k] = temp;  // tablica o indeksie k przyjmuje wartoœæ tymczasow¹
         }
        }
        i++;    // zwiêkszenie i o 1
        int temp = tab[i];  // deklaracja tymczasowej wartoœci zmiennej przyjmuj¹c¹ wartoœæ elementu tablicy o indeksie i
        tab[i] = tab[last_element]; // element o indeksie i przyjmuje wartoœæ ostatniego elementu
        tab[last_element] = temp;   // ostatni element przyjmuje tymczasow¹ warotœæ

        return i;   // zwrócenie wartoœci i
}

int main()
{
    int tab[] = {2, 4, 5, 10, 23, 65, 1000, 13, -982};  // deklaracja tablicy 9-elementowe
    int tab_size = sizeof(tab) / sizeof(tab[0]);    // stworzenie zmiennej tab_size przechowujac¹ d³ugoœæ tablicy

    quickSort(tab,0,tab_size - 1);  // wywo³anie funkcji quickSort sortuj¹c¹ tablicê

    printf("Wynik sortowania tablicy: \n");
    for (int i = 0; i < tab_size; i++)  // pêtla for przechodz¹ca przez wszystkie elementy posortowanej tablicy
    {
        printf("%d ", tab[i]);  // wypisanie ka¿dego elementu posortowanej tablicy
    }
    return 0;
}
