#include<bits/stdc++.h>
using namespace std;

struct segtree {
	int n;
	vector<int> st;

	segtree(int a) {
		n=a;
		while (n&(n-1)) n++;
		vector<int> b(2*n, 1);
		for (int i = n-1; i > 0; --i) b[i]=b[2*i]+b[2*i+1];
		swap(b, st);
	}

	int query(int v, int n=1, int nl=1, int nr=-1) {
		if (n==1) nr=this->n;
		if (nl==nr) return n;
		if (st[2*n]>=v) return query(v, 2*n, nl, (nr+nl)/2);
		else return query(v-st[2*n], 2*n+1, (nr+nl)/2+1, nr);
	}

	void remove(int v) {
		v+=n; st[v]=0;
		for (v/=2; v>0; v/=2) st[v]--; 
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	} segtree st(n);

	for (int i = 0; i < n; ++i) {
		cin >> k;
		int r=st.query(k)-st.n;
		cout << a[r] << ' ';
		st.remove(r);
	}

	return 0;
}