#include<bits/stdc++.h>
using namespace std;

vector<bool> s;

void dfs(int u, vector<int>& c, vector<vector<int>>& e) {
	s[u]=true;
	for (auto v : e[u]) {
		if (s[v]) continue;
		dfs(v, c, e);
	} c.push_back(u);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> f(n+1, vector<int>()), r(n+1, vector<int>());
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		f[a].push_back(b);
		r[b].push_back(a);
	}

	s.assign(n+1, false);
	vector<int> tout, scc;
	for (int i = 1; i <= n; ++i) {
		if (!s[i]) dfs(i, tout, f);
	} s.assign(n+1, false);
	dfs(tout[tout.size()-1], scc, r);
	if (scc.size()!=n) {
		cout << "NO\n";
		sort(scc.begin(), scc.end());
		bool b=false;
		for (int i = 1; i <= scc.size() && !b; ++i) {
			if (scc[i-1]==i) continue;
			cout << i << ' ' << scc[i-1] << '\n';
			b=true;
		} if (!b) cout << scc.size()+1 << ' ' << scc.size() << '\n';
	} else cout << "YES\n";

	return 0;
}