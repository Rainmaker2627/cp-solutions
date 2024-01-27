#include<bits/stdc++.h>
using namespace std;
#define int long long

struct lazy {
	int n;
	vector<int> st, lza, lzd;

	lazy(int a) {
		n=a;
		while (n&(n-1)) n++;
		vector<int> b(2*n), c(2*n, 0), d(2*n, 0);
		for (int i = n; i < n+a; ++i) cin >> b[i];
		for (int i = n-1; i > 0; --i) b[i]=b[2*i]+b[2*i+1];
		swap(b, st); swap(c, lza); swap(d, lzd);
	}

	int calc(int a, int d, int n) {
		return n*(2*a+(n-1)*d)/2;
	}

	void push(int n, int l, int r) {
		st[n]+=calc(lza[n], lzd[n], r-l+1);
		if (n<this->n) {
			lza[2*n]+=lza[n]; lzd[2*n]+=lzd[n];
			lza[2*n+1]+=lza[n]+((r-l)/2+1)*lzd[n]; lzd[2*n+1]+=lzd[n];
		} lza[n]=lzd[n]=0;
	}

	void update(int a, int b, int n=1, int l=1, int r=-1) {
		if (n==1) r=this->n;
		push(n, l, r);
		if (r<a || l>b) return;
		if (a<=l && r<=b) {
			lza[n]+=l-a+1; lzd[n]++; push(n, l, r);
			return;
		} else st[n]+=calc(max(l, a)-a+1, 1, min(b, r)-max(l, a)+1);
		update(a, b, 2*n, l, (l+r)/2);
		update(a, b, 2*n+1, (l+r)/2+1, r);
	}

	int query(int a, int b, int n=1, int l=1, int r=-1) {
		if (n==1) r=this->n;
		push(n, l, r);
		if (r<a || l>b) return 0;
		if (a<=l && r<=b) return st[n];
		return query(a, b, 2*n, l, (l+r)/2)+query(a, b, 2*n+1, (l+r)/2+1, r);
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q, t, a, b;
	cin >> n >> q;
	lazy st(n);
	for (int i = 0; i < q; ++i) {
		cin >> t >> a >> b;
		if (t==1) st.update(a, b);
		else cout << st.query(a, b) << '\n';
	}

	return 0;
}