#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
vector<int> dep, ret, crit;
vector<vector<int>> adj;

void dfs(int u, int p) {
	int m=-1;
	dep[u]=dep[p]+1;
	for (auto v : adj[u]) {
		if (v==p) continue;
		if (dep[v]>dep[u]) continue;
		if (dep[v]==0) dfs(v, u);
		if (dep[v]<dep[u]) ret[u]=min(ret[u], dep[v]);
		if (dep[v]>dep[u]) ret[u]=min(ret[u], ret[v]), m=max(m, ret[v]);
	}
	
	if (u==1) { if (m>1 && adj[1].size()>1) crit.push_back(1); }
	else if (m>=dep[u]) crit.push_back(u);
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

	cout << crit.size() << '\n';
	for (auto u : crit) {
		cout << u << ' ';
	} cout << '\n';

	return 0;
}