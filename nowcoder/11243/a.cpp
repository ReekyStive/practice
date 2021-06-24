// #include <iostream>
#include <cstdio>

using namespace std;

double solve(int total, int selected)
{
    if (selected == total)
        return 0.0;

    int cur = selected + 1;
    int remain = total - 1 - selected;

    return 1.0 / total * cur +
           (double)selected / total * cur +
           (double)remain / total * solve(total, selected + 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%.2lf\n", solve(n, 0));
    return 0;
}
