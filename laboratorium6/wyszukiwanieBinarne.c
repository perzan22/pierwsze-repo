#include <stdio.h>
#include <stdlib.h>

void insertionSort(int tab[], int size)   /* deklaracja funkcji sortujaca tablice */

{
    int j, temp;
    for (int i = 1; i < size; i++) {  /* pętla sortująca każdy element po kolei od drugiego elementu */
        temp = tab[i];  /* ustawienie tymczasowej zmiennej na wartość sprawdzanego argumentu */
        j = i - 1;
        while (j >= 0 && tab[j] > temp){    /* pętla wykonująca instrukcje jeśli j wieksze lub równe 0 i element talicy z indeksem j wiekszy od tymczasowej zmiennej */
            tab[j + 1] = tab[j];    /* zamiana sprawdzanego elementu tablicy z argumentem z prawej strony */
            j--;    /* zmniejszenie j o 1 */
            }
            tab[j + 1] = temp; /* ustawienie elementu z prawej strony na zmienną tymczasową */
        }
}

int wyszukiwanieBinarne(int tab[], int element, int lewy, int prawy) {  // deklaracja funkcji wyszukujacej szukany element
    int wynik = -1;
    if (lewy > prawy) {     // jesli lewy indeks wiekszy od prawego indeksu zwrocic -1 czyli brak szukanego elementu w tablicy
        return wynik;
    }
    int pivot_indeks = (lewy + prawy) / 2;      // ustawienie indeksu pivota na srodkowy element tabeli
    int pivot = tab[pivot_indeks];      // ustawienie wartosci pivota
    if (element > pivot) {      // jesli szukana liczba wieksza od pivota to
        return wyszukiwanieBinarne(tab, element, pivot_indeks + 1, prawy);  // rekurencyjne wywolanie funkcji wyszukujacej
    }                                                                       // ktora sprawdzi prawa strone tablicy
    if (element < pivot) {      // jesli szukana liczba mniejsza od pivota to
       return wyszukiwanieBinarne(tab, element, lewy, pivot_indeks - 1);    // rekurencyjne wywolanie funkcji wyszukujacej
    }                                                                       // ktora sprawdzi lewa strone tablicy
    if (element == pivot) {     // jesli pivot rowna sie liczbie szukanej to
        wynik = pivot_indeks;   // wynikiem bedzie wartosc indeksu pivota
    }
    return wynik;
}


int main()
{
    int tab[10] = {14, 2, 22, 34, 19, 25, 10, 1, 33, 11};   // deklaracja tablicy 10-elementowe
    int tab_size = sizeof(tab) / sizeof(tab[0]);    // zmienna przechowujaca wielkosc tablicy

    insertionSort(tab, tab_size);   // wywolanie funkcji sortujacej

    int element;
    printf("Prosze podac szukany element: ");   // prosba o wpisanie szukanej liczby
    scanf("%d", &element);      // scanf do odczytania liczby szukanej

    int indeks = wyszukiwanieBinarne(tab, element, 0, tab_size - 1);    // przypisanie wartosci indeksu przez wywolanie funkcji
                                                                        // wyszukujacej indeks
    if (indeks != -1) {
        printf("Indeks szukanego elementu to: %d", indeks);     // wypisanie wartosci indeksu
    } else {
        printf("Brak szukanego elementu w tablicy.");           // lub informacji o braku szukanego elementu w tablicy
    }
}
