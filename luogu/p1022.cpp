#include <iostream>
#include <string>

using namespace std;

int main()
{
    string in_str;
    cin >> in_str;

    int index_equal;
    for (int i = 0; i < in_str.length(); i++)
    {
        if (in_str[i] == '=')
        {
            index_equal = i;
            break;
        }
    }

    if (in_str[index_equal + 1] != '-')
        in_str[index_equal] = '+';
    else
        in_str.erase(index_equal, 1);
    
    for (int i = index_equal; i < in_str.length(); i++)
    {
        if (in_str[i] == '-')
            in_str[i] = '+';
        else if (in_str[i] == '+')
            in_str[i] = '-';
    }

    // ax + b = 0
    int a = 0, b = 0;

    int sign = 1, pos_a = 0, pos_b = 0, tmp_val;
    bool is_var;
    char var_letter;
    if (in_str[0] == '-')
    {
        sign = -1;
        pos_a = 1;
    }

    for (int i = pos_a; i < in_str.length(); i++)
    {
        is_var = false;
        tmp_val = 0;
        pos_a = i;

        for (pos_b = i; pos_b < in_str.length(); pos_b++)
            if (in_str[pos_b] == '+' || in_str[pos_b] == '-')
                break;

        i = pos_b;
        
        if (in_str[pos_b - 1] >= 'a' && in_str[pos_b - 1] <= 'z')
        {
            var_letter = in_str[pos_b - 1];
            pos_b--;
            is_var = true;
        }
        
        for (int j = pos_b; j >= pos_a; j--)
        {
            tmp_val *= 10;
            tmp_val += (in_str[j] - '0');
        }

        if (is_var)
            a += tmp_val;
        else
            b += tmp_val;
    }

    cout.flags(ios::fixed);
    cout.precision(3);
    cout << var_letter << "=" << (double)(-b) / (double)a << endl;

    return 0;
}
