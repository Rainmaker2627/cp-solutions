#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> adj, cap;

bool bfs(int s, int t, vector<int>& p) {
	fill(p.begin(), p.end(), 0);
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		auto cur=q.front();
		q.pop();

		for (auto i : adj[cur]) {
			if (p[i] || cap[cur][i]==0) continue;
			p[i]=cur;
			if (i==t) return true;
			q.push(i);
		}
	}

	return false;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	adj.assign(n+1, vector<int>());
	cap.assign(n+1, vector<int>(n+1, 0));
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		cap[a][b]=cap[b][a]=1;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int cut=0, req;
	vector<int> p(n+1);
	while (req=bfs(1, n, p)) {
		cut += req;
		int cur=n;
		while (cur!=1) {
			int prev = p[cur];
			cap[prev][cur] -= req;
			cap[cur][prev] += req;
			cur = prev;
		}
	}

	cout << cut << '\n';

	queue<int> q;
	q.push(1);
	p[1]=-1;
	while (!q.empty()) {
		auto cur=q.front();
		q.pop();
		for (auto i : adj[cur]) {
			if (p[i]<0) continue;
			p[i]=-p[i];
			if (p[i]==0) {
				cout << cur << ' ' << i << '\n';
			} else {
				q.push(i);
			}
		}
	}


	return 0;
}