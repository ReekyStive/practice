#include <iostream>
#include <algorithm>
using namespace std;

const int inf = __INT_MAX__ / 4;

int main()
{
    int apex, side, a, b, val;
    cin >> apex >> side;
    int graph[apex][apex];

    for (int i = 0; i < apex; i++)
        for (int j = 0; j < apex; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = inf;
        }

    for (int i = 0; i < side; i++)
    {
        cin >> a >> b >> val;
        graph[a][b] = val;
    }

    for (int i = 0; i < apex; i++)
        for(int j = 0; j < apex; j++)
            for(int k = 0; k < apex; k++)
                if (graph[j][k] > graph[j][i] + graph[i][k])
                    graph[j][k] = graph[j][i] + graph[i][k];

    for (int i = 0; i < apex; i++)
    {
        for(int j = 0; j < apex; j++)
        {
            cout.width(5);
            if (graph[i][j] == inf)
                cout << -1;
            else
                cout << graph[i][j];
        }
        cout << endl;
    }

    return 0;
}
