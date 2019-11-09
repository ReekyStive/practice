#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        bool skip = false;

        int N, M;
        cin >> N >> M;

        vector<string> input(N + 1);
        vector<string> output(N + 1);
        set<int> used;
        vector<int> m_arr(M + 1);

        for (int i = 0; i < N; i++)
            cin >> input[i] >> output[i];
        
        for (int i = 1; i <= M; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (used.count(j))
                    continue;

                m_arr[i] = j;

                for (int k = 1; k <= N; k++)
                {
                    if (input[k][i] != output[k][j])
                    {
                        skip = true;
                        break;
                    }
                }
                
                used.erase(used.find(j));
            }
        }
    }

    return 0;
}
