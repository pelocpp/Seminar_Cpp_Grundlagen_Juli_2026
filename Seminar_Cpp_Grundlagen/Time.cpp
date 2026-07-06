

#include "Time.h"

#include <print>

void Time :: reset()
{
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;
}

void Time::print()
{
    std::println("{:02}:{:02}:{:02}", m_hours, m_minutes, m_seconds); // C++ 23
}

void Time::increment()
{
    ++ m_seconds;
}

// getter / setter
void Time::setHours(int hours)
{
    // der Wert der / des Parameter(s) ist zu überprüfen !
    if (hours >= 0 && hours < 24) {
        m_hours = hours;
    }
    else {
        // die Variable m_hours kann nicht gesetzt werden
        std::println("Falscher Parameter Wert: {}", hours);
    }
}

void Time::setMinutes(int minutes)
{
    // der Wert der / des Parameter(s) ist zu überprüfen !
    if (minutes >= 0 && minutes < 60) {
        m_minutes = minutes;
    }
    else {
        // die Variable m_minutes kann nicht gesetzt werden
        std::println("Falscher Parameter Wert: {}", minutes);
    }
}

void Time::setSeconds(int seconds)
{
    // der Wert der / des Parameter(s) ist zu überprüfen !
    if (seconds >= 0 && seconds < 60) {
        m_seconds = seconds;
    }
    else {
        // die Variable m_hours kann nicht gesetzt werden
        std::println("Falscher Parameter Wert: {}", seconds);
    }
}


int Time::getHours() {
    return m_hours;
}

int Time::getMinutes() {
    return m_minutes;
}

int Time::getSeconds() {
    return m_seconds;
}

// getter
int Time::getTotalSeconds()
{
    int seconds = m_hours * 60 * 60 + m_minutes * 60 + m_seconds;

    return seconds;
}

// Konstruktoren

// Einfache Realisierung // sie ist korrekt !!!
//Time::Time()
//{
//    m_hours = 0;
//    m_minutes = 0;
//    m_seconds = 0;
//}

// Kürzere Realisierung , natürlich auch korrekt !!!
// Member Initializer List
Time::Time() 
    : m_hours (0), m_minutes(0), m_seconds(0)
{
}




Time::Time(int hours, int minutes, int seconds)    // ein Konstruktor MIT drei Parametern
{
    // sehr schnelle Realisierung, aber manchmal falsch !!!
    //m_hours = hours;
    //m_minutes = minutes;
    //m_seconds = seconds;

    // korrekte Realisierung:
    // A) Die Veriablen erst mal in einen - prinzipiell - richtigen Grundzustand setzen
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;

    // B) Versuchen, die Werte der Parameter zu übernehmen,
    // wenn sich korrekt sind.
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
}

Time::Time(int hours, int minutes)    // ein Konstruktor MIT zwei Parametern
{
    // korrekte Realisierung:
    // A) Die Veriablen erst mal in einen - prinzipiell - richtigen Grundzustand setzen
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;   // Bei diesem Konstruktor soll m_seconds immer 0 sein
                     // mit setSeconds könnte man später die Sekunden ändern ...

    // B) Versuchen, die Werte der Parameter zu übernehmen,
    // wenn sich korrekt sind.
    setHours(hours);
    setMinutes(minutes);
}