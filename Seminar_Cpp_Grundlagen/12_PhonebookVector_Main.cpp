// ===============================================================================
// PhoneBook_Main.cpp
// ===============================================================================

#include <iostream>
#include <chrono> 

#include "PhoneBookVector.h"

static void test01_phonebook()
{
    using namespace PhoneBook;

    PhoneBookVector book;

    // testing insert
    book.insert("Franz", "Schneider", 8483);
    book.insert("Hans", "Mueller", 5326);
    book.insert("Sepp", "Meier", 7561);
    book.insert("Anton", "Huber", 4899);
    book.print();

    // testing invalid insertion
    bool succeeded = book.insert("Franz", "Schneider", 4321);
    if (!succeeded) {
        std::cout << "Franz Schneider already in Phonebook!" << std::endl;
    }

    // testing toString
    std::string s = book.toString();
    std::cout << s << std::endl;

    // testing update
    std::cout << "Updating phone number of Franz Schneider:" << std::endl;
    succeeded = book.update("Franz", "Schneider", 1234);
    book.print();

    // testing remove
    std::cout << "Removing Anton Huber:" << std::endl;
    succeeded = book.remove("Anton", "Huber");
    book.print();

    // testing contains
    bool found = book.contains("Sepp", "Meier");
    std::cout << "Found Sepp Meier: " << std::boolalpha << found << std::endl;
    found = book.contains("Otto", "Meier");
    std::cout << "Found Otto Meier: " << found << std::endl;

    // testing search
    std::size_t numberMeier = 0;
    succeeded = book.search("Anton", "Meier", numberMeier);
    if (succeeded) {
        std::cout << "Hans Meier: " << numberMeier << std::endl;
    }
    std::cout << std::endl;

    // testing 'getNames'
    std::forward_list<std::string> allNames = book.getNames();
    std::size_t i = 1;
    for (const std::string& name : allNames) {
        std::cout << i << ": " << name << std::endl;
        ++i;
    }
    std::cout << std::endl;
}

//static void test02_phonebook()
//{
//    using namespace PhoneBook;
//
//    PhoneBookMap book;
//
//    // testing insert
//    book.insert("Franz", "Schneider", 8483);
//    book.insert("Hans", "Mueller", 5326);
//    book.insert("Sepp", "Meier", 7561);
//    book.insert("Anton", "Huber", 4899);
//    book.print();
//
//    // testing invalid insertion
//    bool succeeded = book.insert("Franz", "Schneider", 4321);
//    if (!succeeded) {
//        std::cout << "Franz Schneider already in Phonebook!" << std::endl;
//    }
//
//    // testing toString
//    std::string s = book.toString();
//    std::cout << s << std::endl;
//
//    // testing sort
//    // book.sort();  // std::unordered map doesn't support sorting
//    book.print();
//
//    // testing update
//    std::cout << "Updating phone number of Franz Schneider:" << std::endl;
//    succeeded = book.update("Franz", "Schneider", 1234);
//    book.print();
//
//    // testing remove
//    std::cout << "Removing Anton Huber:" << std::endl;
//    succeeded = book.remove("Anton", "Huber");
//    book.print();
//
//    // testing contains
//    bool found = book.contains("Sepp", "Meier");
//    std::cout << "Found Sepp Meier: " << std::boolalpha << found << std::endl;
//    found = book.contains("Otto", "Meier");
//    std::cout << "Found Otto Meier: " << found << std::endl;
//
//    // testing search
//    std::size_t numberMeier = 0;
//    succeeded = book.search("Sepp", "Meier", numberMeier);
//    if (succeeded) {
//        std::cout << "Hans Meier: " << numberMeier << std::endl;
//    }
//    std::cout << std::endl;
//
//    // testing 'getNames'
//    std::forward_list<std::string> allNames = book.getNames();
//    std::size_t i = 1;
//    for (const std::string& name : allNames) {
//        std::cout << i << ": " << name << std::endl;
//        ++i;
//    }
//    std::cout << std::endl;
//}

// ===============================================================================

void aufgabe_STLPhoneBook()
{
    test01_phonebook();
    //test02_phonebook();
}

// ===============================================================================
// End-of-File
// ===============================================================================