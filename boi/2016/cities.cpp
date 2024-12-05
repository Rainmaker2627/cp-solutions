#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
 
const int inf=1e18;
 
signed main() {
	cin.tie(0)->sync_with_stdio(false);
 
	int n, k, m;
	cin >> n >> k >> m;
	vector<int> imp(k);
	vector<vector<pii>> adj(n+1, vector<pii>());
	for (int i = 0; i < k; ++i) cin >> imp[i];
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
		adj[b].push_back({c, a});
	}
 
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<vector<int>> dp(1<<(--k), vector<int>(n+1, inf));
	for (int i = 0; i < k; ++i) dp[1<<i][imp[i]]=0;
	for (int mask = 1; mask < (1<<k); ++mask) {
		for (int sub = mask; sub; sub = (sub-1)&mask) {
			for (int i = 1; i <= n; ++i) {
				dp[mask][i]=min(dp[mask][i], dp[sub][i]+dp[mask^sub][i]);	
			}
		}
 
		auto &d=dp[mask];
		for (int i = 1; i <= n; ++i) pq.push({d[i], i});
		while (!pq.empty()) {
			auto [c, u]=pq.top(); pq.pop();
			if (c>d[u]) continue;
			else d[u]=c;
			for (auto [w, v] : adj[u]) {
				if (d[v]<w+c) continue;
				pq.push({w+c, v});
			}
		}
	}
 
	cout << dp[(1<<k)-1][imp[k]] << '\n';
	return 0;
}