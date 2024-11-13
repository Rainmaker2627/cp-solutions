#include<bits/stdc++.h>
using namespace std;

struct segtree {
	int n;
	vector<int> s, m;

	segtree(int a) {
		n=a;
		while (n&(n-1)) n++;
		s.assign(2*n, 0);
		m.assign(2*n, 0);
	}

	bool query() {
		return m[1]>0;
	}

	void update(int p, int v, int n=1, int nl=1, int nr=1) {
		if (n==1) nr=this->n;
		if (nr<p || p<nl) return;
		if (nl==nr) { s[n]=m[n]=v; return; }
		update(p, v, 2*n, nl, (nl+nr)/2);
		update(p, v, 2*n+1, (nl+nr)/2+1, nr);
		s[n]=s[2*n]+s[2*n+1];
		m[n]=max(m[2*n+1], m[2*n]+s[2*n+1]);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	segtree l(n), r(n);
	for (int i = 0; i < n; ++i) {
		int c, s;
		cin >> c >> s;
		int v=(s==1?1:-1);
		l.update(c, v);
		r.update(c, -v);
		bool a=l.query(), b=r.query();
		if (a) {
			if (b) cout << "?\n";
			else cout << ">\n";
		} else {
			cout << "<\n";
		}
	}

	return 0;
}