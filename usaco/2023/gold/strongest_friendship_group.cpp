#include<bits/stdc++.h>
using namespace std;

struct dsu {
	int n;
	vector<int> s, r;

	dsu(int _n) {
		n=_n;
		s.assign(n, 1);
		r.assign(n, 0);
		for (int i = 0; i < n; ++i) r[i]=i;
	}

	int find(int a) {
		if (a==r[a]) return a;
		return r[a]=find(r[a]);
	}

	void unite(int a, int b) {
		a=find(a), b=find(b);
		if (a==b) return;
		if (s[a]<s[b]) swap(a, b);
		s[a]+=s[b]; r[b]=a;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> deg(n+1, 0);
	vector<vector<int>> adj(n+1, vector<int>());
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b); deg[a]++;
		adj[b].push_back(a); deg[b]++;
	}

	vector<int> ord;
	set<pair<int, int>> s;
	for (int i = 1; i <= n; ++i) s.insert({deg[i], i});
	for (int i = 0; i < n; ++i) {
		auto [d, u]=*s.begin();
		s.erase({d, u}); deg[u]=0;
		for (auto v : adj[u]) {
			if (deg[v]==0) continue;
			s.erase({deg[v]--, v});
			s.insert({deg[v], v});
		} ord.push_back(u);
	} reverse(ord.begin(), ord.end());

	int a=0;
	dsu uf(n+1);
	vector<bool> in(n+1, false);
	for (int i = 0; i < n; ++i) {
		int j=ord[i], d=0; in[j]=true;
		for (auto v : adj[j]) {
			if (!in[v]) continue;
			uf.unite(j, v); d++;
		} a=max(a, uf.s[uf.find(j)]*d);
	} cout << a << '\n';

	return 0;
}