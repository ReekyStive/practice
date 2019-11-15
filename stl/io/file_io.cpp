#include <iostream>
#include <fstream>
#include <chrono>

#include <cstdio>

using namespace std;
using namespace chrono;

double mesure(void (*task)())
{
    auto start = system_clock::now();

    task();

    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return (double)duration.count() * microseconds::period::num / microseconds::period::den;
}

void fsread()
{
    ifstream fin("file_io.in");

    int temp;
    for (int i = 0; i < 1000000; i++)
        fin >> temp;
}

void fswrite()
{
    ofstream fout("file_io.out");

    for (int i = 0; i < 1000000; i++)
        fout << i << endl;
}

void frread()
{
    int temp;
    freopen("file_io.in", "r", stdin);
    for (int i = 0; i < 1000000; i++)
        scanf("%d", &temp);
}

void frwrite()
{
    freopen("file_io.out", "w", stdout);
    for (int i = 0; i < 1000000; i++)
        printf("%d\n", i);
}

int main()
{
    // ios::sync_with_stdio(false);

    cout << "fsin:" << endl;
    cout << "Time Spend: " << mesure(fsread) << " Seconds." << endl;
    cout << endl;

    cout << "fsout:" << endl;
    cout << "Time Spend: " << mesure(fswrite) << " Seconds." << endl;
    cout << endl;

    cout << "frin:" << endl;
    cout << "Time Spend: " << mesure(frread) << " Seconds." << endl;
    cout << endl;

    cout << "frout:" << endl;
    cout << "Time Spend: " << mesure(frwrite) << " Seconds." << endl;
    cout << endl;

    return 0;
}
