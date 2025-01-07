#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;

const int inf=1e18;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    string s;
    cin >> s;
    int n=s.size();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    string b="bessie";
    vector<vector<pii>> dp(n+1, vector<pii>(6, {0, -inf}));
    dp[0][0]={0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            auto [x, y]=dp[i][j];
            if (j==5) {
                if (s[i]==b[j] && dp[i][j].second!=-inf) dp[i+1][0]=max(dp[i+1][0], {x+1, y});
                dp[i+1][j]=max(dp[i+1][j], {x, max(-inf, y-a[i])});
            } else {
                if (s[i]==b[j]) dp[i+1][j+1]=dp[i][j];
                dp[i+1][j]=max(dp[i+1][j], {x, (j==0?y:max(-inf, y-a[i]))});
            }
        }
    } cout << dp[n][0].first << '\n' << -dp[n][0].second << '\n';

    return 0;
}