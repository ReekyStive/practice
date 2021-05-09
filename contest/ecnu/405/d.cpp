#include <cstdio>

using namespace std;

int a[(int)2e5];

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        int k = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        for (int i = 0; i < m; i++)
        {
            int temp;
            scanf("%d", &temp);
            k += temp - 1;
            k %= n;
        }

        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[(k + i) % n]);
        }
        printf("\n");
    }
    return 0;
}
