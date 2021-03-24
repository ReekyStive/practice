// 1/4 ACed

#include <iostream>

using namespace std;

int main()
{
    double a;
    int b;
    double c;

    scanf("%lf %d %lf", &a, &b, &c);
    double res;
    if (b == 0)
        res = a * 2.455;
    else
        res = a * 1.26;

    printf("%.2lf ", res);
    if (res < c)
        printf("^_^\n");
    else
        printf("T_T\n");

    return 0;
}
