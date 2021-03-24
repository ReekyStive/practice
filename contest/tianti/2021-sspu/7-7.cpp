#include <iostream>
#include <string>
#include <vector>

using namespace std;

double absdouble(double a)
{
    if (a < 0.0)
        return -a;
    else
        return a;
}

int main()
{
    vector<int> number(10000);
    vector<string> name(10000);

    int count;
    cin >> count;
    long long sum = 0;
    for (int i = 0; i < count; i++)
    {
        cin >> name[i] >> number[i];
        sum += (long long)number[i];
    }

    double halfave = (double)sum / (double)(count * 2);
    int winner_index = 0;
    double min_difference = abs((double)number[0] - halfave);

    for (int i = 1; i < count; i++)
    {
        if (abs((double)number[i] - halfave) < min_difference)
        {
            min_difference = abs((double)number[i] - halfave);
            winner_index = i;
        }
    }

    int intpart = (int)halfave;
    cout << intpart << " " << name[winner_index] << endl;

    return 0;
}
