// ===========================================================================
// Main.cpp // Memory Management
// ===========================================================================

#include "Globals.h"

#include <print>

/*static*/ int g_counter = 123;   // globale variable wird hier definiert // VORBELEGUNGSWERT vorhanden sein.

//namespace Memory_Management
//{
//    int g_counter = 0;
//}

static void main_MemoryManagement_01()
{
    int a = 1;
    int b = 2;
    int sum = a + b;
}

static void main_MemoryManagement_02()
{
    int* pa = new int (1);

    // ........
    delete pa;
}

static void main_GlobalVariable_WithinFunction()
{
    static int a = 1;

    a++;

    std::println("in main_GlobalVariable_WithinFunction: a = {}", a);
}

void main_MemoryManagement()
{
    // using namespace Memory_Management;

    main_GlobalVariable_WithinFunction();
    main_GlobalVariable_WithinFunction();
    main_GlobalVariable_WithinFunction();


    std::println("g_counter: {}", g_counter);
}

// ===========================================================================
// End-of-File
// ===========================================================================