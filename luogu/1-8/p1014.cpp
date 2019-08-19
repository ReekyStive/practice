#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 1, line = 1, column = 1;
    bool up = true;

    if (n != 1)
    {
        while (n >= i)
        {
            n -= i;
            i++;
            up = !up;

            if (column == 1)
            {
                line++;
                column = line;
                line = 1;
            }
            else
            {
                column++;
                line = column;
                column = 1;
            }
        }

        if (n == 0)
        {
            if (line == 1)
                column--;
            if (column == 1)
                line--;
        }
        else if (n >= 1)
        {
            if (up)
            {
                line -= (n - 1);
                column += (n - 1);
            }
            else
            {
                line += (n - 1);
                column -= (n - 1);
            }
        }
    }

    cout << line << "/" << column << endl;
}
