
#include <print>

// Eine Klasse für Rechtecke

class Rectangle
{
protected:
    // member data
    int m_x;       // linke, obere Ecke
    int m_y;
    int m_width;
    int m_height;

public:
    // c'tor(s)
    Rectangle(int x, int y, int width, int height) {
        m_x = x; 
        m_y = y;
        m_width = width;
        m_height = height;
    }

    // method(s)
    virtual  void print() {
        std::println("Rectangle: {},{},{},{}", m_x, m_y, m_width, m_height);
    }

    // Beispiel:
    void eraseBackground() {  /* auf weiß setzen */}

    virtual void paint () { /* ein Rectangle malen ... */ }
};

class ColoredRectangle : public Rectangle
{
private:
    int m_color;

public:
    // c'tor(s)
    ColoredRectangle(int x, int y, int width, int height, int color) 
        : Rectangle (x, y, width, height)  
    {
        m_color = color;
    }

    // method(s)
    void print() {
        // std::println("ColoredRectangle: {},{},{},{},{}", m_x, m_y, m_width, m_height, m_color);
        std::println("ColoredRectangle: ");
        std::print("    ");
        Rectangle::print();
        std::println("    Color: {}", m_color);
    }
};

//class ColoredRectangle
//{
//private:
//    int m_x;       // linke, obere Ecke
//    int m_y;
//    int m_width;
//    int m_height;
//
//    int m_color;   // offen, wie die Farbanteile in einer int-Variablen abgelegt werden.
//};

void test_vererbung_erste_schritte()
{
    Rectangle r (10, 10, 100, 200);
    r.print();

    ColoredRectangle cr (20, 20, 50, 100, 999);
    cr.print();
}

void test_vererbung()
{
    Rectangle r(10, 10, 100, 200);

    ColoredRectangle cr(20, 20, 50, 100, 999);

    Rectangle* rp;

    rp = & cr; // Links: Rectangle*    Rechts: ColoredRectangle*   Die beiden Objekte stehen in der ist-ein Beziehung

    rp->print();    // Welches print  wird aufgerufen ????????????????????????????????????
                    // Das von Rectangle: WEIL rp ist vom Typ Rectangle (Compile / Übersetzungszeit)
                    // oder
                    // Das von ColoredRectangle: WEIL rp zeigt auf ein ColoredRectangle Objekt (Laufzeit / Runtime)
}
