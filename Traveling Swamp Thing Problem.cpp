#define ll long long
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

const ll INF = 10000000000, MOD = 1000000007;
vector <int> a[15];
int n, m;
ll cost[15][15], dis[15][15], E;
ll dp[15][1 << 15][101];

ll Solve(int u, int mask, ll e)
{
    if(dp[u][mask][e]) return dp[u][mask][e];
    if (e < 0) return INF;
    if (mask == 0) return 0;
    dp[u][mask][e] = INF;
    for (int i : a[u]) if (mask&(1 << i))
        dp[u][mask][e] = min(dp[u][mask][e], Solve(i, mask ^ (1 << i), e - cost[u][i]) + dis[u][i]);
    return dp[u][mask][e];
}

int main(){
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d%lli", &n, &m, &E);
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        ll uwu, owo;
        scanf("%d%d", &x, &y);
        scanf("%lli%lli", &uwu, &owo);
        dis[x][y] = uwu; dis[y][x] = uwu;
        cost[x][y] = owo; cost[y][x] = owo;
        a[x].push_back(y);
        a[y].push_back(x);
    }
	ll k = Solve(1, (1 << (n + 1)) - 4, E);
	if(k != INF) printf("%lli", k);
	else printf("-1");
}
