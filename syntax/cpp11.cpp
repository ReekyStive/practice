#include <iostream>
#include <vector>
using namespace std;

template <typename type>
inline void my_swap(type &a, type &b)
{
    type temp = a;
    a = b;
    b = temp;
}

namespace days
{
    enum Day
    {
        today,
        yesterday
    };
}

int main()
{
    vector<int> dat;
    for (int i = 0; i < 4; i++)
    {
        dat.push_back(i);
    }

    for (auto &item : dat)
        cout << item << endl;

    int a = days::Day::today;
    int b = days::yesterday;
    my_swap(a, b);

    return 0;
}