#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf=1e9+7;

struct edge {
	int u, v, w;
	bool operator<(edge b) {
		return w>b.w;
	}
};

struct dsu {
	vector<int> p, s;

	dsu(int n) {
		vector<int> a(n+1), b(n+1, 1);
		for (int i = 1; i <= n; ++i) a[i]=i;
		swap(p, a); swap(s, b);
	}

	int find(int u) {
		if (p[u]==u) return u;
		return p[u]=find(p[u]);
	}

	void unite(int a, int b) {
		a=find(a); b=find(b);
		if (s[a]<s[b]) swap(a,b);
		p[b]=a;
		s[a]+=s[b];
	}
};

vector<vector<pair<int, int>>> par, edg;
vector<int> h;

void dfs(int v) {
	for (auto [i, w] : edg[v]) {
		if (par[i][0].first>-1) continue;
		par[i][0]={v, w};
		h[i]=h[v]+1;
		dfs(i);
	}
}

int lca(int a, int b) { // ok
	int m=inf;
	if (h[a]<h[b]) swap(a, b);
	int d=h[a]-h[b];
	for (int i = 31; i >= 0; --i) {
		if (d&(1<<i)) {
			m=min(m, par[a][i].second);
			a=par[a][i].first;
		}
	}

	if (a==b) return m;
	for (int i = 31; i >= 0; --i) {
		if (par[a][i]!=par[b][i]) {
			int t=min(par[b][i].second, par[a][i].second);
			m=min(m, t);
			a=par[a][i].first;
			b=par[b][i].first;
		}
	} m=min(m, min(par[b][0].second, par[a][0].second));
	return m;
}

int main() {
	int n, m;
	cin >> n >> m;
	dsu uf(n);
	vector<edge> e(m);
	for (int i = 0; i < m; ++i) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	} sort(e.begin(), e.end());

	vector<vector<pair<int, int>>> mst(n+1, vector<pair<int, int>>());
	for (edge p : e) {
		if (uf.find(p.u)!=uf.find(p.v)) {
			uf.unite(p.u, p.v);
			mst[p.u].push_back({p.v, p.w});
			mst[p.v].push_back({p.u, p.w});
		}
	}

	vector<vector<pair<int, int>>> b(n+1, vector<pair<int, int>>(32, {-1, inf}));
	swap(b, par); swap(mst, edg);
	h.reserve(n+1);
	for (int i = 1; i <= n; ++i) {
		if (par[i][0].first==-1) {
			h[i]=0; par[i][0]={i, inf};
			dfs(i);
		}
	}
	
	for (int i = 1; i < 32; ++i) {
		for (int j = 1; j <= n; ++j) {
			int p=par[j][i-1].first;
			int q=par[p][i-1].first;
			par[j][i]={q, min(par[j][i-1].second, par[p][i-1].second)};
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}

	return 0;
}