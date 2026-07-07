#pragma once

class Time
{
    // friend bool operator== (const Time& lhs, const Time& rhs);

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
    // schreibende Zugriff
    void setHours(int hours);
    void setMinutes(int minutes);
    void setSeconds(int seconds);

    // lesende Zugriff / deshalb const
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

  //  int getTotalSeconds();  // Beispiel:  11:31:30  ==> 11 * 60 * 60 + 31 * 60 + 30

public:
    // public methods
    void reset();
    void increment();
    void print();
    bool equal(const Time& other) const;

    // operators
    // bool operator == (Time other);
    // bool operator != (Time other);   Wird automatisch erzeugt
};

// =============================================================

// Objekte kann man auch an freie Funktionen übergeben

// Hmmm, bräuchte aber eine Funktion getTotalSeconds

// Das können wir jetzt als freie Funktion vereinbaren:
// Im Header-File aber nur die Schnittstelle

int getTotalSeconds(const Time& time);

// Auch das Überladen von Operatoren kann man außerhalb der Klasse machen:
// Durch globale / freien Funktionen – außerhalb der Klasse.


bool  operator ==  (const Time& lhs, const Time& rhs);    // lhs = left hand side, rhs: right hand side

void incrementSecond(Time& time);