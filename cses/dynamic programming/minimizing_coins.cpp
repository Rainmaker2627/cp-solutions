#include<bits/stdc++.h>
using namespace std;

int n, x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> x;
	vector<int> dp(x+1, 1e9), c(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
		if (c[i]<=x) dp[c[i]]=1;
	}

	for (int i = 1; i <= x; ++i) {
		for (auto j : c) {
			if (i+j<=x) dp[i+j]=min(dp[i]+1, dp[i+j]);
		}
	}

	cout << (dp[x]==1e9?-1:dp[x]) << '\n';
	return 0;
}