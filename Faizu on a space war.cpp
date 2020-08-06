#define ll long long
#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;
const int INF = 10000000, MOD = 1000000007;
int n;
ll dp[1 << 14][14], H[14], val[124];

ll Solve(int mask, int u)
{
    ll &ans = dp[mask][u];
    if (ans != -1) return ans;
    if (!mask) return ans = 0;
    ans = -INF;
    for (int i = 1; i <= n; ++i) if (mask&(1 << i))
        ans = max(ans, Solve(mask^(1 << i), i) + ((u != 0)?(H[i]^H[u]):0));
    return ans;
}

int main()
{
    freopen("D:\\test.txt", "r", stdin);
    freopen("D:\\test2.txt", "w", stdout);
    string s; int k = 0, t; ll ans = 0;
    scanf("%d", &t); n = t;
    for (int i = 97; i <= 122; ++i) val[i] = ++k;
    k = 0;
    memset(dp, -1, sizeof(dp));
    while (t--)
    {
        cin >> s;
        ans = 0;
        for (int i = 0; i < s.length(); ++i) ans += val[s[i]];
        H[++k] = ans;
    }
    printf("%lli", Solve((1 << (n + 1)) - 2, 0));
}
