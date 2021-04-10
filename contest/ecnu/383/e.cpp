#include <iostream>
#include <vector>

using namespace std;

// struct node
// {
//     int id;
//     int depth;
//     node *father;
//     vector<node *> sons;
// };

bool edges[100001][100001];

// node root;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a][b] = true;
        edges[b][a] = true;
    }

    return 0;
}
