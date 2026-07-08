// ===============================================================================
// PhoneBookVector.h // Using std::vector
// ===============================================================================

#pragma once

#include <cstddef>
#include <forward_list>
#include <string>
#include <vector>

namespace PhoneBook
{
    class PhoneBookVector
    {
    private:
        // private helper classes
        // Ich will diese Klasse nicht für die Anwender konzipieren
        class Entry
        {
        public:
            std::string m_first;   // Zu enthaltenen Objekten wird der Standard-Konstruktor AUTOMATISCH aufgerufen
            std::string m_last;
            std::size_t m_number;   // habe die tel.Nr als size_t gewählt: 1512342 , Alternative: "+49151..."

            Entry() : m_number(0) {}

            Entry(const std::string& first, const std::string& last, std::size_t number)
                : m_first(first), m_last(last), m_number(number)
            {}
        };

        class MatchName
        {
        public:
            const std::string& first;
            const std::string& last;

            MatchName(const std::string& first, const std::string& last)
                : first(first), last(last)
            {}

            bool operator() (const Entry& other) const {
                return other.m_first == first && other.m_last == last;
            }
        };

        // member data
        std::vector<Entry> m_entries;   // Entry ist eine Hilfsklasse

    public:
        // public interface
        std::size_t size() const ;
        bool insert(const std::string& first, const std::string& last, std::size_t number);
        bool update(const std::string& first, const std::string& last, std::size_t number) ;
        bool search(const std::string& first, const std::string& last, std::size_t& number) const ;
        bool remove(const std::string& first, const std::string& last) ;
        bool contains(const std::string& first, const std::string& last) const ;
        std::forward_list<std::string> getNames() const ;
        std::string toString() const ;

        void print() const ;

    private:
        // private helper methods
        static void printEntry(const Entry&);   // diese Methode ist static:
                                                // Dann ist das eine Klassenmethode
                                                // Um in Python zu sprechen: Kein self als erster Parameter
                                                // Um in C++ zu sprechen: Kein (versteckter) this als erster Parameter
                                                // dann ist das vom Charakter her wie eine globale / freie Funktion
                                                // Im Prinzip ist das dann wie eine freie Funktion
                                                // nur kann mal solche Funktionen auch in Klassen verstecken

        static std::string entryToString(const Entry&);
        static std::string append(const std::string&, const Entry&);
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================