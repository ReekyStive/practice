#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;

map<char, vector<map<char, int> > > g =
{
    {'A', {{{'B', 5}}, {{'C', 1}}}},
    {'B', {{{'A', 5}}, {{'C', 2}}}},
    {'C', {{{'A', 1}}, {{'B', 2}}, {{'D', 4}}}},
    {'D', {{{'B', 1}}, {{'C', 4}}, {{'E', 3}}, {{'F', 6}}}},
    {'E', {{{'C', 8}}, {{'D', 3}}}},
    {'F', {{{'D', 6}}}}
};

vector<char> bfs(map<char, vector<map<char, int> > > g, char s);
vector<char> dfs(map<char, vector<map<char, int> > > g, char s);

int main()
{
    vector<char> list;
    // char s;
    // cin >> s;

    cout << "BFS: " << endl;
    for (char i = 'A'; i <= 'F'; i++)
    {
        list = bfs(g, i);
        cout << "Begin: " << i << endl;

        for (int i = 0; i < list.size(); i++)
        {
            cout << list[i] << " ";
        }
        cout << endl << endl;
    }
    cout << endl;

    cout << "DFS: " << endl;
    for (char i = 'A'; i <= 'F'; i++)
    {
        list = dfs(g, i);
        cout << "Begin: " << i << endl;

        for (int i = 0; i < list.size(); i++)
        {
            cout << list[i] << " ";
        }
        cout << endl << endl;
    }

    return 0;
}

vector<char> bfs(map<char, vector<map<char, int> > > g, char s)
{
    vector<char> list;
    queue<char> q;
    q.push(s);
    set<char> seen;
    seen.insert(s);
    char cur, fro;

    while (!q.empty())
    {
        fro = q.front();
        q.pop();
        list.push_back(fro);

        for (int i = 0; i < g[fro].size(); i++)
        {
            cur = g[fro][i].begin() -> first;
            if (seen.find(cur) == seen.end())
            {
                q.push(g[fro][i].begin() -> first);
                seen.insert(cur);
            }
        }
    }

    return list;
}

vector<char> dfs(map<char, vector<map<char, int> > > g, char s)
{
    vector<char> list;
    stack<char> q;
    q.push(s);
    set<char> seen;
    seen.insert(s);
    char cur, fro;

    while (!q.empty())
    {
        fro = q.top();
        q.pop();
        list.push_back(fro);

        for (int i = 0; i < g[fro].size(); i++)
        {
            cur = g[fro][i].begin() -> first;
            if (seen.find(cur) == seen.end())
            {
                q.push(g[fro][i].begin() -> first);
                seen.insert(cur);
            }
        }
    }

    return list;
}
