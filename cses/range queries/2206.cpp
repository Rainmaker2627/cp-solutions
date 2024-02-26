#include<bits/stdc++.h>
using namespace std;

const int inf=2e9;

struct segtree {
	int n, t;
	vector<int> st;

	segtree(int a, int t, vector<int>& p) {
		n=a; this->t=t;
		while (n&(n-1)) n++;
		st.assign(2*n, 0);
		for (int i = n; i < n+a; ++i) st[i]=p[i-n]+t*(i+1-n);
		for (int i = n-1; i > 0; --i) st[i]=min(st[2*i], st[2*i+1]);
	}

	int query(int a, int b, int n=1, int l=1, int r=-1) {
		if (n==1) r=this->n;
		if (r<a || l>b) return inf;
		if (a<=l && r<=b) return st[n];
		return min(query(a,b,2*n,l,(l+r)/2), query(a,b,2*n+1,(l+r)/2+1,r));
	}

	void update(int a, int v) {
		a+=n-1; st[a]=v+t*(a+1-n);
		for (a/=2; a>0; a/=2) st[a]=min(st[2*a], st[2*a+1]);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<int> p(n);
	for (int i = 0; i < n; ++i) cin >> p[i];

	segtree a(n, 1, p), b(n, -1, p);
	for (int i = 0; i < q; ++i) {
		int t, k, x;
		cin >> t >> k;
		if (t==1) {
			cin >> x;
			a.update(k, x);
			b.update(k, x);
		} else {
			cout << min(a.query(k, n)-k, b.query(1, k)+k) << '\n';
		}
	}

	return 0;
} 