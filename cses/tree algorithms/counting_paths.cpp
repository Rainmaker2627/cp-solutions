#include<bits/stdc++.h>
using namespace std;

vector<int> h, x;
vector<vector<int>> g, st;

void dfs(int u, int p) {
	h[u]=h[p]+1;
	for (auto v : g[u]) {
		if (v==p) continue;
		st[0][v]=u;
		dfs(v, u);
		x[u]+=x[v];
	}
}

int lca(int a, int b) {
	if (h[a]<h[b]) swap(a, b);
	int d=h[a]-h[b];
	for (int i = 0; i < 20; ++i) {
		if (d&(1<<i)) a=st[i][a];
	} if (a==b) return a;

	for (int i = 19; i >= 0; --i) {
		if (st[i][a]==st[i][b]) continue;
		a=st[i][a], b=st[i][b];
	} return st[0][a];
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	g.assign(n+1, vector<int>());
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	st.assign(20, vector<int>(n+1, 0));
	h.assign(n+1, 0); x.assign(n+1, 0);
	dfs(1, 1);

	for (int i = 1; i < 20; ++i) {
		for (int j = 1; j <= n; ++j) {
			st[i][j]=st[i-1][st[i-1][j]];
		}
	}

	for (int i = 0; i < m; ++i) {
		int a, b, l;
		cin >> a >> b;
		l = lca(a, b);
		x[a]++; x[b]++;
		x[l]--; x[st[0][l]]--;
	}

	dfs(1, 1);
	for (int i = 1; i <= n; ++i) {
		cout << x[i] << " \n"[i==n];
	}

	return 0;
}