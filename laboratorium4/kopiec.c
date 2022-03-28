#include <stdio.h>
#include <stdlib.h>

int size = 0;   // deklaracja globalnej zmiennej size przechowujaca wielkosc kopca

void heapify(int tab[], int size, int i) {  // deklaracja funkcji heapify() przywracajaca wlasnosc kopca
    if (size == 1) {    // jesli kopiec ma wielkosc 1 to wypisac
        printf(tab);
    }
    else {  // jesli kopiec wiekszy niz jeden to zrobic ponizsze instrukcje
        int max = i;    // ustwienie zmiennej max na indeks obecnego elementu
        int l_dziecko = 2 * i + 1;  // ustawienie indeksu lewego dziecka
        int p_dziecko = 2 * i + 2;  // ustawienie indeksu prawego dziecka
        if (l_dziecko < size && tab[l_dziecko] > tab[max]) {    // jesli wartosc lewego dziecka wieksza od obecnej wartosci
            max = l_dziecko;                                    // to ustawic maksymalna wartosc na wartosc lewego dziecka
        }
        if (p_dziecko < size && tab[p_dziecko] > tab[max]) {    // jesli wartosc prawego dziecka wieksza od obecnej wartosci
            max = p_dziecko;                                    // to ustawic maksymalna wartosc na wartosc prawego dziecka
        }
        if (max != i) {     // jesli znaleziiono wieksze dziecko
            change(&tab[i], &tab[max]);     // to zmiana miejscem wartosci z indeksem i oraz wartosci maksymalnej
            heapify(tab, size, max);    // rekurencyjne wywolanie heapify()
        }
    }
}

void change (int *x, int *y) {      // deklaracje funkcji change() zmieniajaca miejscami elementy tablicy
    int temp = *y;
    *y = *x;
    *x = temp;
}

void insert(int tab[], int newValue) {      // deklaracja funkcji insert() dodajaca wartosci do kopca
    if (size == 0) {    // jesli kopiec pusty
        tab[0] = newValue;  // to dodac wartosc na pierwszy element kopca
        size += 1;  // zwiekszyc wielkosc kopca o 1
    }
    else {  // jesli kopiec nie jest pusty
        tab[size] = newValue;   // to dodac wartosc do kopca
        size += 1;  // zwiekszenie wielkosci kopca o 1
        for (int i = size / 2 - 1; i >= 0; i--) {   // petla for wywolujaca rekurencyjnie finkcje heapify() do przywracania
            heapify(tab, size, i);                  // wlasnosci kopca po dodawaniu elementow
        }
    }
}

int main()
{
    int tabela[100];    // deklaracja tabeli ktora przechowuje elementy kopca
    insert (tabela, 8);     // dodawanie elementow kopca
    insert (tabela, 12);
    insert (tabela, 20);
    insert (tabela, 6);
    insert (tabela, 9);
    insert (tabela, 19);
    insert (tabela, 10);
    insert (tabela, 4);
    insert (tabela, 16);
    insert (tabela, 3);
    insert (tabela, 14);

    for (int i = 0; i < size; i++) {    // petla for wypisujaca caly kopiec
        printf("%d ", tabela[i]);
    }
    return 0;
}


