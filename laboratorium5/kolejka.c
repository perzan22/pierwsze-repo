#include <stdio.h>
#include <stdlib.h>
int top = 0;    // deklaracja zmiennej globalnej przechowujaca indeks ostatniego elementu
int *queue;     // wskaznik kolejki


void enqueue(int element) {     // deklaracja funkcji enqueue dodajaca element na poczatek kolejki
    top++;      // zwiekszenie wartosci indeksu ostatniego elementu kolejki
    if (top > 1) {                      // jezeli kolejka ma wiecej niz jeden element wykonac
    for (int i =top; i > 0; i--) {      // przeniesienie elementow o jeden do przodu
        queue[i] = queue[i - 1];
    }
    }
    queue[0] = element;     // pierwszym elelemntem zostaje wprowadzona liczba
}

void dequeue() {
    if (top != 0) {    // jesli kolejka nie jest pusta
        top--;      // zmiana wartosci indeksu ostatniego elementu o jeden mniej
        return queue[top];      // zwrocenie wartosci elementu o jeden mniejszego
    } else {    // jesli kolejka pusta to wyswietla "Kolejka pusta"
        printf("Kolejka pusty");
    return 0;
    }
}


int main()
{
    queue = (int *) malloc(sizeof(int));    // alokacja pamieci na kolejke
    enqueue(3);     // dodanie 5 elementow do kolejki
    enqueue(10);
    enqueue(2);
    enqueue(12);
    enqueue(5);
    printf("Przed usunieciem: ");
    for (int i = 0; i < top; i++ ){     // petla for wypisujaca elementy kolejki przed usunieciem
        printf("%d ", queue[i]);
    }
    dequeue();      // usuniecie ostatniego elementu kolejki
    printf("\nPo usunieciu: ");
    for (int i = 0; i < top; i++ ){     // petla for wypisujaca elementy kolejki po usunieciu
        printf("%d ", queue[i]);
    }
}
