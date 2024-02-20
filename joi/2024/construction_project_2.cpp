#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;

const int inf=1e18;
vector<vector<pii>> e;

void dijkstra(int s, vector<int>& d) {
	d[s]=0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, s});
	while (!pq.empty()) {
		auto [w, v]=pq.top();
		pq.pop();
		if (d[v]<w) continue;
		for (auto [u, t] : e[v]) {
			if (w+t<d[u]) {
				d[u]=w+t;
				pq.push({d[u], u});
			}
		}
	}
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m, s, t, l, k;
	cin >> n >> m >> s >> t >> l >> k;
	e.assign(n+1, vector<pii>());
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a].push_back({b, c});
		e[b].push_back({a, c});
	}

	vector<int> ds(n+1, inf), dt(n+1, inf);
	dijkstra(s, ds); dijkstra(t, dt);
	if (ds[t]<=k) {
		cout << n*(n-1)/2;
		return 0;
	}
	sort(ds.begin(), ds.end());
	sort(dt.begin(), dt.end());

	int ans=0;
	for (auto i : ds) {
		ans+=upper_bound(dt.begin(), dt.end(), k-i-l)-dt.begin();
	} cout << ans << '\n';

	return 0;
}