#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	dp[1][1]=1;

	char c;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> c;
			if (c=='*') { dp[i][j]=0; continue; }
			(dp[i][j]+=dp[i-1][j]+dp[i][j-1])%=mod;
		}
	}

	cout << dp[n][n] << '\n';
	return 0;
}