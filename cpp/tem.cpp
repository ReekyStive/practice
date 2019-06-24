#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    cout << sizeof(int) << endl;
    cout << __INT_MAX__ << endl;
    cout << (int)(1<<30) << endl;
    system("pause");

    return 0;
}
