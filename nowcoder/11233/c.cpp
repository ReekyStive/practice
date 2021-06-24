#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>

using namespace std;

const int max_n = 1e5 + 1;
int rat[max_n];

int main()
{
    int n, m;
    cin >> n >> m;

    double sum = 0.0;
    priority_queue<double, vector<double>, greater<double>> pq;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        pq.push((double)temp);
        sum += (double)temp;
    }

    for (int i = 0; i < m; i++)
    {
        int perf;
        cin >> perf;

        double mmin = pq.top();
        pq.pop();
        sum -= mmin;

        double cur = ((double)perf + mmin) / 2.0;
        pq.push(cur);
        sum += cur;
        cout << fixed << setprecision(2);
        cout << sum << endl;
    }

    return 0;
}
