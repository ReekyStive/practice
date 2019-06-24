#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, action, val;
    vector<int> heapval;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> action;
        switch (action)
        {
            case 1:
                cin >> val;
                heapval.insert(lower_bound(heapval.begin(), heapval.end(), val), val);
                break;
            case 2:
                cout << heapval[0] << endl;
                break;
            case 3:
                heapval.erase(heapval.begin());
                break;
        }
    }
    return 0;
}
