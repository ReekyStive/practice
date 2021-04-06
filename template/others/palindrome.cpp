#include <iostream>
using namespace std;

bool palindrome(char const *s)
{
    char const *left = s, *right = s;
    while (*(right + 1) != '\0')
        right++;

    while (left < right)
    {
        if (*left != *right)
            return false;
        left++, right--;
    }
    return true;
}

int main()
{
    cout << palindrome("qwq") << endl;
    return 0;
}
