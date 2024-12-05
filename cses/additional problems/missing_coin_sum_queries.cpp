#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf=1e18;
vector<int> x;

struct segtree {
	int n=0, l=0;
	vector<int> id;
	vector<int> m, s;

	void push(int i) {
		id.push_back(i);
		n++;
	}

	void build() {
		while (n&(n-1)) n++;
		m.assign(2*n,  inf);
		s.assign(2*n, 0);
		for (int i = n; i < n+id.size(); ++i) m[i]=s[i]=x[id[i-n]];
		for (int i = n-1; i > 0; --i) {
			m[i]=min(m[2*i], m[2*i+1]);
			s[i]=s[2*i]+s[2*i+1];
		}
	}

	pair<int, int> query(int a, int b=-1, int n=1, int nl=1, int nr=-1) {
		if (n==1) {
			b=lower_bound(id.begin(), id.end(), a)-id.begin();
			nr=this->n; a=l+1;
		}
		if (nr<a || b<nl) return {inf, 0};
		if (a<=nl && nr<=b) return {m[n], s[n]};
		auto p=query(a, b, 2*n, nl, (nl+nr)/2);
		auto q=query(a, b, 2*n+1, (nl+nr)/2+1, nr);
		return {min(p.first, q.first), p.second+q.second};
	}

	void pop() { l++; }
};

struct query {
	int a, b, id;

	bool operator<(query t) { return a<t.a; }
};

int lg(int a) {
	int lg=0;
	while ((1<<lg)<=a) lg++;
	return lg-1;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	x.reserve(n);
	vector<segtree> st(30);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		st[lg(x[i])].push(i);
	}
	for (int i = 0; i < 30; ++i) st[i].build();

	vector<query> v;
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b, i});
	} sort(v.begin(), v.end());

	int l=0;
	vector<int> ans(q, 0);
	for (int i = 0; i < q; ++i) {
		int a=v[i].a, b=v[i].b, c=0;
		while (l+1<a) st[lg(x[l++])].pop();
		for (int j = 0; j < 30; ++j) {
			auto [m, s]=st[j].query(b);
			if (m<inf && m>c+1) break;
			else c+=s;
		} ans[v[i].id]=c+1;
	}

	for (int i = 0; i < q; ++i) {
		cout << ans[i] << '\n';
	}

	return 0;
}