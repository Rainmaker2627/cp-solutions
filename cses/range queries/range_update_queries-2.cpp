#include<bits/stdc++.h>
using namespace std;
#define int long long

struct lazy {
	int n;
	vector<int> st, lz;

	lazy(int a) {
		n=a;
		while (n&(n-1)) n++;
		vector<int> b(2*n, 0), c(2*n, 0);
		for (int i = n; i < n+a; ++i) cin >> b[i];
		for (int i = n-1; i > 0; --i) b[i]=b[2*i]+b[2*i+1];
		swap(b, st); swap(lz, c);
	}

	void push(int n) {
		st[n]+=lz[n];
		if (n<this->n) {
			lz[2*n]+=lz[n]/2;
			lz[2*n+1]+=lz[n]/2;
		} lz[n]=0;
	}

	void update(int a, int b, int v, int n=1, int l=1, int r=-1) {
		if (n==1) r=this->n;
		if (r<a || l>b) return;
		if (a<=l && r<=b) { lz[n]+=(r-l+1)*v; return; }
		st[n]+=(min(b, r)-max(a, l)+1)*v;
		update(a, b, v, 2*n, l, (l+r)/2);
		update(a, b, v, 2*n+1, (l+r)/2+1, r);
	}

	int query(int a, int b, int n=1, int l=1, int r=-1) {
		if (n==1) r=this->n;
		push(n);
		if (r<a || l>b) return 0;
		if (a<=l && r<=b) return st[n]+lz[n];
		return query(a, b, 2*n, l, (l+r)/2) + query(a, b, 2*n+1, (l+r)/2+1, r);
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	lazy st(n);
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t==1) {
			int a, b, u;
			cin >> a >> b >> u;
			st.update(a, b, u);
		} else {
			int k;
			cin >> k;
			cout << st.query(k, k) << '\n';
		}
	}

	return 0;
}
