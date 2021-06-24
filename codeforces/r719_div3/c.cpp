#include <iostream>

using namespace std;

int matrix[100][100];

void init()
{
    matrix[0][0] = 1, matrix[0][1] = 4, matrix[0][2] = 2;
    matrix[1][0] = 5, matrix[1][1] = 9, matrix[1][2] = 6;
    matrix[2][0] = 7, matrix[2][1] = 3, matrix[2][2] = 8;
}

void gen_matrix(int n)
{
    int cur = 10;
    for (int i = 4; i <= n; i++)
    {
        matrix[i - 1][i - 1] = cur;
        cur++;
        for (int j = 1; j <= i - 1; j++)
        {
            matrix[j - 1][i - 1] = cur;
            cur++;
            matrix[i - 1][j - 1] = cur;
            cur++;
        }
    }
}

void print_matrix(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        if (n == 2)
        {
            cout << -1 << endl;
            continue;
        }

        gen_matrix(n);
        print_matrix(n);
    }
    return 0;
}
