#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf=1e18;

struct segtree {
	int n;
	vector<int> st;

	segtree(vector<int>& v) {
		n=v.size()-1;
		while (n&(n-1)) n++;
		st.assign(2*n, -inf);
		for (int i = n; i < n+v.size()-1; ++i) st[i]=v[i-n+1];
		for (int i = n-1; i > 0; --i) st[i]=max(st[2*i], st[2*i+1]);
	}

	int query(int a, int b, int v=1, int l=1, int r=-1) {
		if (v==1) r=n;
		if (r<a || b<l) return -inf;
		if (a<=l && r<=b) return st[v];
		return max(query(a, b, 2*v, l, (l+r)/2), query(a, b, 2*v+1, (l+r)/2+1, r));
	}

	void print() {
		for (int i = 1; i < 2*n; ++i) {
			cout << st[i] << ' ';
		} cout << '\n';
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, a, b;
	cin >> n >> a >> b;
	vector<int> x(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> x[i]; x[i]+=x[i-1];
	} segtree st(x);

	int m=-inf;
	for (int i = 1; i <= n-a+1; ++i) {
		m=max(st.query(i+a-1, min(i+b-1, n))-x[i-1], m);
	} cout << m << '\n';

	return 0;
}