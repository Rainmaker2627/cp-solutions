#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;
vector<int> dep;
vector<vector<int>> adj;

int bfs(int s) {
	dep[s]=1;
	queue<pair<int, int>> q;
	q.push({s, s});

	int ans=inf;
	while (!q.empty()) {
		auto [u, p]=q.front();
		q.pop();

		for (auto v : adj[u]) {
			if (v==p) continue;
			if (dep[v]) ans=min(ans, dep[u]+dep[v]-1);
			else { dep[v]=dep[u]+1; q.push({v, u}); }
		}
	} return ans;
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

	int ans=inf;
	for (int i = 1; i <= n; ++i) {
		dep.assign(n+1, 0);
		ans=min(ans, bfs(i));
	} cout << (ans==inf?-1:ans) << '\n';

	return 0;
}