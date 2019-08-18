#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int sum(int n)
{
    int result = 0;
    while (n > 0)
    {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int V, sum_V, counter = 0;
        ostringstream out_str;

        cin >> V;
        sum_V = sum(V);

        for (int i = 1; i <= V; i++)
        {
            if (i > sum_V)
                break;
            
            if (V % i == 0 && sum_V % i == 0)
            {
                if (counter > 0)
                    out_str << " ";
                
                counter++;
                out_str << i;
            }
        }

        cout << counter << endl;
        cout << out_str.str() << endl;
    }

    return 0;
}
