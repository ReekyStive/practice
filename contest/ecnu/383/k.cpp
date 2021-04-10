#include <iostream>

using namespace std;

bool prime[300000001];

void gen_prime(int upper)
{
    prime[0] = false, prime[1] = false;
    for (int i = 2; i <= upper; i++)
        prime[i] = true;

    for (int i = 2; i <= upper / 2; i++)
    {
        if (!prime[i])
            continue;
        for (long long j = i; j * i <= upper; j++)
            prime[j * i] = false;
    }
}

bool valid(int l, int k)
{
    gen_prime(l + 2 * k);
    int count = 0;
    for (int i = l; i < l + 2 * k; i++)
    {
        if (prime[i])
            count++;
    }
    if (count > k)
        return true;
    else
        return false;
}

int main()
{
    int l, k;
    cin >> l >> k;

    if (valid(l, k))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
