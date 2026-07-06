#pragma once

class Time
{
private:
    // member data / instance variables
    int m_hours;           // m_  ... member
    int m_minutes;
    int m_seconds;

    // Konstruktoren // constructors // c'tors
public:
    Time();                                       // ein Konstruktor OHNE Parameter
    Time(int hours, int minutes, int seconds);    // ein Konstruktor MIT drei Parametern
    Time(int hours, int minutes);                 // ein Konstruktor MIT zwei Parametern


    // getter / setter
public:
    void setHours(int hours);
    void setMinutes(int minutes);
    void setSeconds(int seconds);

    int getHours();
    int getMinutes();
    int getSeconds();

    int getTotalSeconds();  // Beispiel:  11:31:30  ==> 11 * 60 * 60 + 31 * 60 + 30

    // public interface / methods
    
    // KEINE Implementierung !!!   woanders
    // Was dann: Die Schnittstelle der Funktionen
public:
    void reset();
    void increment();
    void print();
};

