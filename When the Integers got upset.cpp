#define ll long long
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int INF = 10000000, MOD = 1000000007;
int dp[1 << 14][14][14], c[1 << 14], a[14], p[14], t, n;

int countBit(ll mask)
{
    if (c[mask] != -1) return c[mask];
    int ans = 0;
    while(mask)
    {
        if (mask&1) ++ans;
        mask >>= 1;
    }
    return c[mask] = ans - 1;
}

int Solve(int mask, int x3, int x2)
{
    int &ans = dp[mask][x3][x2];
    if (ans != -1) return ans;
    if (!mask) return ans = 0;
    ans = INF;
    for (int i = 1; i <= n; ++i) if (mask&(1 << i))
        ans = min(ans, Solve(mask^(1 << i), x2, i) + ((x3 != 14)?(a[x3]^a[x2]^a[i]):0)*p[n - countBit(mask)]);
    return ans;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &t);
    memset(c, -1, sizeof(c));
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", Solve((1 << (n + 1)) - 2, 14, 14));
    }
}
