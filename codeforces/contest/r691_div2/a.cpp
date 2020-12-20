#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    string sr, sb;
    int cntr, cntb, n;

    for (int f = 0; f < t; f++)
    {
        sr.clear();
        sb.clear();
        cntr = 0;
        cntb = 0;

        cin >> n;
        cin.get();

        getline(cin, sr);
        getline(cin, sb);

        for (int i = 0; i < n; i++)
        {
            if (sr[i] > sb[i])
                cntr++;
            else if (sb[i] > sr[i])
                cntb++;
        }

        if (cntr > cntb)
            cout << "RED" << endl;
        else if (cntb > cntr)
            cout << "BLUE" << endl;
        else
            cout << "EQUAL" << endl;
    }

    return 0;
}