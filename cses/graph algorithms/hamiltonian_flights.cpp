#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int p=1<<n;
	vector<vector<int>> adj(n, vector<int>());
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
	}

	vector<vector<int>> dp(n, vector<int>(p, 0));
	queue<pair<int, int>> q;
	dp[0][1]=1;
	q.push({0, 1});
	while(!q.empty()) {
		auto [u, mask] = q.front();
		q.pop();

		if (u!=n-1) {
			for (auto v : adj[u]) {
				int nmask = mask|(1<<v);
				if (mask&(1<<v)) continue;
				if (dp[v][nmask]==0) q.push({v, nmask});
				dp[v][nmask]=(dp[v][nmask]+dp[u][mask])%mod;
			}
		}
	}

	cout << dp[n-1][p-1] << '\n';
	return 0;
}