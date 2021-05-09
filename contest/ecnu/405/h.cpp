#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5;
int a[maxn], b[maxn];
struct node
{
    int id;
    int value;
    bool operator>(const node &right) const
    {
        return this->value > right.value;
    }
};
node c[maxn];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        for (int i = 0; i < n; i++)
        {
            c[i].id = i;
            c[i].value = a[i] + b[i];
        }
        sort(c, c + n, greater<node>());

        long long s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                s1 += a[c[i].id];
            else
                s2 += b[c[i].id];
        }

        if (s1 > s2)
            printf("Alice\n");
        else if (s2 > s1)
            printf("Bob\n");
        else
            printf("AEMSHANA\n");
    }
    return 0;
}
