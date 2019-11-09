#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        double a, b, c;
        cin >> a >> b >> c;
        double res = (a + b + c) / 3;
        if (res < 60.0)
            count++;
    }

    cout << count << endl;

    return 0;
}