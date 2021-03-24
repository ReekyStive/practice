#include <iostream>
#include <string>

using namespace std;

int max_single(string &data, int center)
{
    int count = 1;
    int spread = 1;
    int len = data.length();
    while (center - spread >= 0 && center + spread < len)
    {
        if (data[center - spread] == data[center + spread])
            count += 2;
        else
            break;
        spread++;
    }
    return count;
}

int max_double(string &data, int center1, int center2)
{
    if (data[center1] != data[center2])
        return 0;

    int count = 2;
    int spread = 1;
    int len = data.length();
    while (center1 - spread >= 0 && center2 + spread < len)
    {
        if (data[center1 - spread] == data[center2 + spread])
            count += 2;
        else
            break;
        spread++;
    }
    return count;
}

int main()
{
    string data;
    getline(cin, data);

    int len = data.length();
    int m1 = 0, m2 = 0;
    int temp;

    for (int i = 0; i < len; i++)
    {
        temp = max_single(data, i);
        if (temp > m1)
            m1 = temp;
    }

    for (int i = 0; i < len - 1; i++)
    {
        temp = max_double(data, i, i + 1);
        if (temp > m2)
            m2 = temp;
    }

    int res = m1 > m2 ? m1 : m2;
    cout << res << endl;

    return 0;
}
