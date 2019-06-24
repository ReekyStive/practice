#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    string ss, tems;
    int times['Z' - 'A' + 1] = {0}, height;
    char temp;

    for (int i = 0; i < 4; i++)
    {
        getline(cin, tems);
        ss += tems;
    }
    istringstream sstream(ss);

    while (sstream >> temp)
    {
        if (temp >= 'A' && temp <= 'Z')
            times[temp - 'A']++;
    }

    height = *max_element(times, times + 26);

    for (int i = height; i >= 1; i--)
    {
        for (char j = 'A'; j <= 'Z'; j++)
        {
            if (times[j - 'A'] >= i)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }

    for (char i = 'A'; i <= 'Z'; i++)
        cout << i << ' ';
    
    return 0;
}
