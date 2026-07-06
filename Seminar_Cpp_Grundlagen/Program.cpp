
#include "Time.h"

#include <print>
#include <iostream>

// externe Funktionen
extern void test_pointer_references();

int main()
{
    test_pointer_references();

    return 1;
}

// Hello World
int main_hello_world()
{
    std::cout << "Hallo Seminar";

    char ch;
    std::cin >> ch;

    return 0;
}




void stolperfalle()
{
    Time now;              // Konstruktor ohne Parameter: Keine Klammern
    now.print();

    Time than(13, 0, 0);   // Konstruktor mit 3 Parametern: Jetzt mit Klammern
}



// Beispiel für Klasse Time
int main_example_time()
{
    int n = 0;

    Time now;     // erstes Objekt: 2 Aktionen: a) Speicher bereitstellen // b) Konstruktor auf diesem Speicher ausführen
    Time later;   // zweites Objekt

    Time evening (9999, 59, 0);   // Konstruktor verbinden

    // Zugriff auf Member Variablen: Punkt Operator
    
    //  now.m_hours = 9999;   // dieser direkte Zugriff wird verboten, um korrekte Daten im Objekt zu garantieren !!!
    //now.m_minutes = 27;
    //now.m_seconds = 30;

    //later.m_hours = 12;
    //later.m_minutes = 30;
    //later.m_seconds = 0;

    evening.print();
   
    now.setHours(9999);
    now.setHours(11);
    now.setMinutes(31);
    now.setSeconds(30);

    later.setHours(12);
    later.setMinutes(30);
    later.setSeconds(0);

   // int aktuelleMinuten = now.m_minutes;
    int aktuelleMinuten = now.getMinutes();
    std::println("Now hat {} Minuten", aktuelleMinuten);

    // Beispiel:  11:31:30  ==> 11 * 60 * 60 + 31 * 60 + 30

    int tmp = 11 * 60 * 60 + 31 * 60 + 30;

    int totalSeconds = now.getTotalSeconds();

    // Zugriff auf Methoden: Punkt Operator
    now.print();
    later.print();

    // 
    return 1;
}

