#define ll long long
#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>

using namespace std;
ll dp[9*9*14][1025][14][2], a[14], l, r;
int t, d;

ll Solve (int sum, int mask, int n, bool r, bool s)
{
    if (n == -1)
    {
        int k = (int)sqrt(sum);
        if ((k*k == sum) && r) return 1;
        return 0;
    }
    ll &ans = dp[sum][mask][n][r];
    if ((ans != -1) && !s) return ans;
    ll tmp = 0;
    int k = ((s)?(a[n]):9);
    for (int i = 0; i <= k; ++i)
    {
        if (!mask)
        {
            if (i == 0) tmp += Solve(sum, mask, n - 1, 0, s&(i == k));
            else tmp += Solve(sum + i*i, mask|(1 << i), n - 1, 0, s&(i == k));
        }
        else
        {
            if (mask&(1 << i)) tmp += Solve(sum + i*i, mask, n - 1, 1, s&(i == k));
            else tmp += Solve(sum + i*i, mask|(1 << i), n - 1, r, s&(i == k));
        }
    }
    if (!s) ans = tmp;
    return tmp;
}

ll Solve (ll n)
{
    d = -1;
    while (n)
    {
        a[++d] = n%10;
        n /= 10;
    }
    return Solve(0, 0, d, 0, 1);
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &t);
    memset(dp, -1, sizeof(dp));
    while (t--)
    {
        scanf("%lli%lli", &l, &r);
        printf("%lli\n", Solve(r) - Solve(l - 1));
    }
}
