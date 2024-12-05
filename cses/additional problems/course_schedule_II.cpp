#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> ind(n+1, 0);
	vector<vector<int>> adj(n+1, vector<int>());
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
		ind[a]++;
	}

	priority_queue<int> pq;
	for (int i = 1; i <= n; ++i) {
		if (ind[i]==0) pq.push(i);
	}

	vector<int> ans;
	while (!pq.empty()) {
		int u=pq.top();
		pq.pop();
		ans.push_back(u);

		for (auto v : adj[u]) {
			if (--ind[v]==0) pq.push(v);
		}
	}

	reverse(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << i << ' ';
	} cout << '\n';

	return 0;
}