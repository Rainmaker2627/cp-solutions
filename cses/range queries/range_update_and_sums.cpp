#include<bits/stdc++.h>
using namespace std;
#define int long long

struct lazy {
	int n;
	vector<int> st, lza, lzs;

	lazy(int a) {
		n=a;
		while (n&(n-1)) n++;
		vector<int> b(2*n), c(2*n, 0), d(2*n, 0);
		for (int i = n; i < n+a; ++i) cin >> b[i];
		for (int i = n-1; i > 0; --i) b[i]=b[2*i]+b[2*i+1];
		swap(st, b); swap(lza, c); swap(lzs, d);
	}

	void push(int n, int l, int r) {
		if (lzs[n]) {
			st[n]=(r-l+1)*(lzs[n]+lza[n]);
			if (n<this->n) {
				lzs[2*n]=lzs[2*n+1]=lzs[n]+lza[n];
				lza[2*n]=lza[2*n+1]=0;
			} lzs[n]=lza[n]=0;
		} else {
			st[n]+=(r-l+1)*lza[n];
			if (n<this->n) {
				lza[2*n]+=lza[n];
				lza[2*n+1]+=lza[n];
			} lza[n]=0;
		}
	}

	void add(int a, int b, int v, int n=1, int l=1, int r=-1) {
		if (n==1) r=this->n;
		push(n, l, r);
		if (r<a || b<l) return;
		if (a<=l && r<=b) { lza[n]+=v; push(n, l, r); return; }
		st[n]+=(min(b, r)-max(a, l)+1)*v;
		add(a, b, v, 2*n, l, (l+r)/2);
		add(a, b, v, 2*n+1, (l+r)/2+1, r);
	}

	void set(int a, int b, int v, int n=1, int l=1, int r=-1) {
		if (n==1) r=this->n;
		push(n, l, r);
		if (r<a || b<l) return;
		if (a<=l && r<=b) { lzs[n]=v; lza[n]=0; push(n, l, r); return; }
		set(a, b, v, 2*n, l, (l+r)/2);
		set(a, b, v, 2*n+1, (l+r)/2+1, r);
		st[n]=st[2*n]+st[2*n+1];
	}

	int query(int a, int b, int n=1, int l=1, int r=-1) {
		if (n==1) r=this->n;
		push(n, l, r);
		if (r<a || b<l) return 0;
		if (a<=l && r<=b) return st[n];
		return query(a, b, 2*n, l, (l+r)/2) + query(a, b, 2*n+1, (l+r)/2+1, r);
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q, t, a, b, x;
	cin >> n >> q;
	lazy st(n);
	for (int i = 0; i < q; ++i) {
		cin >> t >> a >> b;
		if (t==1 || t==2) cin >> x;
		if (t==1) st.add(a, b, x);
		else if (t==2) st.set(a, b, x);
		else cout << st.query(a, b) << '\n';
	}

	return 0;
}