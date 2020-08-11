#define ll long long
#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>

using namespace std;
const ll limit = 1ll*1e18, INF = 100000000000, MOD = 1000000007, N = 100000;
ll prefix[N + 1], sum, ans;
int  c[N + 1], l[N + 1], prime[N + 1], d = -1, k, bit, prod, n, x;

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 2; i <= N; ++i)
    {
        if (!l[i])
        {
            l[i] = i;
            prime[++d] = i;
        }
        k = N/i;
        for (int j = 0; j <= d && prime[j] <= l[i] && prime[j] <= k; ++j)
            l[i*prime[j]] = prime[j];
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x); k = 0, sum = 0;
        while (x > 1)
        {
            int tmp = x;
            c[k++] = l[x];
            while (x > 1 && x%l[tmp] == 0) x /= l[tmp];
        }
        for (int mask = 1; mask < (1 << k); ++mask)
        {
            bit = 0; prod = 1;
            for (int j = 0; j < k; ++j) if (mask&(1 << j))
            {
                ++bit;
                prod *= c[j];
            }
            prefix[prod] += i;
            if (bit&1) sum += prefix[prod];
            else sum -= prefix[prod];
        }
        ans += 1ll*sum*(n - i + 1);
        if (ans > limit) ans = limit + 1;
    }
    if (ans > limit) printf("-1");
    else printf("%lli", ans);
}
