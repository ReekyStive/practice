#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    map<string, string> numbers;
    numbers["one"] = "01";
    numbers["two"] = "02";
    numbers["three"] = "03";
    numbers["four"] = "04";
    numbers["five"] = "05";
    numbers["six"] = "06";
    numbers["seven"] = "07";
    numbers["eight"] = "08";
    numbers["nine"] = "09";
    numbers["ten"] = "10";
    numbers["eleven"] = "11";
    numbers["twelve"] = "12";
    numbers["thirteen"] = "13";
    numbers["fourteen"] = "14";
    numbers["fifteen"] = "15";
    numbers["sixteen"] = "16";
    numbers["seventeen"] = "17";
    numbers["eighteen"] = "18";
    numbers["nineteen"] = "19";
    numbers["twenty"] = "20";

    queue<string> data;
    for (int i = 0; i < 6; i++)
    {
        string str;
        cin >> str;
        data.push(str);
    }
    
    return 0;
}
