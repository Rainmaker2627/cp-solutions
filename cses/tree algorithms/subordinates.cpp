#include<bits/stdc++.h>
using namespace std;

vector<int> s;
vector<vector<int>> adj;

void dfs(int u, int p) {
	for (auto v : adj[u]) {
		if (v==p) continue;
		dfs(v, u);
		s[u]+=s[v];
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	adj.assign(n+1, vector<int>());
	for (int i = 2; i <= n; ++i) {
		int a;
		cin >> a;
		adj[a].push_back(i);
		adj[i].push_back(a);
	}

	s.assign(n+1, 1);
	dfs(1, 1);
	for (int i = 1; i <= n; ++i) {
		cout << s[i]-1 << ' ';
	}

	return 0;
}