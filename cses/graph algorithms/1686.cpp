#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<bool> s;

void dfs(int u, vector<int>& c, vector<vector<int>>& g) {
	s[u]=true;
	for (auto v : g[u]) {
		if (s[v]) continue;
		dfs(v, c, g);
	} c.push_back(u);
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> k(n+1);
	vector<vector<int>> f(n+1, vector<int>()), r(n+1, vector<int>());
	for (int i = 1; i <= n; ++i) cin >> k[i];
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		f[a].push_back(b);
		r[b].push_back(a);
	}

	int c=0;
	s.assign(n+1, false);
	vector<int> tout, comp(n+1), ck(1, 0);
	for (int i = 1; i <= n; ++i) {
		if (!s[i]) dfs(i, tout, f);
	} s.assign(n+1, false);
	for (int i = n-1, u = tout[n-1]; i >= 0; u=tout[--i]) {
		if (s[u]) continue;
		int x=0;
		vector<int> t;
		dfs(u, t, r); c++;
		for (auto v : t) {
			comp[v]=c;
			x+=k[v];
		} ck.push_back(x);
	}

	vector<int> in(c+1, 0);
	vector<vector<int>> scc(c+1, vector<int>());
	for (int i = 1; i <= n; ++i) {
		for (auto v : f[i]) {
			if (comp[i]==comp[v]) continue;
			scc[comp[i]].push_back(comp[v]);
			in[comp[v]]++;
		}
	}

	queue<int> q;
	vector<int> dp(c+1, 0);
	for (int i = 1; i <= c; ++i) {
		if (in[i]==0) q.push(i);
	} int ans=0;
	while (!q.empty()) {
		int u=q.front(); q.pop();
		ans=max(ans, dp[u]+=ck[u]);
		for (auto v : scc[u]) {
			dp[v]=max(dp[v], dp[u]);
			if (in[v]--==1) q.push(v);
		}
	} cout << ans << '\n';

	return 0;
}