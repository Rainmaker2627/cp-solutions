#include<bits/stdc++.h>
using namespace std;
#define int long long

struct road {
	int a, b, g;
	road(int w, int x, int y, int z) { a=w; b=x; g=y-z; }
	bool operator<(road t) { return g<t.g; }
};

struct dsu {
	int n, c;
	vector<int> p, s;

	dsu(int n) {
		this->n=n; c=n;
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
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m, p, c, s=0;
	cin >> n >> m >> p >> c;
	dsu uf(n);
	vector<road> e;
	vector<int> g(p);
	for (int i = 0; i < p; ++i) cin >> g[i];
	for (int i = 0; i < m; ++i) {
		int a, b, d, r;
		cin >> a >> b >> d >> r;
		if (r<=d) {
			s+=r;
			uf.unite(a, b);
		} else {
			s+=d;
			e.emplace_back(a,b,r,d);
		}
	}

	int i = 0;
	sort(e.begin(), e.end());
	for (; i < e.size(); ++i) {
		auto j = e[i];
		if (uf.find(j.a)==uf.find(j.b)) continue;
		if (j.g<=c) {
			s+=j.g;
			uf.unite(j.a, j.b);
		} else break;
	}

	set<int> t;
	for (int j = 0; j < p; ++j) t.insert(uf.find(g[j]));
	for (auto j = next(t.begin()); j != t.end(); ++j, s+=c) uf.unite(*j, *prev(j));

	for (; i < e.size(); ++i) {
		auto j = e[i];
		if (uf.find(j.a)==uf.find(j.b)) continue;
		uf.unite(j.a, j.b); s+=j.g;
	}

	cout << s << '\n';

	return 0;
}