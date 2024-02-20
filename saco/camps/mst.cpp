#include<bits/stdc++.h>
using namespace std;

struct edge {
	int u, v, w;
	bool operator<(edge b) {
		return w<b.w;
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

int main() {
	int n, m;
	cin >> n >> m;
	dsu uf(n);
	vector<edge> e(m);
	for (int i = 0; i < m; ++i) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	} sort(e.begin(), e.end());

	long long s=0;
	for (edge p : e) {
		if (uf.find(p.u)!=uf.find(p.v)) {
			s+=p.w;
			uf.unite(p.u, p.v);
		}
	} cout << s << '\n';
	return 0;
}