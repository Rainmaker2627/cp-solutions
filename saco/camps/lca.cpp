#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> e, par;
vector<int> h;

void dfs(int v) {
	for (auto i : e[v]) {
		if (par[i][0]>-1) continue;
		par[i][0]=v;
		h[i]=h[v]+1;
		dfs(i);
	}
}

int lca(int a, int b) {
	if (h[a]<h[b]) swap(a, b);
	int d=h[a]-h[b];
	for (int i = 31; i >= 0; --i) {
		if (d&(1<<i)) {
			a=par[a][i];
		}
	}

	if (a==b) return a;
	for (int i = 31; i >= 0; --i) {
		if (par[a][i]!=par[b][i]) {
			a=par[a][i];
			b=par[b][i];
		}
	}
	return par[a][0];
}

int main() {
	int n, q;
	cin >> n >> q;
	vector<vector<int>> a(n, vector<int>()), b(n, vector<int>(32, -1));
	swap(b, par); swap(a, e);
	h.reserve(n);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	par[0][0]=0; h[0]=0;
	dfs(0);

	for (int i = 1; i < 32; ++i) {
		for (int j = 0; j < n; ++j) {
			par[j][i]=par[par[j][i-1]][i-1];
		}
	}

	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
	return 0;
}