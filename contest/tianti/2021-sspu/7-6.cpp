#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    int n[6];

    while (t--)
    {
        for (int i = 0; i < 6; i++)
            n[i] = getchar() - '0';
        getchar();

        if (n[0] + n[1] + n[2] == n[3] + n[4] + n[5])
            printf("You are lucky!\n");
        else
            printf("Wish you good luck.\n");
    }

    return 0;
}
