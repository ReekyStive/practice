#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_N = 2 * 10e5 + 1;
int la[MAX_N], ra[MAX_N], lb[MAX_N], rb[MAX_N];
pair<int, int> ma[MAX_N];

string ss;

bool comp(string ts, int al, int ar, int bl, int br)
{
	if (ar - al != br - bl)
		return false;
	bool res = true;
	for(int i = 0; i <= ar - al; i++)
	{
		if (ts[al + i] != ts[bl + i])
		{
			res = false;
			break;
		}
	}
	return res;
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("string.in");
    fout.open("string.out");
    
    int T, na, nb, m;
    bool bk;
    int x;
    
    for(fin >> T; T > 0; T--)
    {
        ss.clear();
        fin >> ss;

        fin >> na;
        for (int i = 0; i < na; i++)
            fin >> la[i] >> ra[i];

        fin >> nb;
        for (int i = 0; i < nb; i++)
            fin >> lb[i] >> rb[i];

        fin >> m;
        for (int i = 0; i < m; i++)
            fin >> ma[i].first >> ma[i].second;

        if (na == 1)
        {
            for (int i = 0; i < nb; i++)
            {
                bk = false;
				x = ma[i].second - 1;
                if (comp(ss, lb[x] - 1, rb[x] - 1, la[0] - 1, la[0] - 1 + rb[x] - lb[x]))
                {
                    fout << -1 << endl;
                    bk = true;
                    break;
                }
            }
            if (!bk)
                fout << ra[0] - la[0] + 1 << endl;
            else
                continue;
        }
        else
            fout << ra[0] - la[0] + 1 << endl;
    }

    fin.clear();
    fout.clear();
    fin.close();
    fout.close();
    
    return 0;
}
