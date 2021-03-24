#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct user
{
    string username;
    int score;
};

bool usercmp(user left, user right)
{
    if (left.score == right.score)
        return left.username.compare(right.username) < 0 ? 1 : 0;
    return left.score > right.score;
}

int main()
{
    int n, g, k;
    cin >> n >> g >> k;

    vector<user> users(n);
    for (int i = 0; i < n; i++)
        cin >> users[i].username >> users[i].score;

    sort(users.begin(), users.end(), usercmp);

    int count_1 = 0, count_2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (users[i].score >= g)
            count_2++;
        else if (users[i].score >= 60)
            count_1++;
    }

    int total = count_1 * 20 + count_2 * 50;
    cout << total << endl;

    int cur = 1;
    for (int i = 0; i < k; i++)
    {
        if (i >= 1)
        {
            if (users[i].score != users[i - 1].score)
                cur = i + 1;
        }
        cout << cur << " " << users[i].username << " " << users[i].score << endl;
    }
    for (int i = k; i >= 1 && i < n && users[i].score == users[i - 1].score; i++)
    {
        cout << cur << " " << users[i].username << " " << users[i].score << endl;
    }

    return 0;
}
