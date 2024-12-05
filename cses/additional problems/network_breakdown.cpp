#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;

struct dsu {
	int n, m;
	vector<int> s, r;

	dsu(int n) {
		this->n=m=n;
		s.reserve(n+1);
		r.reserve(n+1);
		for (int i = 1; i <= n; ++i) s[i]=1, r[i]=i;
	}

	int find(int a) {
		if (r[a]==a) return a;
		return r[a]=find(r[a]);
	}

	bool unite(int a, int b) {
		a=find(a), b=find(b);
		if (a==b) return false;
		if (s[a]<s[b]) swap(a, b);
		r[b]=a; s[a]+=s[b]; m--;
		return true;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	set<pair<int, pair<int, int>>> adj;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		if (a>b) swap(a, b);
		adj.insert({inf, {a, b}});
	}

	for (int i = 1; i <= k; ++i) {
		int a, b;
		cin >> a >> b;
		if (a>b) swap(a, b);
		adj.erase({inf, {a, b}});
		adj.insert({i, {a, b}});
	}

	dsu uf(n);
	vector<int> x;
	auto p=prev(adj.end());
	while (p!=adj.begin()) {
		auto [w, t]=*p;
		auto [a, b]=t;
		if (uf.unite(a, b)) x.push_back(w);
		p--;
	}

	int c=uf.m;
	reverse(x.begin(), x.end());
	x.push_back(inf);
	for (int i = 1, j = 0; i <= k; ++i) {
		if (i==x[j]) { j++; c++; }
		cout << c << ' ';
	} cout << '\n';

	return 0;
}