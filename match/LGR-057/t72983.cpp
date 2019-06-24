#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long T, N, L, R, X, K;
    long long speed, cur = 1, ans = 0, last = -1;
    int x, y;
    bool err = false;

    cin >> T >> N >> L >> R >> X >> K;
    speed = L;

    for (int i = 0; i < T; i++)
    {
        cin >> x >> y;

        if (x == 0)
            cur++, speed = L;
        if (x == 1)
            cur--, speed = R;
        if (cur < 1 || cur > N)
        {
            err = true;
            break;
        }
        
        if (y == 1)
            speed += X, speed = min(speed, R);

        ans += speed * cur;

        if (speed != R)
            last = -1;
        else if (last == -1)
            last = i;
        
        if (last != -1 && i - last + 1 == K)
            break;
    }

    if (err)
        ans = -1;
    cout << ans;

    return 0;
}