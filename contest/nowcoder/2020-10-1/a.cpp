#include <iostream>
#include <vector>
using namespace std;

vector<char> colors;

int main()
{
    int N;
    cin >> N;
    char c;
    for (int i = 0; i < N; i++)
    {
        cin >> c;
        colors.push_back(c);
    }

    int res = 0;
    while (!colors.empty())
    {
        if (colors.size() == 1)
            break;

        if (colors[0] == colors[colors.size() - 1])
        {
            colors.erase(colors.begin());
            colors.erase(colors.end() - 1);
        }
        else
        {
            colors.erase(colors.begin());
            res++;
        }
    }

    cout << res << endl;

    return 0;
}