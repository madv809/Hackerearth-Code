#define ll long long
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const ll INF = 10000000000, MOD = 1000000007;
int a[100001], n, k;
ll dp[100001][101];

ll Solve()
{
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= k; ++j)
            dp[i][j] = dp[i - 1][j - 1]*a[i] + dp[i - 1][j];
    }
    return dp[n][k];
}

int main()
{
    freopen("D:\\test.txt", "r", stdin);
    freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    int x;
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", &x);
        ++a[x];
    }
    a[0] = 1; dp[0][1] = dp[0][0] = 1;
    printf("%lli", Solve());
}
