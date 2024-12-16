#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;

const int inf=1e18;
vector<int> dep, ret, crit;

void dfs(int u, int p, vector<vector<int>>& adj) {
	int m=-1;
	dep[u]=dep[p]+1;
	for (auto v : adj[u]) {
		if (v==p) continue;
		if (dep[v]) {
			ret[u]=min(ret[u], dep[v]);
		} else {
			dfs(v, u, adj);
			ret[u]=min(ret[u], ret[v]);
			if (ret[v]>=dep[u] && u!=1) {
				crit.push_back(u);
			}
		}
	}
}

void dijkstra(int s, vector<int>& d, vector<vector<pii>>& adj) {
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

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<pii>> fwd(n+1, vector<pii>()), rev(n+1, vector<pii>());
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		fwd[a].push_back({b, c});
		rev[b].push_back({a, c});
	}

	vector<int> d1(n+1, inf), dn(n+1, inf);
	dijkstra(1, d1, fwd); dijkstra(n, dn, rev);

	map<pii, bool> ase;
	queue<int> q; q.push(1);
	vector<vector<int>> spg(n+1, vector<int>());
	while (!q.empty()) {
		auto u=q.front(); q.pop();
		for (auto [v, w] : fwd[u]) {
			if (d1[u]+dn[v]+w>d1[n]) continue;
			if (ase[{min(u, v), max(u, v)}]) continue;
			ase[{min(u, v), max(u, v)}]=true;
			spg[u].push_back(v);
			spg[v].push_back(u);
			q.push(v);
		}
	}

	dep.assign(n+1, 0);
	ret.assign(n+1, inf);
	dfs(1, 1, spg);

	crit.push_back(1);
	crit.push_back(n);
	sort(crit.begin(), crit.end());
	cout << crit.size() << '\n';
	for (auto u : crit) {
		cout << u << ' ';
	} cout << '\n';

	return 0;
}