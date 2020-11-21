#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

long long pow_2(int n)
{
    long long res = 1;
    res = res << n;
    return res;
}

long long translate(string s)
{
    if (s == "B")
        return pow_2(0);
    if (s == "KB")
        return pow_2(10);
    if (s == "MB")
        return pow_2(20);
    if (s == "GB")
        return pow_2(30);
}

int main()
{
    double left, right;
    string raw, left_s, right_s;

    cin >> left;
    getline(cin, raw);
    left_s = raw.substr(0, raw.find('='));
    right_s = raw.substr(raw.find('=') + 2);

    right = left;
    if (translate(right_s) < translate(left_s))
        right *= (double)(translate(left_s) / translate(right_s));
    if (translate(right_s) > translate(left_s))
        right /= (double)(translate(right_s) / translate(left_s));

    cout << fixed << setprecision(6) << right << endl;

    return 0;
}