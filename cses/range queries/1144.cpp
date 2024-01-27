#include<bits/stdc++.h>
using namespace std;

struct query {
	int t, a, b;
	query(char x, int y, int z) {
		t=(x=='!'); a=y; b=z;
	}
};

struct segtree {
	int n;
	vector<int> st;
	unordered_map<int, int> m;

	segtree(int a, vector<int>& s, vector<int>& p) {
		int c=0;
		unordered_map<int, int> t; t[p[0]]=c++;
		for (int i = 1; i < p.size(); ++i) {
			if (p[i]==p[i-1]) continue;
			t[p[i]]=c++;
		} swap(m, t);
		while (c&(c-1)) c++;
		n=c; vector<int> b(2*n, 0);
		for (int i = 0; i < s.size(); ++i) b[m[s[i]]+n]++;
		for (int i = n-1; i > 0; --i) b[i]=b[2*i]+b[2*i+1];
		swap(b, st);
	}

	int query(int ql, int qr, int n=1, int nl=1, int nr=-1) {
		if (n==1) { nr=this->n; ql=m[ql]+1; qr=m[qr]+1; }
		if (ql>nr || qr<nl) return 0;
		if (ql<=nl && qr>=nr) return st[n];
		return query(ql, qr, 2*n, nl, (nl+nr)/2) + query(ql, qr, 2*n+1, (nl+nr)/2+1, nr);
	}

	void update(int p, int v) {
		p=m[p]+n; st[p]--;
		for (p/=2; p>0; p/=2) st[p]--;
		p=m[v]+n; st[p]++;
		for (p/=2; p>0; p/=2) st[p]++;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<int> p, s;
	vector<query> a;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		p.push_back(t);
		s.push_back(t);
	}
	for (int i = 0; i < q; ++i) {
		char t;
		int x, y;
		cin >> t >> x >> y;
		query m(t, x, y);
		a.push_back(m);
		p.push_back(y);
		if (t=='?') p.push_back(x);
	} sort(p.begin(), p.end());
	segtree st(n, s, p);

	for (int i = 0; i < q; ++i) {
		if (a[i].t) {
			st.update(s[a[i].a-1], a[i].b);
			s[a[i].a-1]=a[i].b;
		} else {
			cout << st.query(a[i].a, a[i].b) << '\n';
		}
	}

	return 0;
}