#include <iostream>

const int kMaxN = 200000;
int t[kMaxN];
int curs[kMaxN];

int solve(int n)
{
    for (int i = 0; i < n; i++)
        curs[i] = i;

    bool end = false;
    int time = 0;

    while (true) {
        for (int i = 0; i < n; i++) {
            curs[i] = t[curs[i]];
            if (curs[i] == i) {
                end = true;
                break;
            }
        }
        time++;
        if (end)
            break;
    }
    return time;
}

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
        t[i]--;
    }

    std::cout << solve(n) << std::endl;

    return 0;
}
