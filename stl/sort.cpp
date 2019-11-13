#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {-1, 5, 4, 3, 2, 1, 6};

    sort(v.begin(), v.end());
    // nth_element(v.begin(), v.begin() + 1, v.end());
    // partial_sort(v.begin(), v.begin() + 3, v.end());

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}