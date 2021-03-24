#include <iostream>

using namespace std;

int maxint(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int p[4];
    int low, threshold, pmax;
    for (int i = 0; i < 4; i++)
        cin >> p[i];
    cin >> low >> threshold;

    pmax = maxint(maxint(p[0], p[1]), maxint(p[2], p[3]));
    int abnormal_count = 0;
    int abnormal_index;

    for (int i = 0; i < 4; i++)
    {
        if (pmax - p[i] > threshold || p[i] < low)
        {
            abnormal_count++;
            abnormal_index = i + 1;
        }
    }

    if (abnormal_count == 0)
        cout << "Normal" << endl;
    else if (abnormal_count == 1)
    {
        cout << "Warning: please check #";
        cout << abnormal_index << "!" << endl;
    }
    else
        cout << "Warning: please check all the tires!" << endl;

    return 0;
}
