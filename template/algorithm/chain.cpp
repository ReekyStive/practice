#include <iostream>

using namespace std;

struct node
{
    node * llink;
    int val;
    node * rlink;
};

int main()
{
    int cnt = 1, n, num;
    node * p = new node;
    p -> val = 0;
    node * temp = p;
    node * q;

    cin >> num >> n;

    for (int i = 1; i <= num; i++)
    {
        p -> rlink = new node;
        q = p;
        p = p -> rlink;
        p -> llink = q;
        p -> val = i;
        cnt++;
    }

    p -> rlink = temp;
    temp -> llink = p;
    p = p -> rlink;

    for (int i = 0; i < cnt * n; i++)
    {
        cout << p -> val << ' ';
        p = p -> rlink;
    }
    p = p -> llink;
    cout << endl << endl;
    for (int i = 0; i < cnt * n; i++)
    {
        cout << p -> val << ' ';
        p = p -> llink;
    }
    cout << endl;

    return 0;
}
