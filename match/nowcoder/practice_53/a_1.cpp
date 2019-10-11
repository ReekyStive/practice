#include <iostream>

using namespace std;

const long long mod = 1000000007;
const int max_n = 100000;

int mem[max_n + 1];

int fib(int n)
{
    if (n <= 2)
        return 1;
    
    if (mem[n] > 0)
        return mem[n] - 1;
    
    mem[n] = (fib(n - 1) + fib(n - 2)) % mod + 1;
    return mem[n] - 1;
}

int main()
{
    int n;
    cin >> n;

    cout << fib(n + 2) << endl;

    return 0;
}
