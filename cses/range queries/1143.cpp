#include<bits/stdc++.h>
using namespace std;

struct segtree {
	int n;
	vector<int> st;

	segtree(int a) {
		n=a;
		while (n&(n-1)) n++;
		vector<int> b(2*n, 0);
		for (int i = n; i < n+a; ++i) cin >> b[i];
		for (int i = n-1; i > 0; --i) b[i]=max(b[2*i], b[2*i+1]);
		swap(st, b);
	}

	int query(int v, int n=1, int nl=1, int nr=-1) {
		if (n==1) {
			nr=this->n;
			if (st[1]<v) return 0;
		}
		if (nl==nr) return n;
		if (st[2*n]>=v) return query(v, 2*n, nl, (nl+nr)/2);
		else return query(v, 2*n+1, (nl+nr)/2+1, nr);
		return 0;
	}

	void update(int p, int v) {
		if (p==0) return;
		p+=n-1; st[p]-=v;
		for (p/=2; p>0; p/=2) st[p]=max(st[2*p], st[2*p+1]);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m, s;
	cin >> n >> m;
	segtree st(n);

	for (int i = 0; i < m; ++i) {
		cin >> s;
		int r = max(st.query(s)-st.n+1, 0);
		st.update(r, s);
		cout << r << ' ';
	}

	return 0;
}