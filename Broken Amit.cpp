#define ll long long
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

const long long INF = 10000000000;
ll dp[1 << 19], vis[1 << 19], val[18][20], L[18], D[18], n;

ll Solve(int mask, ll k)
{
    if (!(mask & (-mask)) || mask == 1) for (int i = 0; i < n; ++i) if (mask & (1 << i)) return dp[mask] = val[i][k];
    if (vis[mask]) return dp[mask];
    vis[mask] = 1;
    for (int i = 0; i < n; ++i) if (mask & (1 << i))
    {
        dp[mask] = max(dp[mask], val[i][k] + Solve(mask ^ (1 << i), k + 1));
    }
    return dp[mask];
}

int main(){
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%lli", &n);
    for (int i = 0; i < n; ++i) scanf("%lli", &L[i]);
    for (int i = 0; i < n; ++i) scanf("%lli", &D[i]);
    for (int i = 0; i < (1 << n); ++i)dp[i] = -INF;
    for (ll i = 0; i < n; ++i)
        for (ll j = 1; j <= n; ++j) {
                val[i][j] = L[i]*n - ((j - 1)*j)/2*D[i]*i - (j - 1)*D[i]*i*(n - j);
        }
    printf("%lli\n", Solve((1 << n) - 1, 1));
}
