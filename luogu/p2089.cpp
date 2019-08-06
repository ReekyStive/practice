#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n > 30)
    {
        cout << 0 << endl;
        return 0;
    }

    int count = 0;

    for (int d1 = 1; d1 <= 3; d1++)
        for (int d2 = 1; d2 <= 3; d2++)
            for (int d3 = 1; d3 <= 3; d3++)
                for (int d4 = 1; d4 <= 3; d4++)
                    for (int d5 = 1; d5 <= 3; d5++)
                        for (int d6 = 1; d6 <= 3; d6++)
                            for (int d7 = 1; d7 <= 3; d7++)
                                for (int d8 = 1; d8 <= 3; d8++)
                                    for (int d9 = 1; d9 <= 3; d9++)
                                        for (int d10 = 1; d10 <= 3; d10++)
                                            if (d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8 + d9 + d10 == n)
                                                count++;
    
    cout << count << endl;

    for (int d1 = 1; d1 <= 3; d1++)
        for (int d2 = 1; d2 <= 3; d2++)
            for (int d3 = 1; d3 <= 3; d3++)
                for (int d4 = 1; d4 <= 3; d4++)
                    for (int d5 = 1; d5 <= 3; d5++)
                        for (int d6 = 1; d6 <= 3; d6++)
                            for (int d7 = 1; d7 <= 3; d7++)
                                for (int d8 = 1; d8 <= 3; d8++)
                                    for (int d9 = 1; d9 <= 3; d9++)
                                        for (int d10 = 1; d10 <= 3; d10++)
                                            if (d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8 + d9 + d10 == n)
                                                cout << d1 << " " << d2 << " " << d3 << " " << d4 << " " << d5 << " " << d6 << " " << d7 << " " << d8 << " " << d9 << " " << d10 << endl;

    return 0;
}
