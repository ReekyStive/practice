#include <iostream>

using namespace std;

char ans_a[100];
char ans_b[100];

int main()
{
    int n;
    cin >> n;
    cin.get();

    for (int i = 0; i < n; i++)
        cin >> ans_a[i], cin.get();
    for (int i = 0; i < n; i++)
        cin >> ans_b[i], cin.get();

    int ans_min = 0, ans_max = 0;
    for (int i = 0; i < n; i++)
        if (ans_a[i] == ans_b[i])
            ans_max += 2;
        else
            ans_max += 1;

    cout << ans_max << " " << ans_min << endl;

    return 0;
}