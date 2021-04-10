#include <iostream>

using namespace std;

bool prime[10000001];
int primes[6650000];
int pcnt = 0;

void gen_prime(int upper)
{
    prime[0] = false, prime[1] = false;
    for (int i = 2; i <= upper; i++)
        prime[i] = true;

    for (int i = 2; i <= upper; i++)
    {
        if (!prime[i])
            continue;
        primes[pcnt++] = i;
        for (long long j = i; j * i <= upper; j++)
            prime[j * i] = false;
    }
}

int calc_r(int tar, int val)
{
    int count = 0;
    int tmp = tar;
    while (val >= tmp)
    {
        count += val / tmp;
        tmp *= tar;
    }
    return count;
}

int calc(int tar, int l, int r)
{
    return calc_r(tar, r) - calc_r(tar, l - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    gen_prime(10000000);

    int t;
    cin >> t;
    while (t--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if (l1 >= l2 && r1 <= r2)
        {
            cout << "Yes" << endl;
            continue;
        }

        bool valid = true;
        for (int i = 0; i < pcnt; i++)
        {
            int cnta = calc(primes[i], l1, r1);
            int cntb = calc(primes[i], l2, r2);
            if (cnta > cntb)
            {
                valid = false;
                break;
            }
        }

        if (valid)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
