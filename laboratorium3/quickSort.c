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
                                                // bądź równy indeksowi pierwszego elementu i
                                                // zwrócenie tablicy w takim przypadku

    int pivot = partitionFunction(tab, start_element, last_element);    // deklaracja zmiennej pivot o wartości zwróconej przez
                                                                        // funkcję partitionFunction

    quickSort(tab,start_element, pivot - 1);    // wywołanie funkcji quickSort sortującą elementy tablicy
                                                // po lewej stronie od zmiennej pivot

    quickSort(tab, pivot + 1, last_element);    // wywołanie funkcji quickSort sortującą elementy tablicy
                                                // po prawej stronie od zmiennej pivot
}

int partitionFunction(int tab[], int start_element, int last_element)   // deklaracja funkcji partitionFunction z argumentami:
                                                                        // sortowana tablica, indeks pierwszego elementu,
                                                                        // indeks ostatniego elementu
{
    int i = start_element - 1;  // deklaracja zmiennej i o wartości indeksu pierwszego elementu zmniejszonego o 1
    int pivot = tab[last_element];  // deklaracja zmiennej pivot o wartości ostatniego elementu tablicy sortowanej

    for(int k = start_element; k <= last_element; k++)  // pętla for, która przechodzi po wszystkich elementach tablicy
        {
        if(tab[k] < pivot)  // sprawdzenie czy wartość elementu o indeksie k jest mniejszy od wartości zmiennej pivot
         {
            i++;    // zwiększenie i o 1
			int temp = tab[i];  // deklaracja tymczasowej zmiennej przechowującą wartość elementu tablicy o indeksie i
			tab[i] = tab[k];    // tablica o indeksie i przyjmuje wartości tablicy o indeksie k
			tab[k] = temp;  // tablica o indeksie k przyjmuje wartość tymczasową
         }
        }
        i++;    // zwiększenie i o 1
        int temp = tab[i];  // deklaracja tymczasowej wartości zmiennej przyjmującą wartość elementu tablicy o indeksie i
        tab[i] = tab[last_element]; // element o indeksie i przyjmuje wartość ostatniego elementu
        tab[last_element] = temp;   // ostatni element przyjmuje tymczasową warotść

        return i;   // zwrócenie wartości i
}

int main()
{
    int tab[] = {2, 4, 5, 10, 23, 65, 1000, 13, -982};  // deklaracja tablicy 9-elementowe
    int tab_size = sizeof(tab) / sizeof(tab[0]);    // stworzenie zmiennej tab_size przechowujacą długość tablicy

    quickSort(tab,0,tab_size - 1);  // wywołanie funkcji quickSort sortującą tablicę

    printf("Wynik sortowania tablicy: \n");
    for (int i = 0; i < tab_size; i++)  // pętla for przechodząca przez wszystkie elementy posortowanej tablicy
    {
        printf("%d ", tab[i]);  // wypisanie każdego elementu posortowanej tablicy
    }
    return 0;
}
