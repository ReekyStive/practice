#include <iostream>
#include <queue>

using namespace std;

struct Pos
{
    int x, y, count;
    bool operator<(const Pos &point) const
    {
        return this -> count < point.count;
    }
    Pos(int a = 0, int b = 0, int c = 0)
    {
        this -> x = a;
        this -> y = b;
        this -> count = c;
    }
};

int main()
{
    int M, N, K;
    cin >> M >> N >> K;

    Pos point;
    priority_queue<Pos> peanuts;
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> point.count;
            if (point.count > 0)
            {
                point.y = i;
                point.x = j;
                peanuts.push(point);
            }
        }
    }

    if (peanuts.size() == 0 || K == 0)
        cout << "0" << endl;
    else
    {
        int count = 0;
        int remain = K;
        Pos cur(peanuts.top().x);
        while (!peanuts.empty())
        {
            Pos new_point;
            new_point = peanuts.top();
            peanuts.pop();

            int distance = abs(new_point.x - cur.x) + abs(new_point.y - cur.y);
            if (remain - distance - 1 < new_point.y)
                break;
            
            cur = new_point;
            count += new_point.count;
            remain -= (distance + 1);
        }
        cout << count << endl;
    }
    
    return 0;
}
