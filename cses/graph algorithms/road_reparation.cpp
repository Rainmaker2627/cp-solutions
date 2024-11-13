#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct dsu {
	vector<int> rep, s;
	int cc;

	dsu(int n) {
		cc=n;
		vector<int> a(n+1), b(n+1, 1);
		for (int i = 1; i <= n; ++i) a[i]=i;
		swap(a, rep); swap(b, s);
	}

	int find(int a) {
		if (a==rep[a]) return a;
		return rep[a]=find(rep[a]);
	}

	void unite(int a, int b) {
		a=find(a), b=find(b);
		if (s[a]<s[b]) swap(a, b);
		rep[b]=a; s[a]+=s[b]; cc--;
	}
};

struct edge {
	int a, b, c;
	bool operator<(edge x) {
		return c<x.c;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	dsu uf(n);
	vector<edge> e(m);
	for (int i = 0; i < m; ++i) {
		cin >> e[i].a >> e[i].b >> e[i].c;
	} sort(e.begin(), e.end());

	ll s=0;
	for (int i = 0; i < m; ++i) {
		int a=e[i].a, b=e[i].b, c=e[i].c;
		if (uf.find(a)==uf.find(b)) continue;
		uf.unite(a, b);
		s+=c;
	}

	if (uf.cc==1) cout << s << '\n';
	else cout << "IMPOSSIBLE\n";

	return 0;
}