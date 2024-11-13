#include<bits/stdc++.h>
using namespace std;

vector<bool> mat;
vector<vector<int>> adj;

void dfs(int u, int p) {
	for (auto v : adj[u]) {
		if (v==p) continue;
		dfs(v, u);
		if (!mat[v] && !mat[u]) mat[u]=mat[v]=true;
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

	mat.assign(n+1, false);
	dfs(1, 1);

	int s=0;
	for (int i = 1; i <= n; ++i) {
		s+=mat[i];
	} cout << s/2 << '\n';

	return 0;
}