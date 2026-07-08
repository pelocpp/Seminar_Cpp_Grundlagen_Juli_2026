
#include <vector>
#include <print>
#include <list>
#include <algorithm>
#include <deque>
#include <string>

static void test_stl_01()
{
    // Vector // ähnlich zu Python Liste
    std::vector<int> numbers;

   // numbers.reserve(80);

    for (int i = 0; i < 100; ++i) {

        numbers.push_back(2 * i);   // like append in Python

        std::println("{}: size={}    capacity={}", i, numbers.size(), numbers.capacity());
    }

    // hier kommt mit Sicherheit nichts mehr dazu
    numbers.shrink_to_fit();
    std::println("    size={}    capacity={}", numbers.size(), numbers.capacity());
}


static void test_stl_02()
{
    std::vector<int> numbers{ 1, 2, 3, 4, 5 };
    // std::list<int> numbers{ 1, 2, 3, 4, 5 };

    for (int i = 0; i < numbers.size(); ++i) {
        std::println ("{}: {}", i, numbers[i]);
    }
}

static void test_stl_03()
{
    std::vector<int> numbers{ 1, 2, 3 };
    // std::list<int> numbers{ 1, 2, 3 };

    std::vector<int>::iterator pos = numbers.begin();
    std::vector<int>::iterator ende = numbers.end();

    //auto anfang1 = numbers.begin();
    //auto ende1 = numbers.end();

    // Wert des ersten Elements im Container

    if (pos == ende) {
        std::println("Ende.");
        return;
    }

    int value = *pos;
    std::println("Value: {}", value);

    ++pos;   // Gehe zur nächsten Position

    // Wert des aktuellen Elements im Container
    if (pos == ende) {
        std::println("Ende.");
        return;
    }
    value = *pos;
    std::println("Value: {}", value);

    ++pos;   // Gehe zur nächsten Position

    // Wert des aktuellen Elements im Container
    if (pos == ende) {
        std::println("Ende.");
        return;
    }
    value = *pos;
    std::println("Value: {}", value);

    ++pos;   // Gehe zur nächsten Position

    // Wert des aktuellen Elements im Container
    if (pos == ende) {
        std::println("Ende.");
        return;
    }
    value = *pos;
    std::println("Value: {}", value);
}

static void test_stl_04()
{
    std::vector<int> numbers{ 1, 2, 3 };
    // std::list<int> numbers{ 1, 2, 3 };

    std::vector<int>::iterator ende = numbers.end();

    for (std::vector<int>::iterator pos = numbers.begin(); pos != ende; ++pos) {

        int value = *pos;
        std::println("Value: {}", value);
    }
}

static void printElem (int elem)
{
    std::println("Value: {}", elem);
}

static void test_stl_05()
{
    std::vector<int> numbers{ 1, 2, 3 };
    //std::list<int> numbers{ 1, 2, 3 };
   // std::deque<int> numbers{ 1, 2, 3 };

    std::println("Vor std::for_each");

    std::for_each(
        numbers.begin(),
        numbers.end(),
        printElem
    );

    std::println("Nach std::for_each");
}

// ==========================================
// Geht std::for_each im dritten Parameter auch Objekt-orientiert ???: Ja

class Printer
{
private:
    std::string m_header;

public:
    Printer(const std::string& header) {
        m_header = header;
    }

    // Why ... Methode ohne Namen .. ist in diesem Fall einfacher
    // void fun(const Type &a);

    void operator() (int elem) {
        std::println("{}{}", m_header, elem);
    }

    void print (int elem) {
        std::println("{}{}", m_header, elem);
    }
};

static void test_stl_06()
{
    std::vector<int> numbers{ 1, 2, 3 };
    //std::list<int> numbers{ 1, 2, 3 };
   // std::deque<int> numbers{ 1, 2, 3 };

    Printer printer("Value ===> ");   // Dieser hat eine Realisierung für operator() ==> kann deshalb an std::for_each übergeben werden !!!

    std::println("Vor std::for_each");

    std::for_each(
        numbers.begin(),
        numbers.end(),
        printer
    );

    std::println("Nach std::for_each");
}

void test_stl()
{
    // test_stl_01();
    //test_stl_02();
   // test_stl_03();
   // test_stl_04();
    // test_stl_05();
    test_stl_06();
}