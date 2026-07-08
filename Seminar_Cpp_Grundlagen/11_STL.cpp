
#include <vector>
#include <print>

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

void test_stl()
{
    test_stl_01();
}