#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> data;
    data.resize(n);
    for (int i = 0; i < n; i++)
        cin >> data[i];

    for (int i = 0; i <= n - 6; i++)
    {
        if (data[i] == 1 &&
            data[i + 1] == 1 &&
            data[i + 2] == 4 &&
            data[i + 3] == 5 &&
            data[i + 4] == 1 &&
            data[i + 5] == 4)
        {
            data[i + 5] = 5;
            i = i + 5;
        }
    }

    for (auto &item : data)
        cout << item << ' ';
    cout << endl;

    return 0;
}