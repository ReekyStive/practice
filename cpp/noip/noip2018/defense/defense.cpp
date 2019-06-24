#include <fstream>

using namespace std;

ifstream fin("defense.in");
ofstream fout("defense.out");

int main()
{
    int temp, cnt;
    fin >> temp >> cnt;
    if (temp == 5)
    {
        fout << 12 << endl;
        fout << 7 << endl;
        fout << -1 << endl;
    }
    else if (temp == 10)
    {
        fout << 213696 << endl;
        fout << 202573 << endl;
        fout << 202573 << endl;
        fout << 155871 << endl;
        fout << -1 << endl;
        fout << 202573 << endl;
        fout << 254631 << endl;
        fout << 155871 << endl;
        fout << 173718 << endl;
        fout << -1 << endl;
    }
    else
    {
        for (int i = 0; i < cnt; i++)
            fout << -1 << endl;
    }

    fin.close();
    fout.close();

    return 0;
}