#include <iostream>

using namespace std;

const int MAX_N = 9;

// in each 1*2 unit:
//    y       y
//   -----------------
// x |down   |right  |
//   -----------------
bool graph[MAX_N][MAX_N * 2];

int n, m;

void clear()
{
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N * 2; j++)
            graph[i][j] = false;
}

bool is_connect(int x, int y, char direction)
{
    y = y * 2;
    if (direction == 'H')
        y++;
    
    return graph[x][y];
}

void connect(int x, int y, char direction)
{
    y = y * 2;
    if (direction == 'H')
        y++;
    
    graph[x][y] = true;
}

bool is_square(int x, int y, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (!is_connect(x, y + i, 'H'))
            return false;
        if (!is_connect(x + i, y, 'V'))
            return false;
    }

    x += size;
    y += size;

    for (int i = size; i > 0; i--)
    {
        if (!is_connect(x, y - i, 'H'))
            return false;
        if (!is_connect(x - i, y, 'V'))
            return false;
    }

    return true;
}

int counter(int size)
{
    int count = 0;

    for (int i = 0; i < n - size; i++)
        for (int j = 0; j < n - size; j++)
            if (is_square(i, j, size))
                count++;
    
    return count;
}

int main()
{
    int a, b, problems = 0;
    char direction;

    while (!cin.eof())
    {
        problems++;

        if (problems != 1)
            cout << "\n**********************************\n\n";
        
        cout << "Problem #" << problems << endl << endl;

        cin >> n >> m;

        for (int i = 0; i < m; i++)
        {
            cin >> direction >> a >> b;
            a--;
            b--;
            if (direction == 'V')
                connect(b, a, direction);
            else
                connect(a, b, direction);
        }

        int count;
        bool exist = false;
        for (int size = 1; size < n; size++)
        {
            count = counter(size);
            if (count != 0)
            {
                exist = true;
                cout << count << " square (s) of size " << size << endl;
            }
        }

        if (!exist)
            cout << "No completed squares can be found." << endl;

        clear();
        cin.get();
    }

    return 0;
}
