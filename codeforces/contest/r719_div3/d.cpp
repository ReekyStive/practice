#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        map<int, int> log;
        int n;
        cin >> n;
        long long count = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if (log.count(temp - i) > 0)
                count += log[temp - i];
            
            if (log.count(temp - i) > 0)
                log[temp - i]++;
            else
                log[temp - i] = 1;
        }
        cout << count << endl;
    }
    return 0;
}
