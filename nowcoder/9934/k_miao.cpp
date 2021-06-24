#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define ll long long
const int maxn = 2e5 + 10;

struct node
{
    ll a, b;
    bool operator<(const node &x) const
    {
        if (a == x.a)
            return b < x.b;
        return a > x.a;
    }
} an[maxn];
priority_queue<ll> q;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> an[i].a;
    for (int i = 1; i <= n; i++)
        cin >> an[i].b;
    sort(an + 1, an + n + 1);
    an[n + 1].a = 0;
    ll ans = 0x3f3f3f3f3f3f3f;
    q.push(0);
    for (int i = 1; i <= n + 1; i++)
    {
        ans = min(ans, an[i].a + q.top());
        q.push(an[i].b);
    }
    cout << ans << endl;
    return 0;
}