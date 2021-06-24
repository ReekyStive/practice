#include <iostream>

using namespace std;

int digit = 1;
int number = 1;

void reset()
{
    digit = 1;
    number = 1;
}

int next_ordinary()
{
    int res = 0;
    for (int i = 0; i < digit; i++)
    {
        res *= 10;
        res += number;
    }
    number++;
    if (number == 10)
    {
        number = 1;
        digit++;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        reset();
        int n;
        cin >> n;
        int count = 0;
        while (next_ordinary() <= n)
            count++;
        cout << count << endl;
    }
    return 0;
}
