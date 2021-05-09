#include <cstdio>
using namespace std;

char field[100][100];
int n, m;

void dfs(int x, int y)
{
    field[x][y] = '.';
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && field[nx][ny] == 'W')
                dfs(nx, ny);
        }
    }
    return;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf(" %c", &field[i][j]);
        getchar();
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (field[i][j] == 'W')
            {
                dfs(i, j);
                res++;
            }
        }
    }
    printf("%d\n", res);

    return 0;
}