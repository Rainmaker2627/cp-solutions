#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct edge {
	int u, v, w;
};

struct dsu {
	vector<int> p, s;

	void set(int n) {
		p.reserve(n+1); s.assign(n+1, 1);
		for (int i = 1; i <= n; ++i) p[i]=i;
	}

	int find(int a) {
		if (a==p[a]) return a;
		return p[a]=find(p[a]);
	}

	void unite(int a, int b) {
		a=find(a), b=find(b);
		if (s[a]<s[b]) swap(a, b);
		p[b]=a; s[a]+=s[b];
	}
} uf;

const int inf=1e9+7;
vector<vector<pii>> sp, t;
vector<edge> e;
vector<int> h;
int n, m, q, l;

void dfs(int u) {
	for (auto [v, w] : t[u]) {
		if (h[v]) continue;
		sp[0][v]={u, w};
		h[v]=h[u]+1;
		dfs(v);
	}
}

int lca(int a, int b) {
	if (uf.find(a)!=uf.find(b)) return -1;

	int m=0;
	if (h[a]<h[b]) swap(a, b);
	int d=h[a]-h[b];
	for (int i = l-1; i >= 0; --i) {
		if (d&(1<<i)) {
			m=max(sp[i][a].second, m);
			a=sp[i][a].first;
		}
	}

	if (a==b) return m;
	for (int i = l-1; i >= 0; --i) {
		if (sp[i][a].first==sp[i][b].first) continue;
		m=max(sp[i][a].second, m); m=max(sp[i][b].second, m);
		a=sp[i][a].first; b=sp[i][b].first;
	} m=max(m, max(sp[0][a].second, sp[0][b].second));
	return m;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m >> q;
	e.assign(m, edge());
	for (int i = 0; i < m; ++i) {
		cin >> e[i].u >> e[i].v;
		e[i].w=i+1;
	}

	uf.set(n);
	t.assign(n+1, vector<pii>());
	for (auto i : e) {
		if (uf.find(i.u)==uf.find(i.v)) continue;
		uf.unite(i.u, i.v);
		t[i.u].push_back({i.v, i.w});
		t[i.v].push_back({i.u, i.w});
	}

	l=0;
	while (n>=(1<<l)) l++;
	sp.assign(l, vector<pii>(n+1, {0, 0}));
	h.assign(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		if (!h[i]) {
			sp[0][i]={i, 0};
			h[i]=1;
			dfs(i);
		}
	}

	for (int i = 1; i < l; ++i) {
		for (int j = 1; j <= n; ++j) {
			auto [a, b]=sp[i-1][j];
			auto [c, d]=sp[i-1][a];
			sp[i][j]={c, max(b, d)};
		}
	}

	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}

	return 0;
}