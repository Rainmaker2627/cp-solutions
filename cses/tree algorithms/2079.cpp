#include<bits/stdc++.h>
using namespace std;

vector<int> s, m, c;
vector<vector<int>> g;

void dfs(int u, int p) {
	for (auto v : g[u]) {
		if (v==p) continue;
		dfs(v, u);
		s[u]+=s[v];
		if (s[v]>m[u]) m[u]=s[v], c[u]=v;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	g.assign(n+1, vector<int>());
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int r=1;
	s.assign(n+1, 1);
	m.assign(n+1, 0);
	c.assign(n+1, 0);
	dfs(r, r);
	while (m[r]>n/2) r=c[r];
	
	cout << r << '\n';\
	return 0;
}