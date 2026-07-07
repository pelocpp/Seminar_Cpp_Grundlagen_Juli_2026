

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


int Time::getHours() const {

    // Fehler: wird wegen const auch gar nicht übersetzt
    // m_hours++;

    return m_hours;
}

int Time::getMinutes() const {
    return m_minutes;
}

int Time::getSeconds() const {
    return m_seconds;
}

// getter
//int Time::getTotalSeconds()
//{
//    int seconds = m_hours * 60 * 60 + m_minutes * 60 + m_seconds;
//
//    return seconds;
//}

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

bool Time::equal(const Time& other) const
{
    if (m_hours == other.m_hours && m_minutes == other.m_minutes && m_seconds == other.m_seconds) {
        return true;
    }
    else {
        return false;
    }
}

//bool Time::operator == (Time other)
//{
//    if (m_hours == other.m_hours && m_minutes == other.m_minutes && m_seconds == other.m_seconds) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}



// ====================================================================
// freie Funktionen

int getTotalSeconds(const Time& time)
{
    int seconds = time.getHours() * 60 * 60 + time.getMinutes() * 60 + time.getSeconds();

    return seconds;
}

bool operator== (const Time& lhs, const Time& rhs)
{
  //  if (lhs.m_hours == rhs.m_hours && lhs.m_minutes == rhs.m_minutes && lhs.m_seconds == rhs.m_seconds) {
    if (lhs.getHours() == rhs.getHours() && lhs.getMinutes() == rhs.getMinutes() && lhs.getSeconds() == rhs.getSeconds()) {
        return true;
    }
    else {
        return false;
    }
}

// hier wird das Parameter Objekt verändert ===> eine const Referenz geht hier nicht
void incrementSecond(Time& time)
{
    // ACHTUNG: EIN FEHLER
    time.setHours(0);  // ist falsch, ist irgendwie passiert ...........

    // Sprachliches Mittel: Man kann schreibendeZugriffe / Veränderungen verbieten !!!



    // very, very simple:
    // Ein Überlauf bei 59 Sekunden wird hier nicht implementiert ...
    int currentSeconds = time.getSeconds();
    currentSeconds++;
    time.setSeconds(currentSeconds);

    //m_seconds++;
    //if (m_seconds >= 60)
    //{
    //    m_seconds = 0;
    //    m_minutes++;
    //    if (m_minutes >= 60)
    //    {
    //        m_minutes = 0;
    //        m_hours++;
    //        if (m_hours >= 24)
    //        {
    //            m_hours = 0;
    //        }
    //    }
    //}
}