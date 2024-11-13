#include<bits/stdc++.h>
using namespace std;

int n, k, c=0;
vector<int> L, R, ind, vis;
vector<vector<pair<int, int>>> adj;

void dfs(int u, int p) {
	if (vis[u]==0) vis[u]=2;
	for (auto [v, w] : adj[u]) {
		if (vis[v]==1 || vis[v]==2) continue;
		if (v==p) { p=-1; continue; }
		if (u>n) R[c]+=w;
		else L[c]+=w;
		dfs(v, u);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=0;
	cin >> n >> k;
	ind.assign(2*n+1, 0);
	adj.assign(2*n+1, vector<pair<int, int>>());
	for (int i = 0; i < 2*n; ++i) {
		int l, r, s;
		cin >> l >> r >> s;
		adj[l].push_back({n+r, s});
		adj[n+r].push_back({l, s});
		ind[l]++; ind[n+r]++;
		t+=s;
	}

	queue<int> q;
	vis.assign(2*n+1, 0);
	for (int i = 1; i <= 2*n; ++i) {
		if (ind[i]==1) q.push(i);
		if (ind[i]==0) {
			cout << "NO\n";
			return 0;
		}
	}

	int l=0, r=0;
	while (!q.empty()) {
		int u=q.front();
		q.pop();

		vis[u]=1;
		for (auto [v, w] : adj[u]) {
			if (vis[v]) continue;
			if (--ind[v]==1) q.push(v);
			if (ind[v]==0) {
				cout << "NO\n";
				return 0;
			}
			if (u>n) r+=w;
			else l+=w;
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		L.push_back(0);
		R.push_back(0);
		vis[i]=3;
		dfs(i, i);
		c++;
	}

	int m=abs(l-r);
	bitset<600001> dp;
	dp[0]=1; dp|=dp<<abs(l-r);
	for (int i = 0; i < c; ++i) {
		dp|=(dp<<abs(L[i]-R[i]));
		m+=abs(L[i]-R[i]);
	}

	for (int i = 0; i <= m; ++i) {
		if (dp[i] && abs(2*i-m)<=k) {
			cout << "YES\n";
			return 0;
		}
	} cout << "NO\n";

	return 0;
}