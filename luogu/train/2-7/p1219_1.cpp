#include <iostream>

const int max_n = 13;
bool bl[max_n], bc[max_n];
bool bxl[max_n * 2 - 1], bxr[max_n * 2 - 1];
int ans[max_n];

int n;
int found = 0;

void change(int l, int c, bool tar)
{
    int xl = l + c + 1;
    int xr = n - 1 - c + l;
    bl[l] = tar;
    bc[c] = tar;
    bxl[xl] = tar;
    bxr[xr] = tar;
    return;
}

bool is_empty(int l, int c)
{
    int xl = l + c + 1;
    int xr = n - 1 - c + l;
    if (bl[l] || bc[c] || bxl[xl] || bxr[xr])
        return false;
    return true;
}

void dfs(int l)
{
    if (l >= n) {
        if (found < 3) {
            for (int i = 0; i < n; i++)
                std::cout << ans[i] << " ";
            std::cout << std::endl;
        }
        found++;
    }

    for (int i = 0; i < n; i++) {
        if (is_empty(l, i)) {
            change(l, i, true);
            ans[l] = i + 1;
            dfs(l + 1);
            change(l, i, false);
        }
    }
}

int main()
{
    std::cin >> n;

    dfs(0);
    std::cout << found << std::endl;

    return 0;
}
