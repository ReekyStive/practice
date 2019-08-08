#include <iostream>
#include <string>

using namespace std;

int main()
{
    string in_str;
    cin >> in_str;

    int index_equal;
    char var_letter;

    for (int i = 0; i < in_str.length(); i++)
        if (in_str[i] >= 'a' && in_str[i] <= 'z')
        {
            var_letter = in_str[i];
            break;
        }

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

    string one = "1";
    for (int i = 0; i < in_str.length(); i++)
    {
        if (in_str[i] >= 'a' && in_str[i] <= 'z')
        {
            if (i == 0)
                in_str.insert(0, one);
            else if (in_str[i - 1] == '-' || in_str[i - 1] == '+')
                in_str.insert(i, one);
        }
    }

    // ax + b = 0
    int a = 0, b = 0;

    int sign = 1, pos_a = 0, pos_b = 0, tmp_val;
    bool is_var;

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
            is_var = true;
        

        for (int j = pos_a; j < pos_b - is_var; j++)
        {
            tmp_val *= 10;
            tmp_val += (in_str[j] - '0');
        }

        if (is_var)
            a += sign * tmp_val;
        else
            b += sign * tmp_val;

        if (in_str[pos_b] == '-')
            sign = -1;
        else
            sign = 1;
    }

    cout.flags(ios::fixed);
    cout.precision(3);

    double result = (double)(-b) / (double)a;

    if (result <= 0 && result > -0.001)
        cout << var_letter << "=0.000" << endl;
    else
        cout << var_letter << "=" << result << endl;

    return 0;
}
