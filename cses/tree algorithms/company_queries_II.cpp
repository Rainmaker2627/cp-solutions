#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> p, c;
vector<int> h, e;

void dfs(int u, int v) {
	h[u]=h[v]+1;
	for (auto i : c[u]) {
		dfs(i, u);
	}
}

int lca(int a, int b) {
	if (h[a]<h[b]) swap(a, b);
	int d=h[a]-h[b];
	for (int i = 0; i <= 20; ++i) {
		if (d&(1<<i)) a=p[i][a];
	} if (a==b) return b;
	for (int i = 20; i >= 0; --i) {
		if (p[i][a]==p[i][b]) continue;
		a=p[i][a], b=p[i][b];
	} return p[0][a];
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	p.assign(21, vector<int>(n+1, 1));
	c.assign(n+1, vector<int>());
	h.assign(n+1, 0);
	for (int i = 2; i <= n; ++i) {
		cin >> p[0][i];
		c[p[0][i]].push_back(i);
	}

	dfs(1, 1);
	for (int i = 1; i <= 20; ++i) {
		for (int j = 1; j <= n; ++j) {
			p[i][j]=p[i-1][p[i-1][j]];
		}
	}

	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}

	return 0;
}