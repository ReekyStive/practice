#include <fstream>

using namespace std;

ofstream fout("file_io.in");

int main()
{
    for (int i = 0; i < 1000000; i++)
    {
        fout << i << endl;
    }

    return 0;
}