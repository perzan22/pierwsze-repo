// Dijkstra's Algorithm in C

#include <stdio.h>
#define INFINITY 9999       // ustawienie wartości INFINITY na 9999
#define MAX 10              // ustawienie wartości MAX na 10

void Dijkstra(int Graph[MAX][MAX], int n, int start);

void Dijkstra(int Graph[MAX][MAX], int n, int start) {      // deklaracja funkcji Dijkstra
  int cost[MAX][MAX], distance[MAX], pred[MAX];             // deklaracja tablic cost, distance, pred,
  int visited[MAX], count, mindistance, nextnode, i, j;     // visited i zmiennych count, minidistance, nextnode, i oraz j

  for (i = 0; i < n; i++)       // zagniezdzona petla for oblicza koszt drogi od punktu wybranego
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;  // jesli nie ma drogi do punktu (sprawdzany wierzchołek nie graniczy z wybranym) to ustawia
      else                      // wartosc na INFINITY
        cost[i][j] = Graph[i][j];   // jesli wierzcholek graniczy z wybranym to koszt równa się wpisanej wartosci w tabeli

  for (i = 0; i < n; i++) {         // petla for ustawia dystans poczatkowy dla wszystkich wierzchołków od wybranego
    distance[i] = cost[start][i];   // na wartosc 0
    pred[i] = start;
    visited[i] = 0;                 // tablica odwiedzonych wierzcholkow rowniez jest wypelniana 0
  }

  distance[start] = 0;              // dystans dla poczatkowego wierzcholka wynosi 0
  visited[start] = 1;               // pierwszy wierzcholek zostal odwiedzony
  count = 1;

  while (count < n - 1) {       // petla while przechodzi po wierzcholkach od pierwszego po poczatkowym, az do ostatniego
    mindistance = INFINITY;     // minimalny dystans przyjmuje wartosc INFINITY

    for (i = 0; i < n; i++)                                 // petla for ustawia minimalny dystans od kolejnego wierzcholka
      if (distance[i] < mindistance && !visited[i]) {       // dla tego, ktory ma mniejsza wage
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;                                      // kolejny wierzcholek zostal odwiedzony
    for (i = 0; i < n; i++)                                     // petla for dodaje do siebie minimalny dystans do kosztu
      if (!visited[i])                                          // poprzednich odwiedzonych wczesniej wierzcholkow
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }


  for (i = 0; i < n; i++)                                           // petla for drukuje odleglosc wierzcholka od poczatkowego
      printf("\nDystans od wierzcholka A do %c: %d", i + 65, distance[i]);  // ZMIANA OD ORYGINALU DRUKUJE LITRY ZAMIAST LICZB

}
int main() {
  int Graph[MAX][MAX], i, j, n, u;      // deklaracja tabeli Graph oraz zmiennych i, j, n, u
  n = 5;

  Graph[0][0] = 0;      // utworzenie grafu, gdzie pierwszy indeks oznacza numer wierzcholka,
  Graph[0][1] = 6;      // drugi indeks to inny wierzcholek w grafie
  Graph[0][2] = 0;      // liczba po rownaniu to waga drogi, jesli wynosi zero to oznacza, ze jest to ten sam wierzcholek
  Graph[0][3] = 1;      // lub nie ma polaczenia miedzy wierzcholkami
  Graph[0][4] = 0;

  Graph[1][0] = 6;
  Graph[1][1] = 0;
  Graph[1][2] = 5;
  Graph[1][3] = 2;
  Graph[1][4] = 2;

  Graph[2][0] = 0;
  Graph[2][1] = 5;
  Graph[2][2] = 0;
  Graph[2][3] = 0;
  Graph[2][4] = 5;

  Graph[3][0] = 1;
  Graph[3][1] = 2;
  Graph[3][2] = 0;
  Graph[3][3] = 0;
  Graph[3][4] = 1;

  Graph[4][0] = 0;
  Graph[4][1] = 2;
  Graph[4][2] = 5;
  Graph[4][3] = 0;
  Graph[4][4] = 1;

  u = 0;
  Dijkstra(Graph, n, u);        // wywolanie funkcji Dijkstra, ktora oblicza najkrotsza droge od wierzcholka

  return 0;
}

