#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;

    if (a >= 0 && a <= 100)
    {
        if (a >= 90)
            cout << 'A';
        else if (a >= 80)
            cout << 'B';
        else if (a >= 70)
            cout << 'C';
        else if (a >= 60)
            cout << 'D';
        else
            cout << 'E';
    }
    else
        cout << 'F';

    cout << endl;

    return 0;
}