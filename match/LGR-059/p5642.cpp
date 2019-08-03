#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 10e5;
int balls[MAX_N];

int n;

int next_pos(int pos)
{
    int next = -1;
    for (int i = pos + 1; i < n; i++)
        if (balls[i] >= 0)
        {
            next = i;
            break;
        }
    
    return next;
}

int max_pos()
{
    int max = next_pos(-1);
    if (max == -1)
        return max;

    for (int i = max + 1; i < n - 1; i++)
    {
        if (balls[i] > balls[max] && next_pos(i) >= 0)
            max = i;
        
        if (balls[i] == max && next_pos(i) >= 0)
            if (balls[next_pos(i)] > balls[next_pos(max)])
                max = i;
    }

    return max;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> balls[i];
    
    while (next_pos(-1) >= 0)
    {
        int max_index = max_pos();
        int next = next_pos(max_index);
        cout << balls[max_index] << " " << balls[next] << " ";
        balls[max_index] = -1;
        balls[next] = -1;
    }
    
    return 0;
}
