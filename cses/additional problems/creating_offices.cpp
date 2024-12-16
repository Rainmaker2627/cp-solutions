#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> pq;

int n, d;
vector<int> dep;
vector<vector<int>> adj;

pq dfs(int u, int p) {
	dep[u]=dep[p]+1;
	pq ans;
	ans.push({dep[u], u});
	for (auto v : adj[u]) {
		if (v==p) continue;
		auto ch=dfs(v, u);
		if (ans.size()<ch.size()) swap(ans, ch);
		int a=ans.top().first, b=ch.top().first;
		while (!ch.empty()) { ans.push(ch.top()); ch.pop(); }
		if (a+b-2*dep[u]<d) ans.pop();
	} return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> d;
	adj.assign(n+1, vector<int>());
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dep.assign(n+1, 0);
	auto ans=dfs(1, 1);
	cout << ans.size() << '\n';
	while (!ans.empty()) { cout << ans.top().second << ' '; ans.pop(); }

	return 0;
}