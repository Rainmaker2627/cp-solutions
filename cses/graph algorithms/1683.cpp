#include<bits/stdc++.h>
using namespace std;

vector<bool> s;

void dfs(int u, vector<int>& c, vector<vector<int>>& g) {
	s[u]=true;
	for (auto v : g[u]) {
		if (s[v]) continue;
		dfs(v, c, g);
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

	int c=0;
	s.assign(n+1, false);
	vector<int> tout, ans(n+1);
	for (int i = 1; i <= n; ++i) {
		if (!s[i]) dfs(i, tout, f);
	} reverse(tout.begin(), tout.end());
	s.assign(n+1, false);
	for (auto i : tout) {
		if (s[i]) continue;
		vector<int> t;
		dfs(i, t, r); c++;
		for (auto j : t) {
			ans[j]=c;
		}
	}

	cout << c << '\n';
	for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i==n];
	return 0;
}