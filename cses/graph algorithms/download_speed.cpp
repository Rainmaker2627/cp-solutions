#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf=1e18;
vector<vector<int>> adj, cap;

int bfs(int s, int t, vector<int>& par) {
	fill(par.begin(), par.end(), 0);
	queue<pair<int, int>> q;
	q.push({s, inf});
	while(!q.empty()) {
		auto [cur, flow] = q.front();
		q.pop();

		for (auto i : adj[cur]) {
			if (par[i] || cap[cur][i]==0) continue;
			par[i]=cur;
			int cflow=min(flow, cap[cur][i]);
			if (i==t) return cflow;
			q.push({i, cflow});
		}
	}
	
	return 0;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	adj.assign(n+1, vector<int>());
	cap.assign(n+1, vector<int>(n+1, 0));
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		cap[a][b]+=c;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int mflow=0, nflow;
	vector<int> par(n+1);
	while (nflow = bfs(1, n, par)) {
		mflow += nflow;
		int cur = n;
		while (cur != 1) {
			int prev = par[cur];
			cap[prev][cur] -= nflow;
			cap[cur][prev] += nflow;
			cur = prev;
		}
	}

	cout << mflow << '\n';

	return 0;
}