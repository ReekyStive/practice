#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int ma, mi;
    int data;

    scanf("%d", &data);
    ma = data;
    mi = data;

    long long sum = data;
    double ave;
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &data);
        if (data > ma)
            ma = data;
        if (data < mi)
            mi = data;

        sum += data;
        if (i >= 3)
        {
            ave = (double)(sum - ma - mi) / (double)(i - 2);
            printf("%.2lf\n", ave);
        }
    }

    return 0;
}