#include <iostream>
using namespace std;

struct Pos
{
    int x, y;

    Pos operator+(const Pos &right)
    {
        Pos result;
        result.x = x + right.x;
        result.y = y + right.y;
        return result;
    }
    
    friend ostream& operator<<(std::ostream& os, const Pos& po)
    {
        os << '(' << po.x << ", " << po.y << ')';
        return os;
    }

    Pos(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }
};

int main()
{
    Pos a(1, 2), b(3, 4);
    Pos c = a + b;
    cout << a << " + " << b << " = " << c << endl;
    return 0;
}
