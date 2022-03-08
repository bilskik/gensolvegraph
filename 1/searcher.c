//solver wywołuje funkcję research i przypisuje zwracaną tabele struktur do tabeli struktur w solverze  
#include "searcher.h"

#include <stdlib.h>
#include <float.h>

prev_and_weight_t *searcher(){//required (((row&&column) || index) && dane && start)
    int row = 2;
    int column = 2;
    int start =0;
    int index = row*column-1;
    prev_and_weight_t *tab = malloc (index*sizeof(prev_and_weight_t));
//K01: 	S  ← Ø 	zbiór S ustawiamy jako pusty
    int S[index];
    for (int i = 0; i < index; i++) {
        S[i] = 0;
    }
//K02: 	Q  ← wszystkie wierzchołki grafu 
    int Q[index];	 
    for (int i = 0; i < index; i++) {
        Q[i] = 1;
    }
//K03: 	Utwórz n  elementową tablicę d 	tablica na koszty dojścia
//K04: 	Utwórz n  elementową tablicę p 	tablica poprzedników na ścieżkach
//Kroki 03 i 04 wykonuje struktura prev&weight
//K05: 	Tablicę d  wypełnij największą
//wartością dodatnią 
    for(int i = 0; i < index; i++)
        tab[i].d = DBL_MAX;

//K06: 	d [ v  ] ← 0 	
    tab[start].d = 0;
//K07: 	Tablicę p  wypełnij wartościami -1 	
    for (int i = 0; i < index; i++) {
        tab[i].p = -1;
    }
//K08: 	Dopóki Q  zawiera wierzchołki,
//wykonuj kroki K09...K12
int isboolean = 1;
    while (isboolean) {
    //K09: 	    Z Q  do S  przenieś wierzchołek u
    //    o najmniejszym d [ u  ] 	 
    //K10: 	    Dla każdego sąsiada w  wierzchołka u :
    //    wykonuj kroki K11...K12 	przeglądamy sąsiadów przeniesionego wierzchołka
    //    K11: 	        Jeśli w  nie jest w Q,
    //        to następny obieg pętli K10 	szukamy sąsiadów obecnych w Q
    //    K12: 	        Jeśli d [ w  ] > d [ u  ] + waga krawędzi u–w,
    //        to:
    //            d [ w  ] ← d [ u  ] + waga krawędzi u–w
    //            p [ w  ] ← u 	sprawdzamy koszt dojścia. Jeśli mamy niższy, to modyfikujemy koszt i zmieniamy poprzednika w na u
    isboolean = 0;
    for(int i = 0; i < index; i++) 
        if(Q[i]) {
            isboolean = 1;
            break;        
        }    
    }
    return tab;
}