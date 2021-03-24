#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int count[100];
    for (int i = 0; i < n; i++)
        cin >> count[i];

    vector<ostringstream> ostr(n);

    int cur = 1;
    int last_team = -1;

    for (int i = 1; i <= 10; i++) // count >= i
    {
        for (int j = 0; j < 10; j++) // 10 members
        {
            for (int k = 0; k < n; k++) // k-th team
            {
                if (count[k] >= i)
                {
                    if (last_team == k)
                        cur++;

                    ostr[k] << cur;
                    last_team = k;

                    if (j != 9)
                        ostr[k] << " ";

                    cur++;
                    if (j == 9)
                        ostr[k] << endl;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "#" << i + 1 << endl;
        cout << ostr[i].str();
    }

    return 0;
}
