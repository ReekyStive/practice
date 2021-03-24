#include <cstdio>

using namespace std;

int main()
{
    int price;
    int factor;
    scanf("%d %d", &price, &factor);
    printf("%.2lf\n", (double)price * (double)factor / 10.0);
    return 0;
}
