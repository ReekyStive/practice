#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    priority_queue<ll, vector<ll>, greater<ll>> pque;
    long long temp, res = 0;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        pque.push(temp);
    }

    while (pque.size() > 1) {
        temp = pque.top();
        pque.pop();
        temp += pque.top();
        pque.pop();

        res += temp;

        pque.push(temp);
    }

    cout << res << endl;

    return 0;
}
