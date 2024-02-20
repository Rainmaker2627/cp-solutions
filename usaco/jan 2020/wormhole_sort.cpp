#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> e;

void dfs(int u, int m, int g, vector<int>& c) {
	c[u]=g;
	for (auto [v, w] : e[u]) {
		if (c[v]) continue;
		if (w>m) dfs(v, m, g, c);
	}
}

bool possible(int n, int m, vector<int> c) {
	vector<int> g(n, 0);
	for (int i = 0; i < n; ++i) {
		if (!g[i]) dfs(i, m, i+1, g);
	}

	for (int i = 0; i < n; ++i) {
		if (g[i]!=g[c[i]]) return false;
	} return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	ifstream cin("wormsort.in");
	ofstream cout("wormsort.out");

	int n, m, b=true;
	cin >> n >> m;
	vector<int> a(n), c(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b&=(c[i]=a[i]-1)==i;
	} if (b) {
		cout << "-1\n";
		return 0;
	}

	e.assign(m, vector<pair<int, int>>());
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		e[--a].push_back({--b, w});
		e[b].push_back({a, w});
	}

	int hi=1e9+1, lo=1;
	while (lo<hi) {
		int mid=(hi+lo)/2;
		if (possible(n, mid, c)) lo=mid+1;
		else hi=mid;
	} cout << hi << '\n';

	return 0;
}