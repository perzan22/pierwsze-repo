#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define V 11            // liczba wierzcholkow w grafie
#define INF 99999       // duza liczba zastepujaca nieskonczonosc

int size = 0;           // wielkosc kopca

void change (int *x, int *y) {      // deklaracje funkcji change() zmieniajaca miejscami elementy tablicy
    int temp = *y;
    *y = *x;
    *x = temp;
}

void heapify(int tab[], int size, int i) {                  // deklaracja funkcji heapify() przywracajaca wlasnosc kopca
        int min = i;                                        // ustwienie zmiennej min na indeks obecnego elementu
        int l_dziecko = 2 * i + 1;                          // ustawienie indeksu lewego dziecka
        int p_dziecko = 2 * i + 2;                          // ustawienie indeksu prawego dziecka
        if (l_dziecko < size && tab[l_dziecko] < tab[i]) {  // jesli wartosc lewego dziecka mniejsza od obecnej wartosci
            min = l_dziecko;                                // to ustawic mainimalna wartosc na wartosc lewego dziecka
        }
        if (p_dziecko < size && tab[p_dziecko] < tab[min]) {    // jesli wartosc prawego dziecka mniejsza od obecnej wartosci
            min = p_dziecko;                                    // to ustawic minimalna wartosc na wartosc prawego dziecka
        }
        if (min != i) {                     // jesli znaleziiono mniejsze dziecko
            change(&tab[i], &tab[min]);     // to zmiana miejscem wartosci z indeksem i oraz wartosci minimalnej
            heapify(tab, size, min);        // rekurencyjne wywolanie heapify()
        }
    }

int extract_min(int tab[]) {            // funkcja extract_min znajdujaca minimalny element kopca i usuwajaca go z kopca
    int min = tab[0];                   // minimalna wartosc to korzen kopca (element z indeksem 0)
    tab[0] = tab[size-1];               // podstawienie innego elementu za korzen
    size--;                             // zmniejszenie rozmiaru kopca o 1
    heapify(tab, size, tab[0]);         // przywrocenie wlasnosci kopca po usunieciu korzenia
    return min;                         // zwrocenie wartosci najmniejszej w kopcu
}

void insert(int tab[], int newValue) {      // deklaracja funkcji insert() dodajaca wartosci do kopca
    if (size == 0) {                        // jesli kopiec pusty
        tab[0] = newValue;                  // to dodac wartosc na pierwszy element kopca
        size += 1;                          // zwiekszyc wielkosc kopca o 1
    }
    else {                                              // jesli kopiec nie jest pusty
        tab[size] = newValue;                           // to dodac wartosc do kopca
        size += 1;                                      // zwiekszenie wielkosci kopca o 1
        for (int i = size / 2 - 1; i >= 0; i--) {       // petla for wywolujaca rekurencyjnie funkcje heapify() do przywracania
            heapify(tab, size, i);                      // wlasnosci kopca po dodawaniu elementow
        }
    }
}

bool check(int tab[], int num) {            // funkcja check sprawdxajaca czy dany element jest w tablicy
    bool checked = false;                   // zmienna checked przechowuje informacje czy znaleziono element w tablicy
    for (int i = 0; i < size; i++) {        // petla for przechodzaca po kazdej komorce tablicy aby sprawdzic czy wystepuje
        if (tab[i] == num) {                // w niej szukany element
            checked = true;                 // jesli tak to zmienna checked zmienia wartosc na true
        }
    }
    return checked;                         // zwrocenie wartosci checked
}

bool isEmpty (int tab[]) {                  // funkcja isEmpty sprawdzajaca czy kopiec jest pusty
    bool checked;                           // zmienna checked przechowuje informacje czy kopiec jest pusty
    if (size == 0) {                        // jesli wielkosc kopca wynosi 0 to znaczy ze kopiec jest pusty
        checked = true;                     // zmienna checked zmienia wartosc na true
    } else {
    checked = false;
    }
    return checked;                         // zwrocenie wartosci zmiennej checked
}

void setRoot(int tab[], int num) {          // funkcja setRoot ustawiajaca korzen kopca na inny element kopca
    heapify(tab, size, 0);                  // przywrocenie wlasnosci kopca funkcja heapify
    for (int i = 0; i < size; i++) {        // petla for przechodzaca
        if (num == tab[i]) {                // jesli num jest rowny sprawdzanej komorce kopca
            change(&tab[i], &tab[0]);       // to zamiana miejscami korzenia ze sprawdzana komorka
        }
    }
}

bool isSmallestNotVisited(int tab[], int num, int notVis[]) {   // funkcja isSmallestNotVisited sprawdzjaca czy waga krawedzi MDR
    bool checked = true;                                        // jest najmniejsza sposrod pozostalych nieodwiedzonych wczesniej
    for (int i = 1; i < V; i++) {                               // petla for porownuje sprawdzana wartosc do pozostalych wag
        if (num > tab[i] && check(notVis, i)) {                 // jesli waga jest wieksza od ktoregokolwiek z pozostalych wag
            checked = false;                                    // i sa to tylko nieodwiedzone wierzcholki to nalezy zwrocic
        }                                                       // wartosc false poniewaz nie jest to najmniejsza waga
    }
    return checked;
}

