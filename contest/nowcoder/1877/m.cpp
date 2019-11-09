#include <iostream>

using namespace std;

int main()
{
    int a, b, n;
    cin >> a;
    cin.get();
    cin >> b >> n;

    b += n;
    a += b / 60;
    b %= 60;
    a %= 24;

    cout.fill('0');
    cout.width(2);
    cout << a;
    cout << ':';
    cout.width(2);
    cout << b;
    cout << endl;

    return 0;
}