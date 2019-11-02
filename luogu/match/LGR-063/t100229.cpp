#include <iostream>
#include <set>
#include <algorithm>

const int max_n = 5;
int a[max_n], b[max_n], c[max_n];

struct Tri
{
    int x, y, z;

    bool operator<(const Tri& r) const
    {
        return !((x == r.x) && (y == r.y) && (z == r.z));
    }

    Tri(int nx, int ny, int nz)
    {
        x = nx;
        y = ny;
        z = nz;
    }
};

bool able(int x, int y, int n, int m)
{
    std::set<int> ables;

    int nrc = abs(a[0] - x) ^ abs(b[0] - y) ^ 9;
    int nz_a = c[0] - nrc;
    int nz_b = c[0] + nrc;

    if (nz_a >= 1 && nz_a <= m)
        ables.insert(nz_a);
    if (nz_a >= 1 && nz_a <= m)
        ables.insert(nz_b);

    for (int i = 1; i < n; i++)
    {
        int rc = abs(a[i] - x) ^ abs(b[i] - y) ^ 9;
        int z_a = c[i] - rc;
        int z_b = c[i] + rc;
        bool able_z_a = false;
        bool able_z_b = false;

        if (ables.count(z_a) > 0)
            able_z_a = true;
        if (ables.count(z_b) > 0)
            able_z_b = true;

        ables.clear();
        
        if (able_z_a)
            ables.insert(z_a);
        if (able_z_b)
            ables.insert(z_b);

        if (ables.size() == 0)
            return false;
    }

    if (ables.size() > 0)
        return true;

    return false;
}

bool suit(int x, int y, int z, int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((abs(a[i] - x) ^ abs(b[i] - y) ^ abs(c[i] - z)) != 9)
            return false;
    }
    return true;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < n; i ++)
        std::cin >> a[i] >> b[i] >> c[i];

    std::set<Tri> result;

    for (int x = 1; x <= m; x++)
    {
        for (int y = 1; y <= m; y++)
        {
            if (!able(x, y, n, m))
                continue;
            for (int z = 1; z <= m; z++)
            {
                if (suit(x, y, z, n))
                    result.insert(Tri(x, y, z));
            }
        }
    }

    std::cout << result.size() << std::endl;

    return 0;
}