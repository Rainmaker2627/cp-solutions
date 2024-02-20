#include <bits/stdc++.h>
using namespace std;

struct segtree {
	int n;
	vector<int> st;

	segtree(int a) {
		n=a;
		while (n&(n-1)) n++;
		vector<int> b(2*n,0);
		swap(st, b);
	}

	int query(int ql, int qr, int n=1, int nl=1, int nr=-1) {
		if (nr==-1) nr=this->n;
		if (nr<ql || nl>qr) return 0;
		if (nr<=qr && nl>=ql) return st[n];
		return max(query(ql, qr, 2*n, nl, (nl+nr)/2), query(ql, qr, 2*n+1, (nl+nr)/2+1, nr));
	}

	void update(int p, int k) {
		p+=n-1; st[p]=k;
		for (p/=2; p>0; p/=2) st[p]=max(st[2*p],st[2*p+1]);
	}
};

int main() {
	int n, q;
	cin >> n >> q;
	segtree st(n);
	for (int i = 0; i < q; ++i) {
		char c;
		int a, b;
		cin >> c >> a >> b;
		if (c=='U') {
			st.update(a+1, b);
		} else {
			cout << st.query(a+1, b+1) << '\n';
		}
	}
	return 0;
}