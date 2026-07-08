// ===========================================================================
// Main.cpp // Keyword 'static'
// ===========================================================================

#include <iostream>

namespace Violating_Static
{

    // Pi: So gut oder schlecht gelöst ????????????????

    // Was passiert, wenn man 5 Math Objekte hat ????  ==> Man hat den Wert von Pi 5 Mal im Speicher 

    class Math
    {
    private:
        double m_pi;

    public:
        Math()
        {
            m_pi = 3.14159265358979323846;
        }

        double Pi() const { return m_pi; }
    };






    static void violatingStatic01()
    {
        Math math;

        double radius = math.Pi() * 2.0 * 2.0;
    }



    class Calculator
    {
    public:
        int add(int x, int y) { return x + y; }
        int sub(int x, int y) { return x - y; }
        int mul(int x, int y) { return x * y; }
        int div(int x, int y) { return x / y; }
    };



    static void violatingStatic02()
    {
        Calculator calc;

        int sum = calc.add(123, 456);
    }
}

namespace Motivating_Static
{
    // Was bedeutet static in der Klasse Math:
    // Bei 5 Objekten von Math liegt Pi genau EINMAL im Speicher


    class Math
    {
    public:
        //           double m_pi;
        static const double Pi;
    };

    double const Math::Pi = 3.14159265358979323846;   // Hier wird EINMALIG der Wert von Pi gesetzt






    static void motivatingStatic01()
    {
        double radius = Math::Pi * 2.0 * 2.0;
    }


    //class Calculator
    //{
    //public:
    //    int add(int x, int y) { return x + y; }
    //    int sub(int x, int y) { return x - y; }
    //    int mul(int x, int y) { return x * y; }
    //    int div(int x, int y) { return x / y; }
    //};

    class Calculator
    {
    public:
        // static: add bekommt den Charakter einer globalen Funktion
        // Man nennt solche Methoden Klassenmethoden
        static int add(int x, int y) { return x + y; }
        static int sub(int x, int y) { return x - y; }
        static int mul(int x, int y) { return x * y; }
        static int div(int x, int y) { return x / y; }
    };

    static void motivatingStatic02()
    {
        int sum = Calculator::add(123, 456);
    }
}




void main_Static()
{
    using namespace Violating_Static;
    using namespace Motivating_Static;

    violatingStatic01();
    violatingStatic02();
    motivatingStatic01();
    motivatingStatic02();
}

// ===========================================================================
// End-of-File
// ===========================================================================