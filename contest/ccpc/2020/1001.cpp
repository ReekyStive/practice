#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int times, type, last_type;
        bool correct = true;
        cin >> times;

        cin >> type;
        times--;
        for (int i = 0; i < times; i++)
        {
            last_type = type;
            cin >> type;
            if (type == last_type)
                correct = false;
        }

        if (correct)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}