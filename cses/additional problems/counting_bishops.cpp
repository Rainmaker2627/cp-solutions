#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;
int squares(int i) {
    if (i%2) return i/4*2+1;
    else return (i-2)/4*2+2;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    if (k>=2*n) { cout << 0 << '\n'; return 0; }
    vector<vector<int>> dp(2*n, vector<int>(k+1, 0));
    dp[0][0]=dp[1][0]=dp[1][1]=1;
    for (int i = 2; i < 2*n; i++) {
        int x=squares(i);
        for (int j = 0; j <= min(x, k); j++) {
            dp[i][j]=dp[i-2][j];
            if (j>0) dp[i][j]=(dp[i][j]+(x-j+1)*dp[i-2][j-1])%mod;
        }
    }
    
    int ans=0;
    for (int i = 0; i <= k; i++) {
        ans=(ans+dp[2*n-2][i]*dp[2*n-1][k-i])%mod;
    } cout << ans << '\n';

    return 0;
}