#include<bits/stdc++.h>
using namespace std;

int n, m, k, s;
vector<bool> ans;
vector<int> dist, par, cyc, skip;
vector<vector<int>> chl;

void add(int u, int p, int v) {
	if (u>n) return;
	cyc[dist[u]-dist[p]+s]+=v;
	for (auto i : chl[u]) add(i, p, v);
}

void dfs(int u) {
	if (u>n) {
		int d=k-dist[u];
		if (d==0) ans[u]=true;
		for (int i = 1; i*i <= d; ++i) if (d%i==0 && (cyc[i] || cyc[d/i])) ans[u]=true;
		for (int i = par[u]; i >= 0; i=par[i]) if (d-s+dist[i]>=0 && skip[d-s+dist[i]]) ans[u]=true;
	} else {
		add(u, u, 1);
		for (auto v : chl[u]) dfs(v);
		add(u, u, -1);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m >> k >> s; s++;
	cyc.assign(2*k+1, 0);
	skip.assign(2*k+1, 0); skip[0]=1;
	dist.assign(n+m+1, 0);
	par.assign(n+m+1, 0); par[0]=-1;
	ans.assign(n+m+1, false);
	chl.assign(n+m+1, vector<int>());

	for (int i = 1; i <= n+m; ++i) {
		int p, l;
		cin >> p >> l;
		par[i]=p;
		chl[p].push_back(i);
		dist[i]=dist[p]+l+1;
		if (i<=n) skip[dist[i]]++;
	}

	dfs(0);
	for (int i = n+1; i <= n+m; ++i) {
		cout << (ans[i]?"YES":"NO") << '\n';
	}

	return 0;
}