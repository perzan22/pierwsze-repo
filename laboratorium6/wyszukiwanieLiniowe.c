#include <stdio.h>
#include <stdlib.h>

int wyszukanieIndeksu(int tab[], int element) {     // deklaracja funkcji wyszukujacej indeks
    int indeks = -1;    
    for (int i = 0; i < 10; i++) {      // petla for sprawdza kolejne elementy tablicy
        if (tab[i] == element) {        // jesli szukany element rowna sie wartosci w tablicy
            indeks = i;                 // to wynikiem jest indeks tego elementu w tablicy
        }
    }
    return indeks;
}


int main()
{
    printf("Prosze podac elementy tablicy.\n");
    int tab[10];    // deklaracja tablicy 10-elementowej
    for (int i = 0; i < 10; i++) {      // petla for wczytujaca z klawiatury kolejne wartosci
        int temp;
        scanf("%d", &temp);
        tab[i] = temp;                  // i przypisujaca je do tablicy
    }
    printf("Prosze podac szukany element.\n");
    int element;
    scanf("%d", &element);      // scanf do wczytania wartosci szukanej
    int wynik = wyszukanieIndeksu(tab, element);    // zmienna wynik przechowujaca indeks szukanego elementu
    if (wynik != -1) {      // jesli znaleziono indeks to
        printf("Indeks szukanego elementu w tablicy: %d", wynik);   // wypisanie indeksu 
        printf("\nAdres pamieci indeksu szukanego elementu: %p", &wynik);   // wypisanie adresu w pamieci indeksu szukanego 
    } else {                                                                // elementu
        printf("Brak szukanego elementu w tablicy.");   // informacja o braku szukanego elementu w tablicy
    }

}
