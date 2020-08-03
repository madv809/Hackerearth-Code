#define ll long long
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

const ll INF = 10000000000, MOD = 1000000007;
ll dp[100001][65];
int bit[21], w[20], n, m;
vector <int> a[100001];

ll Solve(int v, int par, int mask)
{
    if (dp[v][mask]) return dp[v][mask];
    ll &ans = dp[v][mask], tmp;
    for (int i = 1; i <= m; ++i)
    {
        tmp = 1;
        bool leaf = 1;
        for (int j : a[v]) if (j != par)
        {
            tmp = (tmp * Solve(j, v, (mask&bit[i]))) % MOD;
            leaf = 0;
        }
        if (leaf)
        {
            if ((mask&bit[i]) == 0) ++ans;
        }
        else ans = (ans + tmp) % MOD;
    }
    return ans;
}

int main(){
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    int x, y;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    w[2] = 0; w[3] = 1; w[5] = 2; w[7] = 3; w[11] = 4; w[13] = 5; w[17] = 6; w[19] = 7;
    for (int p:{ 2, 3, 5, 7, 11, 13, 17, 19 })
        for (int i = 1; i <= m; ++i) if (i%p == 0) bit[i] |= (1 << w[p]);
    printf("%lli", Solve(1, -1, (1 << 8) - 1));
}
