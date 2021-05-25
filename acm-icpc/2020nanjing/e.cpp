// Wrong Answer

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;

        int dx = 0, dy = 0;
        int uc = 0, dc = 0, lc = 0, rc = 0;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (*it == 'U')
                dy += 1, uc++;
            if (*it == 'D')
                dy -= 1, dc++;
            if (*it == 'R')
                dx += 1, rc++;
            if (*it == 'L')
                dx -= 1, lc++;
        }

        if ((x == 0 && y == 0) || (x == dx && y == dy))
        {
            cout << "Impossible" << endl;
            continue;
        }

        if (dx != 0 && dy != 0)
        {
            if (y == dy || x == 0) // R -> U
            {
                int _dx = dx < 0 ? -dx : dx;
                char _cx = dx < 0 ? 'L' : 'R';
                for (int i = 0; i < _dx; i++)
                    cout << _cx;

                int _rx = dx < 0 ? rc : lc;
                for (int i = 0; i < _rx; i++)
                    cout << "RL";

                int _dy = dy < 0 ? -dy : dy;
                char _cy = dx < 0 ? 'D' : 'U';
                for (int i = 0; i < _dy; i++)
                    cout << _cy;

                int _ry = dy < 0 ? uc : dc;
                for (int i = 0; i < _ry; i++)
                    cout << "UD";
            }
            else // U -> R
            {
                int _dy = dy < 0 ? -dy : dy;
                char _cy = dx < 0 ? 'D' : 'U';
                for (int i = 0; i < _dy; i++)
                    cout << _cy;

                int _ry = dy < 0 ? uc : dc;
                for (int i = 0; i < _ry; i++)
                    cout << "UD";

                int _dx = dx < 0 ? -dx : dx;
                char _cx = dx < 0 ? 'L' : 'R';
                for (int i = 0; i < _dx; i++)
                    cout << _cx;

                int _rx = dx < 0 ? rc : lc;
                for (int i = 0; i < _rx; i++)
                    cout << "RL";
            }
            cout << endl;

            continue;
        }

        if (dx == 0 && dy == 0)
        {
            if (x == 0 && y == 1)
            {
                for (int i = 0; i < uc; i++)
                    cout << "DU";
            }
            else
            {
                for (int i = 0; i < uc; i++)
                    cout << "UD";
            }

            if (x == 1 && y == 0)
            {
                for (int i = 0; i < rc; i++)
                    cout << "LR";
            }
            else
            {
                for (int i = 0; i < rc; i++)
                    cout << "RL";
            }

            cout << endl;
            continue;
        }

        if (dx == 0)
        {
            if (dy > 0)
            {
                if (x == 0 && y > 0 && y < dy)
                {
                    if (rc == 0)
                    {
                        cout << "Impossible";
                    }
                    else
                    {
                        for (int i = 0; i < rc; i++)
                            cout << "R";
                        for (int i = 0; i < dc; i++)
                            cout << "D";
                        for (int i = 0; i < uc; i++)
                            cout << "U";
                        for (int i = 0; i < lc; i++)
                            cout << "L";
                    }
                }
                else
                {
                    for (int i = 0; i < dy; i++)
                    {
                        cout << "U";
                    }
                    for (int i = 0; i < dc; i++)
                    {
                        cout << "DU";
                    }

                    if (y == dy && x == 1)
                    {
                        for (int i = 0; i < lc; i++)
                            cout << "LR";
                    }
                    else
                    {
                        for (int i = 0; i < lc; i++)
                            cout << "RL";
                    }
                }
            }

            if (dy < 0)
            {
                if (x == 0 && y < 0 && y > dy)
                {
                    if (rc == 0)
                    {
                        cout << "Impossible";
                    }
                    else
                    {
                        for (int i = 0; i < rc; i++)
                            cout << "R";
                        for (int i = 0; i < uc; i++)
                            cout << "U";
                        for (int i = 0; i < dc; i++)
                            cout << "D";
                        for (int i = 0; i < lc; i++)
                            cout << "L";
                    }
                }
                else
                {
                    for (int i = 0; i < -dy; i++)
                    {
                        cout << "D";
                    }
                    for (int i = 0; i < uc; i++)
                    {
                        cout << "UD";
                    }

                    if (y == dy && x == 1)
                    {
                        for (int i = 0; i < lc; i++)
                            cout << "LR";
                    }
                    else
                    {
                        for (int i = 0; i < lc; i++)
                            cout << "RL";
                    }
                }
            }

            cout << endl;
            continue;
        }

        if (dy == 0)
        {
            if (dx > 0)
            {
                if (y == 0 && x > 0 && x < dx)
                {
                    if (uc == 0)
                    {
                        cout << "Impossible";
                    }
                    else
                    {
                        for (int i = 0; i < uc; i++)
                            cout << "U";
                        for (int i = 0; i < lc; i++)
                            cout << "L";
                        for (int i = 0; i < rc; i++)
                            cout << "R";
                        for (int i = 0; i < dc; i++)
                            cout << "D";
                    }
                }
                else
                {
                    for (int i = 0; i < dx; i++)
                    {
                        cout << "R";
                    }
                    for (int i = 0; i < lc; i++)
                    {
                        cout << "LR";
                    }

                    if (x == dx && y == 1)
                    {
                        for (int i = 0; i < uc; i++)
                            cout << "DU";
                    }
                    else
                    {
                        for (int i = 0; i < uc; i++)
                            cout << "UD";
                    }
                }
            }

            if (dx < 0)
            {
                if (y == 0 && x < 0 && x > dx)
                {
                    if (uc == 0)
                    {
                        cout << "Impossible";
                    }
                    else
                    {
                        for (int i = 0; i < uc; i++)
                            cout << "U";
                        for (int i = 0; i < rc; i++)
                            cout << "R";
                        for (int i = 0; i < lc; i++)
                            cout << "L";
                        for (int i = 0; i < dc; i++)
                            cout << "D";
                    }
                }
                else
                {
                    for (int i = 0; i < -dx; i++)
                    {
                        cout << "L";
                    }
                    for (int i = 0; i < rc; i++)
                    {
                        cout << "RL";
                    }

                    if (x == dx && y == 1)
                    {
                        for (int i = 0; i < uc; i++)
                            cout << "DU";
                    }
                    else
                    {
                        for (int i = 0; i < uc; i++)
                            cout << "UD";
                    }
                }
            }
        }

        cout << endl;
        continue;
    }
    return 0;
}
