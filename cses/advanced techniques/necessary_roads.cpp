#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;
vector<int> dep, ret;
vector<vector<int>> adj;
vector<pair<int, int>> e;

void dfs(int u, int p) {
	dep[u]=ret[u]=dep[p]+1;
	for (auto v : adj[u]) {
		if (v==p) continue;
		if (dep[v]==0) dfs(v, u);
		if (dep[v]<dep[u]) ret[u]=min(ret[u], dep[v]);
		else ret[u]=min(ret[u], ret[v]);
	}

	if (ret[u]==dep[u]) {
		e.push_back({u, p});
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

	dep.assign(n+1, 0);
	ret.assign(n+1, inf);
	dfs(1, 1);
	e.pop_back();

	cout << e.size() << '\n';
	for (auto [u, v] : e) {
		cout << u << ' ' << v << '\n';
	}

	return 0;
}