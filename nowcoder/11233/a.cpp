#include <iostream>
#include <algorithm>

using namespace std;

struct point
{
    long long x;
    long long y;
};

point p[4];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 4; i++)
            cin >> p[i].x >> p[i].y;

        int index[4] = {0, 1, 2, 3};
        bool valid = false;
        do
        {
            long long dx1 = p[index[0]].x - p[index[1]].x;
            long long dy1 = p[index[0]].y - p[index[1]].y;
            long long dx2 = p[index[2]].x - p[index[3]].x;
            long long dy2 = p[index[2]].y - p[index[3]].y;
            bool parallel = dx1 * dy2 == dx2 * dy1;
            bool equal_x = dx1 == dx2;
            if (parallel && equal_x)
            {
                valid = true;
                int index1[3] = {0, 1, 2};
                for (int i = 0; i < 4; i++)
                {
                    int cur = 0;
                    for (int j = 0; j < 4; j++)
                    {
                        if (j == i)
                            continue;
                        index1[cur++] = j;
                    }
                    long long ddx1 = p[index1[1]].x - p[index1[0]].x;
                    long long ddy1 = p[index1[1]].y - p[index1[0]].y;
                    long long ddx2 = p[index1[2]].x - p[index1[0]].x;
                    long long ddy2 = p[index1[2]].y - p[index1[0]].y;
                    if (ddx1 * ddy2 == ddx2 * ddy1)
                    {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid)
                break;
        } while (next_permutation(index, index + 4));

        if (valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
