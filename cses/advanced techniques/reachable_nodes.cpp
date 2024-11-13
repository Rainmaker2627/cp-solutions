#pragma GCC target("popcnt")
#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> ind(n, 0);
	vector<vector<int>> adj(n);
	vector<bitset<50000>> bs(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[b-1].push_back(a-1);
		ind[a-1]++;
	}

	queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (ind[i]==0) q.push(i);
		bs[i]=bitset<50000>();
		bs[i].set(i);
	}

	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (auto v : adj[u]) {
			if (--ind[v]==0) q.push(v);
			bs[v]|=bs[u];
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << bs[i].count() << ' ';
	} cout << '\n';

	return 0;
}