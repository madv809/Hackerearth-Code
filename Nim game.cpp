#define ll long long
#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
const ll INF = 100000000000, MOD = 1000000007;
ll dp[69][2][2][2][2][2], target, n;
int t;
vector <int> a, b;

void fac(vector <int> &a, ll n)
{
    while (n)
    {
        a.push_back((n&1));
        n >>= 1;
    }
}

void preCom()
{
    a.clear(); b.clear();
    if ((n%4) == 0) target = n;
    else if ((n%4) == 1) target = 1;
    else if ((n%4) == 2) target = n + 1;
    else if ((n%4) == 3) target = 0;
    fac(a, n); fac(b, target);
    while (b.size() < a.size()) b.push_back(0);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
}

//                      x        y       before
long long Solve(int indx, int lo1, int lo2, int carry1, int carry2, int isZero)
{
    ll &ans = dp[indx][lo1][lo2][carry1][carry2][isZero];
    if (ans != -1) return ans;
    if (indx == a.size()) return ans = ((carry1 + carry2) == 0 && lo2 == 1 && isZero == 1);
    ans = 0;
    for (int x = 0; x < 2; ++x)
    {
        if (lo1 == 0 && x > a[indx]) break;
        for (int y = 0; (y < 2); ++y)
        {
            if (lo2 == 0 && (y > x)) break;
            if ((x + y + carry2 > 1) == carry1 && (x^y^((x+y+carry2)&1)) == b[indx])
            {
                ans += Solve(indx + 1, (lo1 | (x < a[indx])), (lo2 | (y < x)), carry2, 0, (isZero | (y > 0)));
                ans += Solve(indx + 1, (lo1 | (x < a[indx])), (lo2 | (y < x)), carry2, 1, (isZero | (y > 0)));
            }
        }
    }
    return ans %= MOD;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lli", &n);
        preCom();
        memset(dp, -1, sizeof(dp));
        printf("%lli\n", (Solve(0, 0, 0, 0, 0, 0) + Solve(0, 0, 0, 0, 1, 0))%MOD);
    }
}
