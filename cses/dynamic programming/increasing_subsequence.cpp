#include<bits/stdc++.h>
using namespace std;

struct segtree {
	int n;
	vector<int> st;
	unordered_map<int, int> c;

	segtree(int a, vector<int>& x) {
		n=a; int t=2;
		while (n&(n-1)) n++;
		vector<int> b(2*n, 0);
		swap(st, b);
		c[x[0]]=1;
		for (int i = 1; i < x.size(); ++i) {
			if (x[i]==x[i-1]) continue;
			else c[x[i]]=t++;
		}
	}

	int update(int u, int v) {
		u=c[u]+n; st[u]=v;
		for (u/=2; u>0; u/=2) st[u]=max(st[u], v);
		return v;
	}

	int query(int ql, int qr, int v=1, int nl=1, int nr=-1) {
		if (nr==-1) { nr=this->n; ql++; qr=c[qr]; }
		if (nr<ql || nl>qr) return 0;
		if (nl>=ql && nr<=qr) return st[v];
		return max(query(ql, qr, 2*v, nl, (nl+nr)/2), query(ql, qr, 2*v+1, (nl+nr)/2+1, nr));
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		y[i]=x[i];
	} sort(y.begin(), y.end());
	segtree st(n, y);

	int m=0;
	for (int i = 0; i < n; ++i) {
		m=max(m, st.update(x[i], st.query(0, x[i])+1));
	}

	cout << m << '\n';
	return 0;
}