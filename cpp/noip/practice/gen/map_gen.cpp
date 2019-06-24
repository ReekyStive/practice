#include <iostream>
#include <fstream>
#include <algorithm>
#include <time.h>
using namespace std;

const int inf = __INT_MAX__ / 16;

int main()
{
    int apex, side, a, b, val;
    srand((unsigned)time(0));
    cin >> apex;

    ofstream fout;
    fout.open("gen.txt");

    side = rand() % ((apex - 1) * (apex - 1) + 1);
    fout << apex << " " << side << endl;

    for (int i = 0; i < side; i++)
    {
        a = rand() % apex;
        b = rand() % apex;
        while (a == b)
            b = rand() % apex;
        val = rand() % inf;
        fout << a << " " << b << " " << val << endl;
    }

    system("pause");

    return 0;
}
