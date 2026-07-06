

#include <print>

static void test_pointer_references_C()
{
    // A) Was gibt es in C?
    int n = 123;   // 123: 0x 7B   // 1234 = 0x 04 D2

    long long ll = 123;

    std::size_t countBytes = sizeof(int);
    std::size_t countBytes1 = sizeof(int*);
    std::size_t countBytes2 = sizeof(long long);
    std::size_t countBytes3 = sizeof(std::size_t);

    std::println("n = {}", n);

    // a) Bildung einer Adresse in C // Anweisung // Statement
   // int* ip = &n;

    int* ip = NULL;   // Variablenvereinbarung (ip) mit Vorbelegung
    ip = &n;          // Anweisung // Statement (Wertzuweisung) // Adress-Operator & in einer Anweisung

    // Weise der Variablen n den Wert 124 zu, ohne den Bezeichner 'n' dabei zu verwenden :)
    *ip = 124;     // Schreibend

    int m = *ip;   // lesend

    // -----------------------------------
    // Zeigerarithmetik

    // a) Wert eines Zeigers verändern / inkrementieren
    ip++;

    // Frage: Gehört mir der Speicher hinter dieser Adresse ?????? Nein

    ip--;
    // Frage: Gehört mir der Speicher hinter dieser Adresse ?????? Jetzt wieder - bin beim alten Wert der Adresse


    // VOOOOOOOOOOOOOORSICHT: Ich tue mal so, als ob mir der Speicher hinter dieser Adresse gehört:
    *ip = 126;

}

static void test_pointer_references_Cpp()
{
    // B) Was gibt es in C++ ?

    int n = 123;

    // man kann zu n einen zweiten Namen definieren, der - hinter den Kulissen - für die Adresse steht.

    // Variablenvereinbarung
    int& rn = n;     // & als Modifizierer des Datentyps int in einer Variablenvereinbarung

    //  int& rn2 = NULL;   // Geht NICHT !!!

    // rn ist ein zweiter Name / Alias für eine vorhandene Variable
    rn = 124;

    rn++;
}

void test_pointer_references()
{
    test_pointer_references_C();
    test_pointer_references_Cpp();
}