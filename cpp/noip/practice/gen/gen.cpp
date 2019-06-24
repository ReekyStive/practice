#include <fstream>
#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int n = 10e6;

int main()
{
    // ios::sync_with_stdio(false);
    double intime, outtime;
    long long begin, end;
    int temp;
    srand(time(0));

    ofstream fout("gen.txt");
    // begin = clock();
    // for (int i = 0; i < n; i++)
        // fout << rand() << endl;
    // end = clock();
    // outtime = (end - begin) / CLOCKS_PER_SEC;
    // cout << n << "Output : " << outtime << "s" << endl;
    fout.close();

    ifstream fin("gen.txt");
    begin = clock();
    for (int i = 0; i < n / 10; i++)
        fin >> temp;
    end = clock();
    intime = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "fstream " << n << " Iutput : " << intime << "s" << endl;
    fin.close();

    // freopen("gen.txt", "rb", stdin);
    // freopen("233.txt", "w", stdout);
    // begin = clock();
    // for (int i = 0; i < n; i++)
    //     scanf("%d", &temp);
    // end = clock();
    // intime = (double)(end - begin) / CLOCKS_PER_SEC;
    // cout << "freopen scanf" << n << " Iutput : " << intime << "s" << endl;

    // freopen("gen.txt", "r", stdin);
    // freopen("233.txt", "w", stdout);
    // begin = clock();
    // for (int i = 0; i < n; i++)
    //     cin >> temp;
    // end = clock();
    // intime = (double)(end - begin) / CLOCKS_PER_SEC;
    // cout << "freopen scanf" << n << " Iutput : " << intime << "s" << endl;

    system("pause");

    return 0;
}