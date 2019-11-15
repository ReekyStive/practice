#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

ifstream fin("file_io.in");
ofstream fout("file_io.out");

double mesure(void (*task)())
{
    auto start = system_clock::now();

    task();

    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return (double)duration.count() * microseconds::period::num / microseconds::period::den;
}

void fread()
{
    int temp;
    for (int i = 0; i < 1000000; i++)
        fin >> temp;
}

void fwrite()
{
    for (int i = 0; i < 1000000; i++)
        fout << i << endl;
}

int main()
{
    // ios::sync_with_stdio(false);

    cout << "fin:" << endl;
    cout << "Time Spend: " << mesure(fread) << " Seconds." << endl;
    cout << endl;

    cout << "fout:" << endl;
    cout << "Time Spend: " << mesure(fwrite) << " Seconds." << endl;
    cout << endl;

    return 0;
}