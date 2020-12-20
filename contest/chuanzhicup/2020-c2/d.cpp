#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> files;

void ls()
{
    for (int i = 0; i < files.size(); i++)
    {
        cout << files[i] << endl;
    }
}

void touch(string &name)
{
    for (int i = 0; i < files.size(); i++)
    {
        if (files[i] == name)
            return;
    }

    files.push_back(name);
}

void rename(string &old_name, string &new_name)
{
    for (int i = 0; i < files.size(); i++)
    {
        if (files[i] == new_name)
            return;
    }

    for (int i = 0; i < files.size(); i++)
    {
        if (files[i] == old_name)
        {
            files[i] = new_name;
            return;
        }
    }

    return;
}

void rm(string &name)
{
    for (int i = 0; i < files.size(); i++)
    {
        if (files[i] == name)
        {
            files.erase(files.begin() + i);
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cin.get();

    string cmd;
    for (int t = 0; t < n; t++)
    {
        string op, para1, para2;
        op.clear();
        para1.clear();
        para2.clear();

        cin >> op;

        if (op == "touch")
        {
            cin >> para1;
            touch(para1);
        }
        else if (op == "rename")
        {
            cin >> para1 >> para2;
            rename(para1, para2);
        }
        else if (op == "rm")
        {
            cin >> para1;
            rm(para1);
        }
        else
        {
            ls();
        }
    }

    return 0;
}