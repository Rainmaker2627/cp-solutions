#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n=1e7, m, q;
    cin >> m >> q;
    vector<int> pr(m), dec(n+1);
    for (int i = 0; i < m; i++) {
        cin >> pr[i];
        for (int j = pr[i]; j <= n; j+=pr[i]) dec[j-1]=pr[i]-1;
        dec[n]=max(dec[n], n%pr[i]);
    }

    vector<int> dp(n+1, inf); dp[0]=0;
    for (int i = n; i > 0; i--) dec[i]=max(dec[i], dec[i+1]-1);
    for (int i = 1; i <= n; i++) dp[i]=min(inf, dp[i-dec[i]]+1);
    
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (dp[x]==inf) cout << "oo\n";
        else cout << dp[x] << '\n';
    }

    return 0;
}