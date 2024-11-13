#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;
vector<int> out, dep;
vector<pair<int, int>> ans;
vector<vector<int>> adj;

void dfs(int u, int p) {
	dep[u]=dep[p]+1;
	for (auto v : adj[u]) {
		if (v==p) continue;
		if (dep[v]<dep[u]) {
			out[u]++; ans.push_back({u, v});
		} else if (dep[v]==inf) {
			dfs(v, u);
			if (out[v]%2==1) { out[v]++; ans.push_back({v, u}); }
			else { out[u]++; ans.push_back({u, v}); }
		}
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

	bool b=(m%2==0);
	dep.assign(n+1, inf);
	out.assign(n+1, 0);
	for (int i = 1; i <= n && b; ++i) {
		if (dep[i]==inf) {
			dep[i]=0;
			dfs(i, i);
		} b&=(out[i]%2==0);
	}

	if (b) {
		for (auto [u, v] : ans) {
			cout << u << ' ' << v << '\n';
		}
	} else {
		cout << "IMPOSSIBLE\n";
	}

	return 0;
}