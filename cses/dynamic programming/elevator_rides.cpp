#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, x;
	cin >> n >> x;
	int m=1<<n;

	vector<int> w(n);
	vector<pair<int, int>> dp(m, {inf, inf});
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
		dp[1<<i]={1, w[i]};
	}

	for (int i = 3; i < m; ++i) {
		if ( (i&(i-1))==0 ) continue;
		for (int j = 0; j < n; ++j) {
			if ( ((1<<j)&i)==0 ) continue;
			int t=i-(1<<j);
			if (dp[t].second+w[j]>x) dp[i]=min(dp[i], {dp[t].first+1, min(dp[t].second, w[j])});
			else dp[i]=min(dp[i], {dp[t].first, dp[t].second+w[j]});
		}
	}

	cout << dp[m-1].first << '\n';
	return 0;
}