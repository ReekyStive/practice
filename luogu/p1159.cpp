#include <iostream>
#include <stack>
#include <windows.h>
using namespace std;

stack<int> s;

void calc(int c)
{
    int a, b, res;
    b = s.top();
    s.pop();
    a = s.top();
    s.pop();
    if (c == '+')
        res = a + b;
    if (c == '-')
        res = a - b;
    if (c == '*')
        res = a * b;
    if (c == '/')
        res = a / b;
    return s.push(res);
}

void readin()
{
    char temp;
    int res = 0;
    cin.get(temp);
    while (temp != '@')
    {
        if (temp >='0' && temp <= '9')
        {
            res *= 10;
            res += temp - '0';
        }
        else if (temp == '.')
        {
            s.push(res);
            res = 0;
        }
        else
            calc(temp);
        
        cin.get(temp);
    }
}

int main()
{
    readin();
    cout <<  s.top();
    system("pause");
    return 0;
}