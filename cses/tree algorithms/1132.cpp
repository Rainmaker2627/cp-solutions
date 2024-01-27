#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> e;
vector<int> d, a, b;

void max_set(int i, int v) {
	if (v>=a[i]) {
		swap(a[i], b[i]);
		a[i]=v;
	} else if (v>=b[i]) b[i]=v;
}

void dfs(int u, int p, bool t) {
	if (t) {
		for (auto v : e[u]) {
			if (v==p) continue;
			dfs(v, u, true);
			d[u]=max(d[u], d[v]+1);
			max_set(u, d[v]+1);
		}
	} else {
		if (u!=p) {
			if (a[p]==d[u]+1) max_set(u, b[p]+1);
			else max_set(u, a[p]+1);
		}
		for (auto v : e[u]) {
			if (v==p) continue;
			dfs(v, u, false);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> t(n+1, vector<int>());
	for (int i = 2; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		t[a].push_back(b);
		t[b].push_back(a);
	} swap(t, e);

	d.reserve(n+1); a.reserve(n+1); b.reserve(n+1);
	for (int i = 1; i <= n; ++i) d[i]=a[i]=b[i]=0;
	dfs(1, 1, true); dfs(1, 1, false);

	for (int i = 1; i <= n; ++i) cout << a[i] << ' ';

	return 0;
}