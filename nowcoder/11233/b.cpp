#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string s;
    getline(cin, s);

    if (s.length() == 1)
    {
        cout << "0" << endl;
        return 0;
    }

    unsigned long long count_a = 0;
    unsigned long long count_ab = 0;
    unsigned long long count_aab = 0;
    if (s[0] == 'a')
        count_a++;

    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == 'a')
            count_a++;
        else if (s[i] == 'b')
        {
            count_ab += count_a;
            count_aab += count_a * (count_a - 1) / 2;
        }
    }
    unsigned long long count_aa = count_a * (count_a - 1) / 2;

    unsigned long long count_1 = count_aab + count_ab;
    unsigned long long count_2 = count_aab + count_aa;
    cout << max(count_1, count_2) << endl;

    return 0;
}
