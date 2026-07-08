

class IntCalculator
{
public:
    // Klassenmethoden // class methods
    static int add(int x, int y) { return x + y; }
    static int sub(int x, int y) { return x - y; }
    static int mul(int x, int y) { return x * y; }
    static int div(int x, int y) { return x / y; }
};

class DoubleCalculator
{
public:
    // Klassenmethoden // class methods
    static double add(double x, double y) { return x + y; }
    static double sub(double x, double y) { return x - y; }
    static double mul(double x, double y) { return x * y; }
    static double div(double x, double y) { return x / y; }
};


template <typename T>
class Calculator
{
public:
    // Klassenmethoden // class methods
    static T add(T x, T y) {
        return x + y;
    }
    static T sub(T x, T y) { return x - y; }
    static T mul(T x, T y) { return x * y; }
    static T div(T x, T y) { return x / y; }
};



void test_schablonen()
{
    int result = IntCalculator::add(3, 4);

    double dresult = DoubleCalculator::add(5.7, 6.1);



    int anotherResult = Calculator<int>::add(17, 18);

    double anotherDResult = Calculator<double>::add(5.7, 6.1);
}