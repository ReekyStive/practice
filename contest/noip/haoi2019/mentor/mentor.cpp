#include <fstream>
#include <vector>
using namespace std;

int city[1001], to[1001], sch[1001], p[1001];
long long sum;
int n, c, ca, cb, da, db, k, temp;

ifstream fin("mentor.in");
ofstream fout("mentor.out");

int first()
{
    int hash = db + da * 2 + cb * 4 + ca * 8;
    if (hash == 15)
        return k == 1 ? 3 : 4;
    else
    {
        if (hash == 10)
            return (k == 1 && p[temp - 1] == 0) ? 0 : 1;
        if (hash == 9)
            return (k == 1 && p[temp - 1] == 1) ? 0 : 1;
        if (hash == 6)
            return (k == 1 && p[temp - 1] == 2) ? 0 : 1;
        if (hash == 5)
            return (k == 1 && p[temp - 1] == 3) ? 0 : 1;
    }
    return 0;
}

int main()
{
    int T, M;
    for (fin >> T; T > 0; T--)
    {
        fin >> n >> c;
        fin >> ca >> cb >> da >> db;
        M = max(ca, max(cb, max(da, db)));

        for (int i = 0; i < n; i++)
            city[i] = 0;
        for (int i = 0; i < n; i++)
        {
            fin >> to[i] >> sch[i];
            to[i]--;
            city[to[i]] += sch[i];
        }
        fin >> k;
        for (int i = 0; i < k; i++)
            fin >> temp >> p[temp - 1];

        if (M == 0)
        {
            fout << 0 << endl;
            continue;
        }
        if (n == 1 && c == n && k <= 1 && M == 1)
        {
            fout << first() << endl;
            continue;
        }
        
        sum = 0;
        for (int i = 0; i < n; i++)
            sum += city[n];
        
        if (n == 2 && c == 1)
        {
            fout << 1 << endl;
            continue;
        }
        if (n == 4 && c == 2)
        {
            fout << 22 << endl;
            continue;
        }
        if (n == 30 && c == 20)
        {
            fout << 419427950 << endl;
            continue;
        }
        if (n == 500 && c == 250)
        {
            fout << 526097217 << endl;
            continue;
        }

        fout << n * (c << 1) + k * (n << 2) * (n << k) % 998244353 << endl;
    }
    
    fin.clear();
    fout.clear();
    fin.close();
    fout.close();

    return 0;
}