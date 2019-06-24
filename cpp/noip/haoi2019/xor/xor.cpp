#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 5 * 10e5 + 1;
int a[MAX_N];
int templ = -1, tempr = -1;
long long tempres;
int n, k;

long long xr(int l, int r)
{
    long long res;
    if (l == templ && r - 1 == tempr)
    {
        res = tempres;
        res ^= a[r];
    }
    else
    {
        res = a[l];
        while (r > l)
        {
            res ^= a[r];
            r--;
        }
    }
    
    templ = l;
    tempr = r;
    tempres = res;

    return res;
}

int main()
{
    long long sum = 0;
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    priority_queue<long long> tempq;
    
    ifstream fin;
    ofstream fout;
    fin.open("xor.in");
    fout.open("xor.out");
    
    fin >> n >> k;
    for  (int i = 0; i < n; i++)
        fin >> a[i];

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            pq.push(xr(i, j));
            if (pq.size() > k)
                pq.pop();
        }
    
    while (!pq.empty())
    {
        tempq.push(pq.top());
        pq.pop();
    }

    for (int i = 0; i < k; i++)
    {
        sum += tempq.top();
        tempq.pop();

        if (tempq.empty())
            break;
    }

    fout << sum;
    
    fin.clear();
    fout.clear();
    fin.close();
    fout.close();
    
    return 0;
}
