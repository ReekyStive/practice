// [USACO 1.3] Mixing Milk

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct MilkProvider
{
    int price;
    int count;
    bool operator>(const MilkProvider &right) const
    {
        return this -> price > right.price;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    priority_queue<MilkProvider, vector<MilkProvider>, greater<MilkProvider> > pqueue;
    MilkProvider provider;
    for (int i = 0; i < m; i++)
    {
        cin >> provider.price >> provider.count;
        pqueue.push(provider);
    }

    int bought = 0, cost = 0;

    while (!pqueue.empty())
    {
        provider = pqueue.top();
        pqueue.pop();
        
        if (bought + provider.count <= n)
        {
            bought += provider.count;
            cost += provider.price * provider.count;
        }
        else
            break;
    }
    cost += provider.price * (n - bought);

    cout << cost << endl;

    return 0;
}
