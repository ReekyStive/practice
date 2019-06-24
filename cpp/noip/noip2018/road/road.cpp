#include <fstream>

using namespace std;

ifstream fin("road.in");
ofstream fout("road.out");

const int maxn = 100010;
int d[maxn];
int n;
int deep;

int fbegin()
{
    for (int i = 1; i <= n; i++)
    {
        if (d[i] > 0)
            return i;
    }
    return -1;
}

int fend(int ibegin)
{
    for (int i = ibegin + 1; i <= n; i++)
    {
        if (d[i] == 0)
            return i - 1;
    }
    return n;
}

void bk(int ibegin, int iend)
{
    for (int i = ibegin; i <= iend; i++)
        d[i] -= deep;
}

int dmin(int ibegin, int iend)
{
    int m = d[ibegin];
    for (int i = ibegin + 1; i <= iend; i++)
    {
        if (d[i] < m)
            m = d[i];
    }
    return m;
}

int main()
{
    int b, e;
    long long ans = 0;
    fin >> n;

    for (int i = 1; i <= n; i++)
    {
        fin >> d[i];
    }

    b = fbegin();
    while (b != -1)
    {
        e = fend(b);
        deep = dmin(b, e);
        ans += deep;
        bk(b, e);
        
        b = fbegin();
    }

    fout << ans << endl;

    fin.close();
    fout.close();

    return 0;
}
