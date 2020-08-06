#define ll long long
#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;
const ll INF = 1000000000, MOD = 1000000007;
int n;
ll dp[1 << 22];
struct coor
{
    ll x, y;
} a[22], l[22];

ll Solve(int mask, int k)
{
    ll &ans = dp[mask];
    if (ans != - 1) return ans;
    if (!mask) return ans = 0;
    ans = INF;
    for (int i = 1; i <= n; ++i) if (mask&(1 << i))
        ans = min(ans, Solve(mask^(1 << i), k + 1) + abs(a[i].x - l[k].x) + abs(a[i].y - l[k].y));
    return ans;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lli%lli", &a[i].x, &a[i].y);
    for (int i = 1; i <= n; ++i) scanf("%lli%lli", &l[i].x, &l[i].y);
    memset(dp, -1, sizeof(dp));
    printf("%lli", Solve((1 << (n + 1)) - 2, 1));
}
