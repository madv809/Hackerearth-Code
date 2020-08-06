#define ll long long
#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;
const ll INF = 100000000000;//, MOD = 1000000007;
int S[10004], n, mxMask;
ll dp[10004][1 << 10], C[10004];

ll Solve(int mask, int k)
{
    ll &ans = dp[k][mask];
    if (ans != -1) return ans;
    if (k == n + 1)
    {
        if (!mask) return ans = 0;
        else return ans = INF;
    }
    if (!mask) return ans = 0;
    ans = min(Solve(mask, k + 1), Solve(mask&(~S[k]), k + 1) + C[k]);
    return ans;
}

int countBit(int mask)
{
    int ans = 0;
    while (mask)
    {
        if (mask&1) ++ans;
        mask >>= 1;
    }
    return ans;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    string s;
    int ans = 0, i, j;
    memset(dp, -1, sizeof(dp));
    for (i = 1; i <= n; ++i)
    {
        scanf("%lli", &C[i]);
        cin >> s;
        ans = 0;
        for (j = 0; j < s.length(); ++j)
        {
            ans <<= 1;
            if (s[j] == '1') ans += 1;
        }
        S[i] = ans;
        mxMask |= ans;
    }
    printf("%lli", Solve(mxMask, 1));
}
