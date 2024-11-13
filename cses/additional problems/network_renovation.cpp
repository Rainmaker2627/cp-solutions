#include<bits/stdc++.h>
using namespace std;

vector<int> l;
vector<vector<int>> adj;

void dfs(int u, int p) {
	if (adj[u].size()==1) l.push_back(u);
	for (auto v : adj[u]) {
		if (v==p) continue;
		dfs(v, u);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	adj.assign(n+1, vector<int>());
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 1);
	int m=l.size();
	cout << (m+1)/2 << '\n';
	for (int i = 0; i < (m+1)/2; ++i) {
		cout << l[i] << ' ' << l[i+m/2] << '\n';
	}

	return 0;
}