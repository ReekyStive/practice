#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

const int max_n = 1000;

struct Person {
    int num;
    int t;
};

bool cmp(Person a, Person b)
{
    return a.t < b.t;
}

Person persons[max_n];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        persons[i].num = i + 1;
        cin >> persons[i].t;
    }

    sort(persons, persons + n, cmp);

    long long res = 0;

    for (int i = 0; i < n; i++)
        res += persons[i].t * (n - i - 1);

    for (int i = 0; i < n; i++)
        cout << persons[i].num << " ";
    cout << endl;

    cout << setiosflags(ios::fixed);
    cout << setprecision(2);

    cout << (double)res / n << endl;

    return 0;
}
