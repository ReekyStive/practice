// Not Tested

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 100000;
struct node
{
    int id;
    int data;
    bool operator>(const node &right) const
    {
        return this->data > right.data;
    }
    bool operator<(const node &right) const
    {
        return this->data < right.data;
    }
};
node h[maxn + 1];
int ans[maxn + 1];

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        priority_queue<node, vector<node>, greater<node>> pq;
        int n, m, x;
        cin >> n >> m >> x;

        for (int i = 0; i < n; i++)
            h[i].id = i, cin >> h[i].data;
        sort(h, h + n, less<node>());

        for (int i = 0; i < m; i++)
        {
            node temp;
            temp.data = 0, temp.id = i;
            pq.push(temp);
        }
        for (int i = 0; i < n; i++)
        {
            node temp = pq.top();
            pq.pop();
            temp.data += h[i].data;
            pq.push(temp);
            ans[h[i].id] = temp.id + 1;
        }

        int minn = pq.top().data;
        while (pq.size() != 1)
            pq.pop();
        int maxx = pq.top().data;
        pq.pop();

        if (maxx - minn <= x)
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
                cout << ans[i] << " ";
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
