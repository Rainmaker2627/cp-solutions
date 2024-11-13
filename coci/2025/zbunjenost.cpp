#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9+7;
vector<int> dp;
vector<vector<int>> tadj;

void dfs(int u, int p) {
	dp[u]=1;
	for (auto v : tadj[u]) {
		if (v==p) continue;
		dfs(v, u);
		dp[u]=(dp[v]+1)*dp[u]%mod;
	}
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	if (n==3) { cout << 1 << '\n'; return 0; }
	vector<int> ind(n+1, 2);
	vector<set<int>> adj(n+1, set<int>());
	for (int i = 0; i < n-3; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
		ind[a]++; ind[b]++;
	}

	int ts=1, p=n+1;
	stack<int> s;
	for (int i = 1; i <= n; ++i) {
		adj[i].insert(i%n+1);
		adj[i%n+1].insert(i);
		if (ind[i]==2) { p=min(p, i); s.push(i); }
	}

	stack<pair<pair<int, int>, int>> r;
	tadj.assign(n+1, vector<int>());
	while (!s.empty()) {
		int u = s.top(); s.pop();
		if (!r.empty() && (r.top().first.first==u || r.top().first.second==u)) {
			tadj[ts].push_back(r.top().second);
			tadj[r.top().second].push_back(ts);
			r.pop();
		}

		auto t=adj[u].begin();
		int a=*(t++), b=*t;
		adj[a].erase(u); ind[a]--;
		adj[b].erase(u); ind[b]--;
		if (ind[b]==2 || ind[a]==2) {
			tadj[ts+1].push_back(ts);
			tadj[ts++].push_back(ts);
			if (ind[a]==2 && ind[b]==2) {
				if (!r.empty()) {
					tadj[ts].push_back(r.top().second);
					tadj[r.top().second].push_back(ts);
					r.pop();
				}
			} else {
				if (ind[a]==2) s.push(a);
				if (ind[b]==2) s.push(b);
			}
		} else {
			r.push({{a, b}, ts++});
		}
	}

	int m=0;
	dp.assign(ts+1, 0);
	dfs(1, 1);
	for (int i = 1; i <= ts; ++i) {
		if (dp[i]) m=(m+dp[i])%mod;
	} cout << m << '\n';

	return 0;
}