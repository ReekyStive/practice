#include <iostream>
#include <vector>

using namespace std;

int count(int len, vector<int> &data)
{
    int res = 0;
    for (int i = 0; i < data.size(); i++)
        res += data[i] / len;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> data;
    data.resize(n);

    int max_len = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
        if (data[i] > max_len)
            max_len = data[i];
    }

    int l = 1, r = max_len, mid, c = -1;

    while (l < r)
    {
        mid = (l + r) / 2;
        if (count(mid, data) >= k)
            l = mid + 1;
        else
            r = mid;
    }

    cout << l - 1 << endl;
    
    return 0;
}