#include<bits/stdc++.h>
using namespace std;

struct dsu {
	int n;
	vector<int> s, r;

	dsu(int n) {
		this->n=n;
		s.reserve(n+1);
		r.reserve(n+1);
		for (int i = 1; i <= n; ++i) s[i]=1, r[i]=i;
	}

	int find(int a) {
		if (r[a]==a) return a;
		return r[a]=find(r[a]);
	}

	void unite(int a, int b) {
		a=find(a), b=find(b);
		if (s[a]<s[b]) swap(a, b);
		r[b]=a; s[a]+=s[b];
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	dsu uf(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		uf.unite(a, b);
	}

	vector<bool> v(n+1, false);
	bitset<100001> bs;
	bs[0]=1;
	for (int i = 1; i <= n; ++i) {
		int r=uf.find(i);
		if (v[r]) continue;
		bs|=bs<<uf.s[r];
		v[r]=true;
	}

	for (int i = 1; i <= n; ++i) cout << bs[i];
	cout << '\n';

	return 0;
}