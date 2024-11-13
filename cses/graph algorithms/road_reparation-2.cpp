#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> e(n+1, vector<pair<int, int>>());
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}

	ll s=0, t=n;
	priority_queue<pair<int, int>> pq;
	vector<bool> p(n+1, false);
	pq.push({0, 1});
	while (!pq.empty()) {
		auto [w, u] = pq.top();
		pq.pop();
		if (p[u]) continue;
		p[u]=true; t--; s-=w;
		for (auto [v, c] : e[u]) {
			pq.push({-c, v});
		}
	}

	if (t) cout << "IMPOSSIBLE\n";
	else cout << s << '\n';

	return 0;
}