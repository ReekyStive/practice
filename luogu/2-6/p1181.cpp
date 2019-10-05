#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int cnt = 0, sum = 0, tmp;
    int i = 0;
    cin >> tmp;
    while (i < n)
    {
        while (sum + tmp <= m)
        {
            sum += tmp;
            i++;
            if (i >= n)
                break;
            cin >> tmp;
        }
        sum = 0;
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
