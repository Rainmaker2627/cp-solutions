#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;
vector<int> ret, dep;
vector<vector<int>> adj;
vector<pair<int, int>> e;

void dfs(int u, int p) {
	dep[u]=dep[p]+1;
	for (auto v : adj[u]) {
		if (v==p) continue;
		if (dep[v]<dep[u]) { e.push_back({u, v}); }
		if (dep[v]==0) { dfs(v, u); ret[u]=min(ret[u], ret[v]); }
		if (dep[v]<dep[u]) { ret[u]=min(ret[u], dep[v]); }
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	adj.assign(n+1, vector<int>());
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	ret.assign(n+1, inf);
	dep.assign(n+1, 0);
	dfs(1, 1);

	bool b=true;
	for (int i = 2; i <= n; ++i) b&=ret[i]<dep[i];
	if (!b || e.size()!=m) {
		cout << "IMPOSSIBLE\n";
	} else {
		for (auto [u, v] : e) {
			cout << u << ' ' << v << '\n';
		}
	}

	return 0;
}