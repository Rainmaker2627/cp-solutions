#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;

const int inf=1e18;
int n, m, s, t, u, v;
vector<vector<pii>> adj;

void dijkstra(int s, vector<int>& d) {
	priority_queue<pii> pq;
	pq.push({0, s}); d[s]=0;
	while (!pq.empty()) {
		auto [c, u]=pq.top();
		pq.pop(); c=-c;
		if (d[u]<c) continue;
		for (auto [v, w] : adj[u]) {
			if (c+w>=d[v]) continue;
			else d[v]=w+c;
			pq.push({-d[v], v});
		}
	}
}

vector<int> spg(bool rev, vector<int>& d, vector<int>& ds, vector<int>& dt) {
	vector<int> ind(n+1, 0);
	vector<vector<int>> spg(n+1, vector<int>());
	for (int u = 1; u <= n; ++u) {
		for (auto [v, w] : adj[u]) {
			if (ds[u]+w+dt[v]>ds[t]) continue;
			if (rev) spg[v].push_back(u);
			else spg[u].push_back(v);
			ind[rev?u:v]++;
		}
	}

	int r=d[v];
	queue<int> q; q.push(rev?t:s);
	vector<int> dp(n+1, inf); dp[rev?t:s]=d[rev?t:s];
	while (!q.empty()) {
		auto u=q.front(); q.pop();
		if (--ind[u]!=-1) continue;
		for (auto v : spg[u]) {
			if (--ind[v]==0) q.push(v);
			dp[v]=min(dp[v], min(dp[u], d[v]));
		}
	} return dp;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m >> s >> t >> u >> v;
	adj.assign(n+1, vector<pii>());
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	vector<int> ds(n+1, inf), dt(n+1, inf), du(n+1, inf), dv(n+1, inf);
	dijkstra(s, ds); dijkstra(t, dt); dijkstra(u, du); dijkstra(v, dv);

	int r=du[v];
	auto dp=spg(false, du, ds, dt);
	auto dq=spg(true, du, ds, dt);
	for (int u = 1; u <= n; ++u) {
		r=min(r, min(dp[u], dq[u])+dv[u]);
	} cout << r << '\n';

	return 0;
}