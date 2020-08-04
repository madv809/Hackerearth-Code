#define ll long long
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int bit[100002], w[8], n;
ll dp[100002][5][17];

ll Solve(int uwu, int owo, int mask)
{
    ll &ans = dp[uwu][owo][mask];
    if (ans != -1) return ans;
    if (!mask) return 0;
    if (owo == 3)
    {
        if (mask) return 1;
        else return 0;
    }
    if (uwu == n + 1) return 0;
    ans = 0;
    ans += Solve(uwu + 1, owo, mask);
    ans += Solve(uwu + 1, owo + 1, mask&bit[uwu]);
    return ans;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    ll x, k;
    w[3] = 1; w[5] = 2; w[7] = 3;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lli", &x);
        while (x)
        {
            k = x%10;
            if (k == 2 || k == 3 || k == 5 || k == 7) bit[i] |= (1 << w[k]);
            x /= 10;
        }
    }
    printf("%lli", Solve(1, 0, (1 << 4) - 1));
}
