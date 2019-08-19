#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

struct Line
{
    enum Type
    {
        First,
        End
    };

    Type type;
    char var;

    struct Val
    {
        bool is_n;
        int value;
    };

    Val a, b;

    int level = -1;
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        // Analyse given level
        int L, level;
        string given;
        cin >> L >> given;
        getchar();

        if (given[2] == '1')
            level = 0;
        else
        {
            stringstream ss_given(given.substr(4, given.length() - 5));
            ss_given >> level;
        }

        // Analyse singal line data
        string line_str;
        vector<Line> prog;
        Line line_obj;
        int max_level = 0;
        bool err= false;
        set<char> used;
        int i;
        for (i = 0; i < L; i++)
        {
            line_obj.a.is_n = false;
            line_obj.b.is_n = false;

            getline(cin, line_str);
            if (line_str[0] == 'E')
                line_obj.type = Line::End;
            else
            {
                line_obj.type = Line::First;
                stringstream ss_line(line_str.substr(2, line_str.length() - 2));
                ss_line >> line_obj.var;

                // Analyse value
                for (int j = 0; j < 2; j++)
                {
                    string temp_str;
                    ss_line >> temp_str;
                    if (temp_str[0] == 'n')
                    {
                        if (j == 0)
                            line_obj.a.is_n = true;
                        else
                            line_obj.b.is_n = true;
                    }
                    else
                    {
                        stringstream temp_ss(temp_str);
                        if (j == 0)
                            temp_ss >> line_obj.a.value;
                        else
                            temp_ss >> line_obj.b.value;
                    }
                }
            }

            // Calculate singal line level
            if (line_obj.type == Line::First)
            {
                if (line_obj.a.is_n)
                {
                    if (!line_obj.b.is_n)
                        line_obj.level = -1;
                    else
                        line_obj.level = 0;
                }
                else
                {
                    if (!line_obj.b.is_n)
                    {
                        if (line_obj.b.value < line_obj.a.value)
                            line_obj.level = -1;
                        else
                            line_obj.level = 0;
                    }
                    else
                        line_obj.level = 1;
                }
            }
            
            if (line_obj.type == Line::First)
            {
                prog.push_back(line_obj);

                // Detect repeat error
                if (used.count(line_obj.var) > 0)
                {
                    err = true;
                    break;
                }
                else
                    used.insert(line_obj.var);
            }
            else
            {
                // Detect 'E' more than 'F' error
                if (prog.size() == 0)
                {
                    err = true;
                    break;
                }

                used.erase(prog[prog.size() - 1].var);
                prog.erase(prog.end() - 1);
            }

            // calculate max level
            int temp_sum = 0;
            for (int j = 0; j < prog.size(); j++)
            {
                if (prog[j].level == -1)
                    break;
                
                temp_sum += prog[j].level;
            }
            
            max_level = max(max_level, temp_sum);

            // Detect 'F' more than 'E' error
            if (i == L - 1 && prog.size() > 0)
                err = true;
        }

        // Read remain data
        if (i < L)
        {
            i = L - i - 1;
            string ignore_str;
            while (i--)
                getline(cin, ignore_str);
        }
        
        // Output
        if (err)
            cout << "ERR" << endl;
        else
        {
            if (max_level == level)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}
