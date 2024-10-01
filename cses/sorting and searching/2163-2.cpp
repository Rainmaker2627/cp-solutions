#include<bits/stdc++.h>
using namespace std;

struct segtree {
	int n;
	vector<int> st;

	segtree(int a) {
		n=a;
		while (n&(n-1)) n++;
		st.assign(2*n, 1);
		for (int i = n-1; i > 0; --i) st[i]=st[2*i]+st[2*i+1];
	}

	int query(int k, int v=1) {
		if (v>=n) { update(v); return v-n; }
		if (st[2*v]>k) return query(k, 2*v);
		return query(k-st[2*v], 2*v+1);
	}

	void update(int p) {
		for (st[p]=0; p>1; p/=2) st[p/2]=st[p]+st[p^1];
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k, p=0;
	cin >> n >> k;
	segtree st(n+1);
	while (n) {
		p=(p+k)%n--;
		cout << st.query(p+1) << " \n"[n==0];
	}

	return 0;
}