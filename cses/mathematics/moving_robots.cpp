#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int k;
	cin >> k;

	vector<vector<int>> adj(64, vector<int>());
	for (int i = 0; i < 64; ++i) {
		if (i%8>0) adj[i].push_back(i-1);
		if (i%8<7) adj[i].push_back(i+1);
		if (i>7) adj[i].push_back(i-8);
		if (i<56) adj[i].push_back(i+8);
	}

	vector<vector<long double>> dp(k+1, vector<long double>(64, 0));
	vector<long double> ans(64, 1);
	for (int s = 0; s < 64; s++) {
		dp.assign(k+1, vector<long double>(64, 0));
		dp[0][s]=1;
		for (int t = 1; t <= k; ++t) {
			for (int i = 0; i < 64; ++i) {
				for (auto j : adj[i]) {
					dp[t][i]+=dp[t-1][j]/adj[j].size();
				}
			}
		}

		for (int i = 0; i < 64; ++i) {
			ans[i]*=(1-dp[k][i]);
		}
	}

	long double s=0;
	for (int i = 0; i < 64; ++i) {
		s+=ans[i];
	} cout << fixed << setprecision(6) << s << '\n';

	return 0;
}