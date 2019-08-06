#include <iostream>

using namespace std;

int main()
{
    double s, x, v = 7.0, dis = 0;
    cin >> s >> x;

    while (dis < s - x)
    {
        dis += v;
        v *= 0.98;
    }

    dis += v;

    if (dis > s + x)
        cout << "n" << endl;
    else
        cout << "y" << endl;

    return 0;
}
