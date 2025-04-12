#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

struct dsu {
	int n;
	vector<int> r, s;

	dsu(int n) {
		this->n=n;
		r.reserve(n+1);
		for (int i = 1; i <= n; ++i) r[i]=i;
		s.assign(n+1, 1);
	}

	int find(int a) {
		if (a==r[a]) return a;
		return r[a]=find(r[a]);
	}

	void unite(int a, int b) {
		a=find(a), b=find(b);
		if (a==b) return;
		if (s[a]<s[b]) swap(a, b);
		r[b]=a; s[a]+=s[b];
	}
};

struct query {
	int s, c, i;
	query(int _s, int _c, int _i) { s=_s, c=_c, i=_i; }
	bool operator<(query b) { return c<b.c; }
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 0; i < n-1; ++i) {
		int u, v, d;
		cin >> u >> v >> d;
		pq.push({-d, {u, v}});
	}

	vector<query> Q;
	for (int i = 0; i < q; ++i) {
		int c, s;
		cin >> c >> s;
		Q.emplace_back(s, c, i);
	} sort(Q.begin(), Q.end());

	dsu uf(n);
	vector<int> ans(q);
	for (int i = 0; i < q; ++i) {
		while (!pq.empty() && -pq.top().fi<=Q[i].c) {
			auto [u, v] = pq.top().se;
			uf.unite(u, v);
			pq.pop();
		} ans[Q[i].i]=uf.s[uf.find(Q[i].s)];
	}

	for (int i = 0; i < q; ++i) {
		cout << ans[i]-1 << '\n';
	}

	return 0;
}