void algPrim(int G[], int r, int w[][V]) {                  // funkcja algPrim wyznaczajaca MDR grafu
    int Q[V];           // tablica Q przechowuje kopiec z wierzcholkami
    int key[V];         // tablica key przechowuje najmniejsze wagi z wierzcholka do MDR
    int pi[V];          // tablica pi przechowuje wierzcholki do ktorych waga krawedzi jest najmniejsza

    for (int i = 0; i < V; i++) {       // petla for wstawia kolejne wierzcholki do kopca
        insert(Q, G[i]);
    }

    for (int i = 0; i < V; i++) {       // petla for poczatkowo wstawia do tablicy z wagami wartosc INF (nieskonczonosc)
        key[i] = INF;
    }
    key[r] = 0;         // waga dla poczatkowego wierzcholka wynosi 0
    pi[r] = 0;          // poniewaz wierzcholek jest poczatkowy to za wierzcholek z ktorym sie laczy uznalem ten sam wierzcholek

    while(!isEmpty(Q)) {                // dopoki kolejka nie jest pusta nalezy wykonywac algorytm
        int u = extract_min(Q);         // zmienna u przechowuje nieodwiedzony wierzcholek ktory ma najmniejsza wage do MDR
        int adj[V];                     // tablica adj przechowuje wagi wierzcholka u do innych wierzcholkow
        for (int i = 1; i < V; i++) {   // petla for wpisuje wagi do tablicy adj
            adj[i] = w[u][i];
        }
        for (int i = 1; i < V; i++) {                       // petla for przechodzaca po kazdej wadze od wierzcholka u
            if (adj[i] != 0) {                              // jesli wierzcholek nie jest oddalony o 2 krawedzie
                int t = adj[i];                             // to zmienna t przechowuje wage do wierzcholka i
                if (check(Q, i) && t <= key[i]) {           // jesli t jest mniejsze od aktualnej wartosci w tablicy k i
                    pi[i] = u;                              // wierzcholek i nie zostal wczesniej odwiedzony to wartosc t nalezy
                    key[i] = t;                             // wpisac do tablicy z najmniejszymi wagami, a wierzcholek u do
                }                                           // tablicy pi z wierzcholkami do ktorych waga jest najmniejsza
                if (isSmallestNotVisited(key, key[i], Q)) { // jesli najmniejsza waga z wierzcholka i jest najmniejsza i ten
                    setRoot(Q, i);                          // wierzcholek nie zostal wczesniej odwiedzony to ustawic korzen
                }                                           // kopca jako wlasnie ten wierzcholek
            }
        }
    }

    for (int i = 0; i < V; i++) {                   // petla for wypisujaca kolejne wierzcholki grafu G
        printf("%c ",G[i] + 65);
    }
    printf("\n");

    for (int i = 0; i < V; i++) {                   // petla for wypisujaca kolejne najmniejsze wagi krawedzi MDR
        printf("%d ",key[i]);
    }
    printf("\n");

    for (int i = 0; i < V; i++) {                   // petla for wypisujaca wierzcholki do ktorych waga krawedzi byla najmniejsza
        printf("%c ", pi[i] + 65);
    }
    printf("\n");

    int mdr = 0;
    for (int i = 0; i < V; i++) {                   // petla for wypisujaca sume krawedzi MDR
        mdr = mdr + key[i];
    }
    printf("Suma krawedzi MDR wynosi %d", mdr);
}

int main()
{
    int G[V] = {0,1,2,3,4,5,6,7,8,9,10};        // wierzcholki grafu G
    int w[V][V] = {
        {0,0,1,4,5,5,0,0,22,0,0},               // wagi krawedzi miedzy wierzcholkami grafu G, wartosc 0 oznacza, ze wierzcholki
        {0,0,16,0,0,0,0,0,3,30,0},              // nie sa bezposrednio polaczone krawedzia lub jest to ten sam wierzcholek
        {1,16,0,1,0,0,0,0,0,0,0},
        {4,0,1,0,1,0,0,0,0,0,0},
        {5,0,0,1,0,12,0,0,0,0,0},
        {5,0,0,0,12,0,27,0,0,0,0},
        {0,0,0,0,0,27,0,5,0,10,18},
        {0,0,0,0,0,0,5,0,5,20,0},
        {22,3,0,0,0,0,0,5,0,25,0},
        {0,30,0,0,0,0,10,20,25,0,3},
        {0,0,0,0,0,0,18,0,0,3,0}
    };
    int r = 0;                                  // wierzcholek startowy A
    algPrim(G,r,w);                             // wywolanie funkcji algPrim wyznaczajacej MDR
}


