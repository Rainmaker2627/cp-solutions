#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> c, a;

set<int> dfs(int u, int p) {
	set<int> s;
	s.insert(c[u]);
	for (auto v : g[u]) {
		if (v==p) continue;
		set<int> t=dfs(v, u);
		if (t.size()>s.size()) swap(s, t);
		for (auto i = t.begin(); i != t.end(); ++i) {
			s.insert(*i);
		}
	} a[u]=s.size();
	return s;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	c.assign(n+1, 0), a.assign(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}

	g.assign(n+1, vector<int>());
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1, 1);
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << " \n"[i==n];
	}

	return 0;
}