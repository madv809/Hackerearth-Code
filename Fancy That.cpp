#define ll long long
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
ll l, r;
int t;

ll solve(ll r){
    ll ans = 0;
    int k = -1;
    while (1){
        ++k;
        if (pow(10, k) >= r) break;
        for (ll i = 2; i <= 8; i += 2) if((i + 1)*(ll)pow(10, k) <= r) {
                ans += (ll)pow(10,k);
        }
        else{
            if (r >= i*(ll)pow(10, k)) ans += r - i*(ll)pow(10, k) + 1;
            break;
        }
    }
    return ans;
}

int main(){
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &t);
    while (t--){
        scanf("%lli %lli", &l, &r);
        printf("%lli\n", solve(r) - solve(l - 1));
    }
}
