#define ll long long
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
ll dp[1 << 22], vis[1 << 21], n;
vector<int> a[21];

ll Solve(int mask)
{
    if (mask == (1 << (n + 1)) - 2) return 1;
    if (vis[mask]) return dp[mask];
    vis[mask] = 1;
    for (int i = 1; i <= n; ++i) if(!(mask & (1 << i)))
    {
        bool flag = 1;
        for (int j : a[i]) if (!(mask & (1 << j))) flag = 0;
        if (flag) dp[mask] += Solve(mask | (1 << i));
    }
    return dp[mask];
}

int main(){
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 2; i <= 20; ++i)
        for (int j = i - 1; j >= 1; --j)
        if ((i&j) == j) a[i].push_back(j);
    printf("%lli", Solve(0));
}
