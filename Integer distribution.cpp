#define ll long long
#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;
const ll INF = 100000000000;//, MOD = 1000000007;
pair <ll, ll> dp[1 << 21];
bool vis[1 << 21];
int a[22], n;

pair <ll, ll> Solve(int mask)
{
    pair <ll, ll> &ans = dp[mask];
    pair <ll, ll> k;
    if (vis[mask]) return ans;
    vis[mask] = 1;
    if (!mask) return ans = make_pair(0, 0);
    ans = make_pair(INF, -INF);
    for (int i = 0; i < n; ++i) if(mask&(1 << i))
        for (int j = 0; j < n; ++j) if((mask&(1 << j)) && j != i)
        {
            k = Solve(mask^(1 << i)^(1 << j));
            ans.first = min(ans.first, k.first + (ll)(a[i]^a[j]));
            ans.second = max(ans.second, k.second + (ll)(a[i]^a[j]));
        }
    return ans;
}

int main()
{
    freopen("D:\\test.txt", "r", stdin);
    freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    pair <ll, ll> ans;
    ans = Solve((1 << n) - 1);
    printf("%lli %lli", ans.first, ans.second);
}
