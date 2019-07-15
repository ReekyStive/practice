#include <iostream>
#include <cmath>

using namespace std;

bool cheaters[1024][1024];

int main()
{
    int n;
    cin >> n;
    int total = pow(2, n);

    cheaters[0][total - 1] = true;
    cheaters[1][total - 1] = true;
    cheaters[1][total - 2] = true;

    // Fill
    int range;
    for (int i = 1; i < n; i++)
    {
        range = pow(2, i);

        for (int j = 0; j < range; j++)
            for (int k = total - 1; k > total - range - 1; k--)
            {
                cheaters[j + range][k] = cheaters[j][k];
                cheaters[j + range][k - range] = cheaters[j][k];
            }
    }

    for (int i = 0; i < total; i++)
    {
        for (int j = 0; j < total; j++)
            cout << (int)cheaters[i][j] << " ";
        cout << endl;
    }

    return 0;
}
