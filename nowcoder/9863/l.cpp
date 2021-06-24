#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item
{
    int x;
    int y;
    int a;
    int h;
};

bool cmp(item l, item r)
{
    if (l.x > r.x)
    {
        return true;
    }
    else if (l.x < r.x)
    {
        return false;
    }
    else
    {
        if (l.y > r.y)
        {
            return true;
        }
        else if (l.y < r.y)
        {
            return false;
        }
        else
        {
            if (l.a < r.a)
            {
                return true;
            }
            else if (l.a > r.a)
            {
                return false;
            }
            else
            {
                return l.h < r.h;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<item> unread;
    unread.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> unread[i].x >> unread[i].y >> unread[i].a;
        unread[i].h = i + 1;
    }

    sort(unread.begin(), unread.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        cout << unread[i].h << ' ';
        if (unread[i].a > 99)
            cout << "99+";
        else
            cout << unread[i].a;
        cout << endl;
    }

    return 0;
}