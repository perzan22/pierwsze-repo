#include <stdio.h>
#include <stdlib.h>
int top = -1;   // deklaracja globalnej zmiennej top, przechowujaca indeks ostatniego elementu stosu
int *stack;     // stworzenie wskaxnika na stos

void stack_empty(int top) {     // deklaracja funkcji stack_empty, ktora sprawdza czy stos jest pusty
    if (top == -1) {    // jesli stos jest pust to wyswietla "Stos pusty"
        printf("Stos pusty");
    } else {    // jesli stos niepusty to wyswietla "Stos niepusty"
        printf("Stos niepusty");
    }
}

void push(int element) {    // deklaracja funkcji push ktora dodaje element do stosu
    top++;  // zwiekszenie indeksu ostatniego elementu
    stack[top] = element;   // ostatni elelemnt stosu przybiera wartosc elementu
}

int pop() {     // deklaracja funkcji pop ktora usuwa ostatni element stosu
    if (top != -1) {    // jesli stos nie jest pusty
        top--;      // zmiana wartosci indeksu ostatniego elementu o jeden mniej
        return stack[top];      // zwrocenie wartosci elementu o jeden mniejszego
    } else {    // jesli stos pusty to wyswietla "Stos pusty"
        printf("Stos pusty");
    return 0;
    }
}

int Top() {     // deklaracja funkcji top ktora wyswietla ostatni element stosu
    return stack[top];
}

int main()
{
    stack = (int *) malloc(sizeof(int));    // alokacja pamieci na stos
    push(6);    // dodawanie elementow do stosu
    push(4);
    push(2);
    push(10);
    push(3);
    push(8);
    printf("Przed usunieciem: ");
    for (int i = 0; i <=top; i++) {     // petla for wypisujaca stos przed usunieciem elementow
        printf("%d ", stack[i]);
    }
    pop();      // usuwanie elementow ze stosu
    pop();
    printf("\nPo usunieciu: ");
    for (int i = 0; i <=top; i++) {     // petla for wypisujaca stos po usunieciu elementow
        printf("%d ", stack[i]);
    }
}
