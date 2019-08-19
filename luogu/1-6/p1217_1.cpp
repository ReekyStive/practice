#include <iostream>
#include <cmath>

using namespace std;

bool prim(int n)
{
    if (n == 2)
        return false;
    if (n <= 3)
        return true;

    for (int i = 2; i <= ceil(sqrt(n)); i++)
        if (n % i == 0)
            return false;
    
    return true;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int palindrome;

    for(int d1 = 1; d1 <= 9; d1 += 2)
    {
        palindrome = d1;
        if (palindrome < a)
            continue;
        if (palindrome > b)
            return 0;
        if (prim(palindrome))
            cout << palindrome << endl;
    }

    if (a <= 11 && b >= 11)
        cout << 11 << endl;

    for(int d1 = 1; d1 <= 9; d1 += 2)
        for(int d2 = 0; d2 <= 9; d2++)
        {
            palindrome = 100*d1 + 10*d2 + d1;
            if (palindrome < a)
                continue;
            if (palindrome > b)
                return 0;
            if (prim(palindrome))
                cout << palindrome << endl;
        }

    for(int d1 = 1; d1 <= 9; d1 += 2)
        for(int d2 = 0; d2 <= 9; d2++)
            for(int d3 = 0; d3 <= 9; d3++)
            {
                palindrome = 10000*d1 + 1000*d2 + 100*d3 + 10*d2 + d1;
                if (palindrome < a)
                    continue;
                if (palindrome > b)
                    return 0;
                if (prim(palindrome))
                    cout << palindrome << endl;
            }

    for(int d1 = 1; d1 <= 9; d1 += 2)
        for(int d2 = 0; d2 <= 9; d2++)
            for(int d3 = 0; d3 <= 9; d3++)
                for(int d4 = 0; d4 <= 9; d4++)
                {
                    palindrome = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1;
                    if (palindrome < a)
                        continue;
                    if (palindrome > b)
                        return 0;
                    if (prim(palindrome))
                        cout << palindrome << endl;
                }
    
    return 0;
}
