#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;
int exp(int a, int b, int m) {
    int x=1;
    while (b) {
        if (b%2) x=a*x%m;
        a=a*a%m; b/=2;
    } return x;
}

vector<int> fact;
int binom(int a, int b) {
    return fact[a]*exp(fact[a-b]*fact[b]%mod, mod-2, mod)%mod;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> coord;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        coord.push_back({x, y});
    } sort(coord.begin(), coord.end());
    coord.push_back({n, n});

    fact.assign(2*n+1, 1);
    for (int i = 1; i <= 2*n; i++) {
        fact[i]=fact[i-1]*i%mod;
    }
    
    vector<int> dp(m+2);
    for (int i = 0; i <= m; i++) {
        auto [x1, y1]=coord[i];
        dp[i]=binom(x1+y1-2, x1-1);
        for (int j = 0; j < i; j++) {
            auto [x2, y2]=coord[j];
            if (y2>y1) continue;
            dp[i]-=dp[j]*binom(x1+y1-x2-y2, x1-x2);
            dp[i]=(dp[i]%mod+mod)%mod;
        }
    } cout << dp[m] << '\n';

    return 0;
}