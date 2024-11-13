#include<bits/stdc++.h>
using namespace std;
#define int long long
 
struct segtree {
	int n;
	vector<int> st;
 
	segtree(int a, vector<int>& v) {
		n=a;
		st.assign(2*n, 0);
		for (int i = n; i < 2*n; ++i) st[i]=v[i-n];
		for (int i = n-1; i > 0; --i) st[i]=st[2*i]+st[2*i+1];
	}
 
	int query(int a, int b) {
		int s=0;
		a+=n-1; b+=n-1;
		while (a<=b) {
			if (a%2==1) s+=st[a++];
			if (b%2==0) s+=st[b--];
			a/=2; b/=2;
		} return s;
	}
 
	void update(int p, int v) {
		for (st[p+=n-1]=v; p>1; p/=2) st[p/2]=st[p]+st[p^1];
	}
};
 
signed main() {
	cin.tie(0)->sync_with_stdio(false);
 
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	segtree st(n, v);
 
	int t, a, b;
	for (int i = 0; i < q; ++i) {
		cin >> t >> a >> b;
		if (t==1) st.update(a, b);
		else cout << st.query(a, b) << '\n';
	}
 
	return 0;
}