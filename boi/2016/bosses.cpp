#include<bits/stdc++.h>
using namespace std;

int n;
const int inf=1e9;
vector<int> sal;
vector<vector<int>> adj;

int bfs(int s) {
	sal.assign(n+1, 0);
	stack<pair<int, int>> t;
	queue<pair<int, int>> q;
	q.push({s, 0}); sal[s]=1;
	while (!q.empty()) {
		auto [u, p] = q.front();
		t.push({u, p});
		q.pop();

		for (auto v : adj[u]) {
			if (sal[v]) continue;
			sal[v]=1;
			q.push({v, u});
		}
	}

	while (!t.empty()) {
		auto [u, p] = t.top();
		sal[p]+=sal[u];
		t.pop();
	}

	int m=0;
	for (int i = 1; i <= n; ++i) {
		m+=sal[i];
		if (sal[i]==0) return inf;
	} return m;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n;
	adj.assign(n+1, vector<int>());
	for (int i = 1; i <= n; ++i) {
		int k, v;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			cin >> v;
			adj[v].push_back(i);
		}
	}

	int m=inf;
	for (int i = 1; i <= n; ++i) {
		m=min(m, bfs(i));
	} cout << m << '\n';

	return 0;
}