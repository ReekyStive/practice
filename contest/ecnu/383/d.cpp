#include <iostream>
#include <map>

using namespace std;

bool prime[10000001];
int primes[350000];
int prime_count = 0;

void gen_prime(int upper)
{
    prime[0] = false, prime[1] = false;
    for (int i = 2; i <= upper; i++)
        prime[i] = true;

    for (int i = 2; i <= upper / 2; i++)
    {
        if (!prime[i])
        {
            continue;
        }
        primes[prime_count++] = i;
        for (long long j = i; j * i <= upper; j++)
            prime[j * i] = false;
    }
}

void devide(map<int, int> &m, int n)
{
    for (int i = 0; i < prime_count; i++)
    {
        if (n == 0)
            return;

        int cur = primes[i];
        if (n % cur != 0)
            continue;

        if (m.count(cur) == 0)
            m[cur] = 0;
        while (cur * (int)(n / cur) == n)
        {
            if (n == 0)
                return;
            n /= cur;
            m[cur]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    gen_prime(10000000);

    int t;
    cin >> t;
    map<int, int> ma, mb;
    while (t--)
    {
        ma.clear(), mb.clear();
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if (l1 >= l2 && r1 <= r2)
        {
            cout << "Yes" << endl;
            continue;
        }

        int l3 = l1 > l2 ? l1 : l2;
        int r3 = r1 < r2 ? r1 : r2;

        for (int i = l1; i <= r1; i++)
        {
            if (!(i >= l3 && i <= r3))
                devide(ma, i);
        }

        for (int i = l2; i <= r2; i++)
        {
            if (!(i >= l3 && i <= r3))
                devide(mb, i);
        }

        bool valid = true;
        for (auto ita = ma.begin(); ita != ma.end(); ita++)
        {
            auto itb = mb.find(ita->first);

            if (itb == mb.end())
            {
                valid = false;
                break;
            }
            if (itb->second < ita->second)
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