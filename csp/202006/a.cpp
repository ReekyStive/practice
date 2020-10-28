#include <iostream>
#include <vector>

using namespace std;

struct Pos
{
    int x;
    int y;
    int type;
};
vector<Pos> datas;

int line(int x, int y, int a, int b, int c)
{
    int res;
    res = a + b * x + c * y;
    return res;
}

bool perfect(int a, int b, int c)
{
    if (line(datas[0].x, datas[0].y, a, b, c) == 0)
        return false;

    bool positive_type;
    if (line(datas[0].x, datas[0].y, a, b, c) > 0)
        positive_type = datas[0].type;
    else
        positive_type = !datas[0].type;

    for (int i = 1; i < datas.size(); i++)
    {
        if (line(datas[i].x, datas[i].y, a, b, c) > 0)
        {
            if (datas[i].type != positive_type)
                return false;
        }
        else
        {
            if (line(datas[i].x, datas[i].y, a, b, c) < 0)
            {
                if (datas[i].type != !positive_type)
                    return false;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    datas.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> datas[i].x >> datas[i].y;
        char type;
        cin >> type;
        if (type == 'A')
            datas[i].type = 0;
        else
            datas[i].type = 1;
    }

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if (perfect(a, b, c))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}