
#include <print>

static int malZwei_01(int value)
{
    int result = 2 * value;

    return result;
}

static void malZwei_02(int value)
{
    value = 2 * value;
}

static void malZwei_03(int* adrValue)
{
    int tmp = *adrValue;  // indirektes Lesen

    tmp = 2 * tmp;         // ausführlich, safe, leichter zu debuggen

    *adrValue = tmp;
}

static void malZwei_03_performant(int* adrValue)
{
    *adrValue = 2 * *adrValue;   // Hmmm, advanced writing
}

// Call-by-Reference
static void malZwei_04(int& value)
{
    value = 2 * value;
}

void test_passing_parameters()
{
    int n = 123;    // 246 = 2 * 123

    int m = 0;

    m = malZwei_01(n);
    std::println("m = {}", m);

    malZwei_02(n);
    std::println("n = {}", n);

    n = 123;
    malZwei_03( & n );
    std::println("n = {}", n);

    n = 123;
    malZwei_04(n);
    std::println("n = {}", n);
}