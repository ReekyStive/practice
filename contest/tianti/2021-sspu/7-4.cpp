#include <cstdio>

using namespace std;

int main()
{
    double weight, height;
    scanf("%lf %lf", &weight, &height);
    double res = weight / (height * height);
    printf("%.1lf\n", res);
    if (res > 25.0)
        printf(("PANG\n"));
    else
        printf("Hai Xing\n");
    return 0;
}
