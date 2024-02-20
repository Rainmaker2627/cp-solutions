#include<bits/stdc++.h>
using namespace std;

struct segtree {
	int n;
	vector<int> st;

	segtree(int a, vector<int>& u) {
		n=a;
		while (n&(n-1)) n++;
		st.assign(2*n, 0);
		for (int i = n; i < n+a; ++i) st[i]=u[i-n];
		for (int i = n-1; i > 0; --i) st[i]=st[2*i]+st[2*i+1];
	}

	void update(int a, int v) {
		if (a==-1) return;
		st[a+=n-1]=v;
		for (a/=2; a>0; a/=2) st[a]=st[2*a]+st[2*a+1];
	}

	int query(int a, int b, int n=1, int l=1, int r=-1) {
		if (n==1) r=this->n;
		if (r<a || b<l) return 0;
		if (a<=l && r<=b) return st[n];
		return query(a, b, 2*n, l, (l+r)/2)+query(a, b, 2*n+1, (l+r)/2+1, r);
	}
};

struct query {
	int a, b, i;
	bool operator<(query s) {
		return a<s.a;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<int> a(n), f(n+1,-1), u(n, 1);
	unordered_map<int, int> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (m.count(a[i])) {
			f[m[a[i]]+1]=i+1; u[i]=0;
		} m[a[i]]=i;
	}

	vector<query> r(q);
	for (int i = 0; i < q; ++i) {
		cin >> r[i].a >> r[i].b;
		r[i].i=i;
	} sort(r.begin(), r.end());

	int p=1;
	segtree st(n, u);
	vector<int> ans(q);
	for (auto q : r) {
		int a=q.a, b=q.b;
		for (; p<a; p++) st.update(f[p], 1);
		ans[q.i]=st.query(a, b);
	}

	for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
	return 0;
}