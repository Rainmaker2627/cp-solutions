#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
	dp[1][0]=1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= min(i*(i-1)/2, k); ++j) {
			dp[i][j]=dp[i-1][j];
			if (j>0) dp[i][j]+=dp[i][j-1];
			if (j>=i) dp[i][j]-=dp[i-1][j-i];
			dp[i][j]=(dp[i][j]+mod)%mod;
		}
	}

	cout << dp[n][k] << '\n';
	return 0;
}