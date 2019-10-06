#include <iostream>
using namespace std;

struct Pos
{
    int x, y;

    Pos operator+(const Pos &right)
    {
        Pos result;
        result.x = this -> x + right.x;
        result.y = this -> y + right.y;
        return result;
    }

    Pos operator+(const int &right)
    {
        Pos result;
        result.x = this -> x + right;
        result.y = this -> y;
        return result;
    }

    friend Pos operator+(const int & a, const Pos &right)
    {
        Pos result = right;
        result.x = this -> x + a;
        result.y = this -> y;
        return result;
    }
    
    friend std::ostream & operator<<(std::ostream &os, const Pos &pos)
    {
        os << '(' << pos.x << ", " << pos.y << ')';
        return os;
    }

    Pos(int a = 0, int b = 0)
    {
        this -> x = a;
        this -> y = b;
    }
};

int main()
{
    Pos a(1, 2), b(3, 4);
    Pos c;
    c = a + b;
    // c = a.operator+(b);
    c = a + 1;
    c = 1 + a;
    cout << c << endl << c << endl;
    return 0;
}
