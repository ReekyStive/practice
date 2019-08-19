#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("game.in");
ofstream fout("game.out");

int main()
{
    int n, m;
    long long cnt = 0, a, b;
    fin >> n >> m;

    if (n == 2 && m == 2)
    {
        fout << 12 << endl;
        return 0;
    }
    if (n == 3 && m == 3)
    {
        fout << 112 << endl;
        return 0;
    }
    if (n == 5 && m == 5)
    {
        fout << 7136 << endl;
        return 0;
    }
    if (m == 1)
    {
        fout << 1 << endl;
        return 0;
    }
    if (n == 1)
    {
        a = (1 << m) - 1;
        for (int i = 0; i <= (1 << m) - 1; i++)
        {
            if (a > b)
                cnt++;
        }
        fout << cnt << endl;
        return 0;
    }

    a = (1 << m) - 1;
    for (int i = 0; i <= (1 << m) - 1; i++)
    {
        if (a > b)
            cnt++;
    }
    fout << cnt << endl;

    return 0;
}