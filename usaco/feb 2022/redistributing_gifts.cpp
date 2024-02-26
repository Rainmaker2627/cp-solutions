#include<bits/stdc++.h>
using namespace std;

void dfs(int n, vector<vector<int>>& e, vector<int>& s, vector<int>& t) {
	s[n]=true;
	for (auto i : e[n]) {
		if (s[i]) continue;
		dfs(i, e, s, t);
	} t.push_back(n);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> g(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> g[i][j];
			g[i][j]--;
		}
	}

	vector<vector<int>> f(n, vector<int>()), r(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (g[i][j]==i) break;
			f[i].push_back(g[i][j]);
			r[g[i][j]].push_back(i);
		}
	}

	vector<int> t(n, 0), v(n, 0);
	for (int i = 0; i < n; ++i) if (!v[i]) dfs(i, f, v, t);
	reverse(t.begin(), t.end());

	v.assign(n, 0);
	vector<int> a(n);
	vector<vector<int>> scc;
	for (auto i : t) {
		if (!v[i]) {
			vector<int> c;
			dfs(i, r, v, c);
			scc.push_back(c);
			for (auto j : c) a[j]=scc.size()-1;
		}
	}

	for (int i = 0; i < n; ++i) {
		int ans=i;
		vector<int> r(n);
		for (int j = 0; j < n; ++j) r[g[i][j]]=j;
		for (auto j : scc[a[i]]) {
			if (r[j]<r[ans]) ans=j;
		} cout << ans+1 << '\n';
	}

	return 0;
}