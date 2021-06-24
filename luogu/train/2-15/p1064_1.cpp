#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Sub {
    int value;
    int importance;
    Sub(int a, int b)
    {
        value = a;
        importance = b;
    }
};

struct Item {
    bool exist = false;
    int value;
    int importance;
    vector<Sub> subs;
};

const int kMaxM = 60;
const int kMaxN = 32000;

Item items[kMaxM];
bool bought[kMaxM];
vector<pair<int, int>> alls[kMaxM];

int read(int m)
{
    int main_item_count = 0;
    int _v, _p, _q;
    for (int i = 0; i < m; i++) {
        cin >> _v >> _p >> _q;
        if (_q != 0)
            items[_q - 1].subs.push_back(Sub(_v, _p));
        else {
            items[i].exist = true;
            items[i].value = _v;
            items[i].importance = _p;
            main_item_count++;
        }
    }
    return main_item_count;
}

void PreCalc(int m)
{
    int cur = 0;
    for (int i = 0; i < m; i++) {
        if (items[i].exist) {
            Item& it = items[i];
            if (it.subs.size() == 0) {
                alls[cur].push_back(pair<int, int>(it.value, it.value * it.importance));
            }
            if (items[i].subs.size() == 1) {
                alls[cur].push_back(pair<int, int>(it.value, it.value * it.importance));

                alls[cur].push_back(pair<int, int>(it.value + it.subs[0].value,
                    it.value * it.importance
                        + it.subs[0].value * it.subs[0].importance));
            }
            if (items[i].subs.size() == 2) {
                alls[cur].push_back(pair<int, int>(it.value, it.value * it.importance));

                alls[cur].push_back(pair<int, int>(it.value + it.subs[0].value,
                    it.value * it.importance
                        + it.subs[0].value * it.subs[0].importance));

                alls[cur].push_back(pair<int, int>(it.value + it.subs[1].value,
                    it.value * it.importance
                        + it.subs[1].value * it.subs[1].importance));

                alls[cur].push_back(pair<int, int>(it.value
                        + it.subs[0].value + it.subs[1].value,
                    it.value * it.importance
                        + it.subs[0].value * it.subs[0].importance
                        + it.subs[1].value * it.subs[1].importance));
            }
            cur++;
        }
    }
}

int dp(int cur, int remain)
{
    if (cur < 0)
        return 0;

    int res = 0;
    vector<pair<int, int>>& it = alls[cur];

    res = dp(cur - 1, remain);
    for (unsigned int i = 0; i < it.size(); i++) {
        if (remain < it[i].first)
            continue;

        res = max(res, it[i].second + dp(cur - 1, remain - it[i].first));
    }

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int count;
    count = read(m);
    PreCalc(m);

    cout << dp(count - 1, n) << endl;

    return 0;
}
