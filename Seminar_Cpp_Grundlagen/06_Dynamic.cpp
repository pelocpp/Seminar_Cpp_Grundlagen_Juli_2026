#include <iostream>
#include <print>

#include <random>

// dynamic: die erste
void test_dynamic_01()
{
    int* ip = new int(123);

    /// 

    delete ip;

    // lokale Variable
    int m;
    // ...
}

// ======================


int* dynamic_allocate ()
{
    int* ip = new int(123);   // reserve data on the heap
    return ip;
}

void dynamic_work_with_data(int* data)
{
    int tmp = *data;  // read from heap

    tmp = 10 * tmp;

    *data = tmp;      // write to heap

    // brauche den Speicher nicht mehr
    delete data;
}

void dynamic_release(int* ptr)
{
    delete ptr;
}


void test_dynamic_02()
{
    int* ptr = NULL;

    ptr = dynamic_allocate();

    dynamic_work_with_data(ptr);

    dynamic_release(ptr);
}


void test_dynamic()
{
   //  std::srand (static_cast<unsigned int>(std::time(0))); 

    std::srand(  ( unsigned int)    std::time(0));

  //  std::srand(123);

    // s == seed: Samen ... Unterschiedliches zum Ausdruck bringen ...

    // 2. Variante: Ein Feld (Array) von Daten mit einer variablen Länge anlegen

    int length = 10;

    int* ip = new int[length];   // 10 int-Variablen, die im Speicher dicht hintereinander liegen

    // den Speicherbereich auf dem Heap vorbelegen
    for (int i = 0; i < 10; ++i) {

        *(ip + i) = 2 * i;          // Wirklichkeit: ip, ip + 4, ip + 8, ..., weil ein int 4 bytes belegt
    }

    // Identische, aber besser lesbare Variante
    for (int i = 0; i < 10; ++i) {

        // Ist identisch mit *(ip + i)
        // ip[i]  = 2 * i;          // Wirklichkeit: ip, ip + 4, ip + 8, ..., weil ein int 4 bytes belegt
    
        ip[i] = rand();
    }

    // Speicher aus dem Heap lesen und ausgeben
    for (int i = 0; i < 10; ++i) {

        int tmp = ip[i];
        std::println("{}: {}", i, tmp);
    }

    //char ch;
    //std::cin >> ch;

    delete[] ip;
}
