#include <iostream>

using namespace std;

const int n = 10;
int k[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int binary_search(int x)
{
    int l = 0, r = n;
    while (r - l >= 1)
    {
        int mid = (l + r) / 2;
        if (k[mid] == x)
            return mid;
        if (k[mid] > x)
            r = mid;
        else
            l = mid + 1;
    }
    return -1;
}

int main()
{
    while (true)
    {
        int x;
        cin >> x;
        cout << binary_search(x) << endl;
    }
    return 0;
}
