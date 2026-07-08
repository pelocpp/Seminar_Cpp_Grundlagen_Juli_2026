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


// Dynamic_Memory_Lottery::LotteryTickets

namespace Dynamic_Memory_Lottery
{
    class LotteryTickets
    {
    private:
        int  m_count;
        int* m_tickets;

    public:
        LotteryTickets() : m_count(0), m_tickets(NULL)
        {
            std::srand(static_cast<unsigned int>(std::time(0))); // use current time as seed for random generator
        }

        ~LotteryTickets() {
            delete[] m_tickets;
            // m_tickets = NULL;   // NEIN, das ist überflüssig, der Speicher des Objekts wird ja gerade freigegeben
        }

        void buyTickets(int count)
        {
            m_count = count;
            m_tickets = new int[m_count];   // buying 'count' tickets at once

            for (int i = 0; i < m_count; i++) {
                m_tickets[i] = 1 + rand() % 49;
            }
        }

        void printTickets()
        {
            for (int i = 0; i < m_count; i++) {
                std::cout << "Ticket " << (i + 1) << ": " << m_tickets[i] << std::endl;
            }
        }

        void release() {
            delete[] m_tickets;
            m_tickets = NULL;
        }
    };
}

void aufgabe_lottery()
{
    std::cout << "How many lottery tickets do you want to buy? ";

    int numTickets;
    std::cin >> numTickets;

    Dynamic_Memory_Lottery::LotteryTickets lottery;
    lottery.buyTickets(numTickets);
    lottery.printTickets();
    lottery.release();
    // ... noch was anderes .....

    lottery.buyTickets(numTickets);
    lottery.printTickets();
    lottery.release();

}

