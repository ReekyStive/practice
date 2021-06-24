#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int id;
    int value;
    int impo;
    int father_id;
};

const int max_m = 60;
const int max_n = 32000;

Item items[max_m];
bool bought[max_m];

bool cmp(Item a, Item b)
{
    if (a.father_id >= 0 && b.father_id == -1)
        return true;
    return false;
}

void input(int m)
{
    for (int i = 0; i < m; i++) {
        Item& it = items[i];
        cin >> it.value >> it.impo >> it.father_id;
        it.father_id--;
        it.id = i;
    }

    sort(items, items + m, cmp);
}

int dp(int cur, int remain)
{
    Item& it = items[cur];

    if (cur < 0 || remain <= 0)
        return 0;
    if (remain < it.value) {
        bought[cur] = false;
        return dp(cur - 1, remain);
    }

    int res = 0;

    if (items[cur].father_id == -1) {
        bought[cur] = true;
        int res_1 = dp(cur - 1, remain - it.value) + it.impo * it.value;
        bought[cur] = false;
        int res_2 = dp(cur - 1, remain);
        res = max(res_1, res_2);
    } else {
        if (bought[it.father_id]) {
            int res_1 = dp(cur - 1, remain - it.value) + it.impo * it.value;
            int res_2 = dp(cur - 1, remain);
            res = max(res_1, res_2);
        } else
            res = dp(cur - 1, remain);
    }

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;

    input(m);

    cout << dp(m - 1, n) << endl;

    return 0;
}
