#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("money.in");
ofstream fout("money.out");

const int maxn = 103;
int a[maxn];
int n;

bool rpable(int cur, int mon)
{
    bool rpbe = false;

    if (cur <= 0)
    {
        if (mon == 0)
            return true;
        else
            return false;
    }

    if (mon == 0)
        return true;

    for(int i = 0; i <= mon / a[cur - 1]; i++)
    {
        rpbe = rpable(cur - 1, mon - i * a[cur - 1]);
        if (rpbe)
            break;
    }

    return rpbe;
}

int main()
{
    int T, m;
    fin >> T;

    while (T--)
    {
        m = 0;
        fin >> n;
        for (int i = 0; i < n; i++)
            fin >> a[i];

        if (n == 1)
        {
            fout << 1 << endl;
            continue;
        }

        sort(a, a + n);

        for (int i = n - 1; i >= 0; i--)
        {
            if (!rpable(i, a[i]))
            {
                m++;
            }
        }

        fout << m << endl;
    }

    return 0;
}
