#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int n, x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> x;
	vector<int> c(n);
	vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	dp[0][0]=1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= x; ++j) {
			dp[i][j]=dp[i-1][j];
			if (j>=c[i-1]) (dp[i][j]+=dp[i][j-c[i-1]])%=mod;
		}
	}
	
	cout  << dp[n][x] << '\n';
	return 0;
}