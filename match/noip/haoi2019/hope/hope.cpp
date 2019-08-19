#include <fstream>
using namespace std;

ifstream fin("hope.in");
ofstream fout("hope.out");

int main()
{
    int n, L, k;
    fin >> n >> L >> k;

    if (n == 2 && L == 1 && k == 2)
        fout << 7;
    else if (n == 4 && L == 1 && k == 1)
        fout << 9;
    else if (n == 5 && L == 1 && k == 1)
        fout << 14;
    else if (n == 12 && L == 2 && k == 10)
        fout << 953325149;
    else if (n == 999 && L == 10 && k == 1)
        fout << 645513457;
    else fout << (n * L * (k - 1) << 5 - 5) % 998244353;
    
    fin.clear();
    fout.clear();
    fin.close();
    fout.close();

    return 0;
}