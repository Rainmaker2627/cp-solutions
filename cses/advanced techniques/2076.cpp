#include<bits/stdc++.h>
using namespace std;

int t=0;
vector<int> s, dp;
vector<vector<int>> g;
vector<pair<int, int>> ans;

void dfs(int u, int p) {
	s[u]=++t;
	for (auto v : g[u]) {
		if (v==p) continue;
		if (s[v]) {
			if (s[v]>s[u]) dp[u]--;
			else dp[u]++;
			continue;
		} dfs(v, u);
		if (dp[v]) dp[u]+=dp[v];
		else ans.push_back({u, v});
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	g.assign(n+1, vector<int>());
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	s.assign(n+1, 0);
	dp.assign(n+1, 0);
	dfs(1, 1);

	cout << ans.size() << '\n';
	for (auto [u, v] : ans) {
		cout << u << ' ' << v << '\n';
	}

	return 0;
}