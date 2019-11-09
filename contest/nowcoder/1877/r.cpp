#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int tmp;
    set<int> s;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (s.count(tmp) == 0)
        {
            s.insert(tmp);
            q.push(tmp);
        }
    }

    bool space = false;
    while (!q.empty())
    {
        if (space)
            cout << " ";
        cout << q.top();
        q.pop();
        space = true;
    }

    cout << endl;

    return 0;
}