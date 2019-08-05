#include <iostream>

using namespace std;

int a, b, c;
int second, third;
bool mem[10];

bool determin(int first)
{
    second = first * b / a;
    if ((float)first * b / a - second > 0.01)
        return false;
    
    third = first * c / a;
    if ((float)first * c / a - third > 0.01)
        return false;

    if (second > 999 || third > 999)
        return false;

    for (int i = 1; i <= 9; i++)
        mem[i] = false;

    long long num = first * 1000000 + second * 1000 + third;
    int bit;

    while (num != 0)
    {
        bit = num % 10;
        num /= 10;
        if (mem[bit])
            return false;
        mem[bit] = true;
    }

    return true;
}

int main()
{
    cin >> a >> b >> c;

    int first, count = 0;

    for (int d1 = 1; d1 <= 3; d1++)
        for (int d2 = 1; d2 <= 9; d2++)
            for (int d3 = 1; d3 <= 9; d3++)
            {
                if (d1 == d2 || d2 == d3 || d1 == d3)
                    continue;

                first = d1 * 100 + d2 * 10 + d3;
                if (determin(first))
                {
                    cout << first << " " << second << " " << third << " " << endl;
                    count++;
                }
            }
    
    if (count == 0)
        cout << "No!!!" << endl;

    return 0;
}
