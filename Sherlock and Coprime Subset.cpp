#define ll long long
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const ll INF = 10000000000, MOD = 1000000007;
int bit[51], dp[51][(1 << 15) + 1], a[51], w[48], t, n;

int Solve()
{
    int ans = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j <= (1 << 15) - 1; ++j)
        {
            if (((bit[i]&j) == bit[i]) || bit[i] == 0)
            {
                int k = dp[i - 1][(j^bit[i])];
                dp[i][j] = max(max(dp[i][j], dp[i - 1][j]),k + ((k == 0)?0:1));
            }
            else dp[i][j] = dp[i - 1][j];
            ans = max(ans, dp[i][j]);
            if (dp[i][j] > n) { cout << i << ' ' << j; return -1; }
        }
    }
    return ans;
}

int main(){
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &t);
    int k = -1;
    for (int i : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 }) w[i] = ++k;
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        memset(bit, 0, sizeof(bit));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            for (int j : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 })
                if(a[i] % j == 0) bit[i] |= (1 << w[j]);
            dp[i][bit[i]] = 1;
        }
        printf("%d\n", Solve());
    }
}
