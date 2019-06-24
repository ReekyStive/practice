#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
    string a, line;
    int first = 0, time = 0, i = 0, j = 0, eq = false;
    char c;

    cin >> a;
    cin.ignore();
    getline(cin, line);

    transform(a.begin(), a.end(), a.begin(), (int (*)(int))tolower);
    transform(line.begin(), line.end(), line.begin(), (int (*)(int))tolower);

    for (i = 0; i < line.length(); i++)
    {
        if (time == 0)
            first = i;
        
        if (isalpha(line[i]))
        {
            eq = true;

            for (j = 0; j < a.length(); i++, j++)
            {
                if (line[i] != a[j])
                {
                    eq = false;
                    break;
                }
            }
            
            if (eq)
            {
                i--;
                j--;
            }

            if (eq && line[i] == a[j] && !isalpha(line[i + 1]))
                time++;
                
            while (i < line.length() && isalpha(line[i]))
                i++;
        }
    }
    
    if (time == 0)
        cout << -1;
    else
        cout << time << " " << first;

    system("pause");
    return 0;
}
