#include <fstream>
#include <set>
#include <algorithm>
using namespace std;

const int MAX_N = 2 * 10e5 + 1;
struct node_t
{
	int mem, par;
	bool operator<(const node_t temp)
	{
		return this -> mem < temp.mem;
	}
};
node_t node[MAX_N];
set<int> usedto, used;
long long n, sum = 0;

ifstream fin("spring.in");
ofstream fout("spring.out");

int main()
{
	fin >> n;

	for (int i = 0; i < n; i++)
		fin >> node[i].mem;
	for (int i = 1; i < n; i++)
    {
        fin >> node[i].par;
        node[i].par--;
    }

    node[0].par = -1;
    sort(node, node + n);

    for (int i = n - 1; i >= 0; i--)
    {
        if (node[i].mem == 0)
            continue;

        used.clear();
        sum += node[i].mem;
        used.insert(i);
        usedto.insert(node[i].par);

        for (int j = i - 1; j >= 0; j--)
        {
            if (usedto.count(j) == 0 && used.count(node[j].par) == 0)
            {
                node[j].mem = 0;
                used.insert(j);
                usedto.insert(node[j].par);
            }
        }
    }

    fout << sum;

    fin.clear();
    fout.clear();
    fin.close();
    fout.close();

    return 0;
}
