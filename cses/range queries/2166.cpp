#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e18;

struct segtree {
	int n;
	vector<ll> sum, pre;

	segtree(int a) {
		n=a;
		while (n&(n-1)) n++;
		vector<ll> b(2*n), c(2*n);
		for (int i = n; i < n+a; ++i) {
			cin >> b[i];
			c[i]=b[i];
		} for (int i = n-1; i > 0; --i) {
			b[i]=b[2*i]+b[2*i+1];
			c[i]=max(c[2*i], b[2*i]+c[2*i+1]);
		} swap(sum, b); swap(pre, c);
	}

	pair<ll, ll> query(int ql, int qr, int v=1, int nl=1, int nr=-1) {
		if (v==1) nr=n;
		if (ql>nr || qr<nl) return {0, 0};
		if (ql<=nl && nr<=qr) return {sum[v], pre[v]};
		auto [s1, p1] = query(ql, qr, 2*v, nl, (nl+nr)/2); 
		auto [s2, p2] = query(ql, qr, 2*v+1, (nl+nr)/2+1, nr);
		return {s1+s2, max(p1, s1+p2)};
	}

	void update(int u, int v) {
		u+=n-1;
		sum[u]=pre[u]=v;
		for (u/=2; u>0; u/=2) {
			sum[u]=sum[2*u]+sum[2*u+1];
			pre[u]=max(pre[2*u], sum[2*u]+pre[2*u+1]);
		}
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	segtree st(n);

	for (int i = 0; i < q; ++i) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t==1) st.update(a, b);
		else cout << max((ll) 0, st.query(a, b).second) << '\n';
	}

	return 0;
}