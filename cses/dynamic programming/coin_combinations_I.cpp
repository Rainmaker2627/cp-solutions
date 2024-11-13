#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int n, x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> x;
	vector<int> c(n), dp(x+1, 0);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
		if (c[i]<=x) dp[c[i]]=1;
	}

	for (int i = 0; i < x; ++i) {
		for (auto j : c) {
			if (j+i<=x) dp[i+j]=(dp[i+j]+dp[i])%mod;
		}
	}

	cout << dp[x] << '\n';
	return 0;
}