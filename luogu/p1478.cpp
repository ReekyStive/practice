#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 5000;
struct Apple
{
    int height;
    int cost;
    bool operator<(const Apple &val)
    {
        return cost < val.cost;
    }
};
Apple apples[MAX_N];

int main()
{
    int n, s, a, b;
    cin >> n >> s >> a >> b;

    for (int i = 0; i < n; i++)
        cin >> apples[i].height >> apples[i].cost;

    sort(apples, apples + n);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s >= apples[i].cost)
        {
            if (a + b >= apples[i].height)
            {
                count++;
                s -= apples[i].cost;
            }
        }
        else
            break;
    }

    cout << count << endl;
    
    return 0;
}
