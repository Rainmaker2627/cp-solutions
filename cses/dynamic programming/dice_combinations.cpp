#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<int> dp(n+1, 0);
	dp[0]=1;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= 6; ++j) {
			if (i+j<=n) dp[i+j]=(dp[i+j]+dp[i])%mod;
		}
	}

	cout << dp[n] << '\n';
	return 0;
}