
#include <iostream>
#include <print>
#include <random>

namespace Rule_of_Three
{
    // Puffer von int Variablen
    class BigData
    {
    private:
        int  m_count;
        int* m_buffer;
    
    public:
        // c'tors
        BigData() {
            m_count = 0;
            m_buffer = NULL;
        }

        BigData(int count) {
            m_count = count;
            m_buffer = new int [count];  // Puffer auf der Halde anlegen
        }

        // Kopier-Konstruktor
        BigData(const BigData& other) {         // Call-by-Reference

            m_count = other.m_count;
            // m_buffer = other.m_buffer;   // Stop: Hier wird die Adresse KOPIERT: FALSCH

            m_buffer = new int[other.m_count];        // einen neuen Puffer anlegen

            for (int i = 0; i < other.m_count; ++i) { // den existierenden Pufferinhalt in den neuen Puffer umkopieren.
                m_buffer[i] = other.m_buffer[i];
            }
        }

        // Wertzuweisungs-Operator
        void operator= (const BigData& other) {                // Call-by-Reference
             
            // es gibt eine gültige, vorhandene linke Seite
            delete[] m_buffer;

            // other in das aktuelle Objekt aufnehmen
            m_count = other.m_count;

            m_buffer = new int[other.m_count];        // einen neuen Puffer anlegen

            for (int i = 0; i < other.m_count; ++i) {  // den existierenden Pufferinhalt in den neuen Puffer umkopieren.
                m_buffer[i] = other.m_buffer[i];
            }
        }

        // d'tor
        ~BigData() {
            delete[] m_buffer;
        }
    };

}

void test_rule_of_three()
{
    using namespace Rule_of_Three;

    BigData myData(5);

    // a) Wertzuweisung von Objekten:  operator=
     BigData myData2;
     myData2 = myData;           // Hier haben wir eine Wertzuweisung: operator=  // in diesem Fall muss auch dieser explizit implementiert werden

    // b) Kopie eines Objekts:         Kopierender Konstruktor: Kopiert alle Wert 1:1 um // Problematisch bei ADRESSEN !!!
    BigData myData3(myData);
}