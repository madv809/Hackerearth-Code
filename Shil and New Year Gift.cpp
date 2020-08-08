#define ll long long
#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
const int INF = 1000000, MOD = 1000000007;
ll dp[1 << 17][17], a[17];
int n;

ll gcd(ll a, ll b)
{
    if (b == -INF) return 0;
    ll tmp;
    while (b)
    {
        tmp = a;
        a = b;
        b = tmp%b;
    }
    return a;
}

ll Solve(int mask, int u)
{
    ll &ans = dp[mask][u];
    if (ans != -1) return ans;
    if (!mask) return ans = 0;
    ans = -INF;
    for (int i = 1; i <= n; ++i) if (mask&(1 << i))
        ans = max(ans, Solve(mask^(1 <<i), i) + gcd(a[i], a[u]));
    return ans;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lli", &a[i]);
    a[16] = -INF;
    memset(dp, -1, sizeof(dp));
    printf("%lli", Solve((1 << (n + 1)) - 2, 16));
}
