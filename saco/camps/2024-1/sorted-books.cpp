#include <bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;

struct segtree {
	int n;
	vector<ll> st;

	segtree(int a) {
		n=a;
		while (n&(n-1)) n++;
		vector<ll> b(2*n,0);
		swap(st, b);
	}

	ll query(int ql, int qr, int n=1, int nl=1, int nr=-1) {
		if (nr==-1) nr=this->n;
		if (nr<ql || nl>qr) return 0;
		if (nr<=qr && nl>=ql) return st[n];
		return query(ql, qr, 2*n, nl, (nl+nr)/2)+query(ql, qr, 2*n+1, (nl+nr)/2+1, nr);
	}

	void update(int p, int k) {
		p+=n-1; st[p]+=k;
		for (p/=2; p>0; p/=2) st[p]=st[2*p]+st[2*p+1];
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> h(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		b[i]=h[i];
	} sort(b.begin(), b.end());

	segtree st(n);
	indexed_set s;
	ll c=0;
	for (int i = 0; i < n; ++i) {
		auto t=s.order_of_key(h[i]);
		int k=lower_bound(b.begin(), b.end(), h[i])-b.begin();
		st.update(k+1, i-t);
		s.insert(h[i]);
		c+=st.query(k+2, n);
	} cout << c << '\n';
	return 0;
}