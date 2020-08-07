#define ll long long
#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
const int INF = 1000000, MOD = 1000000007;
int dp[1 << 22][2], mask, N, n, m, q;

bool lose(int mask)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < m - 1; ++j) if (mask&(1 << (i*m + j)))
        {
            if (mask&(1 << ((i + 1)*m + j))) return 0;
            if (mask&(1 << (i*m + j + 1))) return 0;
        }
    for (int i = 0; i < n - 1; ++i) if (mask&(1 << (i*m + m - 1)) && mask&(1 << ((i + 1)*m + m - 1))) return 0;
    for (int i = 0; i < m - 1; ++i) if (mask&(1 << ((n - 1)*m + i)) && mask&(1 << ((n - 1)*m +i + 1))) return 0;
    return 1;
}

bool canGo(int mask, int i)
{
    int x = i/m, y = i%m;
    if (x + 1 <= n - 1 && mask&(1 << ((x + 1)*m + y))) return 1;
    if (x - 1 >= 0 && mask&(1 << ((x - 1)*m + y))) return 1;
    if (y + 1 <= m - 1 && mask&(1 << (x*m + y + 1))) return 1;
    if (y - 1 >= 0 && mask&(1 << (x*m + y - 1))) return 1;
    return 0;
}

int Solve(int mask, int u)
{
    int &ans = dp[mask][u];
    if (ans) return ans;
    if (lose(~mask))
    {
        if (u) return ans = 1;
        return ans = 2;
    }
    ans = (1^u) + 1;
    for (int i = 0; i < N; ++i) if ((!(mask&(1 << i)))&&canGo(~mask, i))
    {
        if (u) ans = max(ans, Solve(mask|(1 << i), 1^u));
        else ans = min(ans, Solve(mask|(1 << i), 1^u));
    }
    return ans;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &q); N = n*m;
    while (q--)
    {
        char s[100];
        mask = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", &s);
            for (int j = 0; j < m; ++j)
                mask = ((mask << 1)|(s[j] == '1'));
        }
        printf("%d\n", (Solve(mask, 0) - 1));
    }
}
