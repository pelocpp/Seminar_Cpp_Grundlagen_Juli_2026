

class Demo
{
private:
    int x;    // member variable

public:
    // setter
    void setX(/*self, */int x) {  // Parameter x
        this->x = x;          // Konflikt: kann mit this beseitigt werden
    }
};

class AnotherDemo
{
private:
    int m_x;    // member variable

public:
    // setter
    void setX(/*self, */int x) {  // Parameter x
        m_x = x;          // Nie einen Konflikt:
    }
};
