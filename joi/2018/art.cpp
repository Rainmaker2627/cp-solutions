#include<bits/stdc++.h>
using namespace std;
#define int long long

struct segtree {
	int n;
	vector<int> sum, pre;

	segtree(vector<int>& a) {
		n=a.size();
		while (n&(n-1)) n++;
		sum.assign(2*n, 0); pre.assign(2*n, 0);
		for (int i = n; i < n+a.size(); ++i) pre[i]=sum[i]=a[i-n];
		for (int i = n-1; i > 0; --i) {
			sum[i]=sum[2*i]+sum[2*i+1];
			pre[i]=max(pre[2*i], sum[2*i]+pre[2*i+1]);
		}
	}

	pair<int, int> query(int ql, int qr, int v=1, int nl=1, int nr=-1) {
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

vector<int> a, b, p;
bool acomp(int x, int y) { return a[x]<a[y]; }

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m=0;
	cin >> n;
	a.assign(n, 1);
	b.assign(n, 1);
	p.assign(n, 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		m=max(m, b[i]);
		p[i]=i;
	} sort(p.begin(), p.end(), acomp);

	vector<int> c(n); c[0]=a[0];
	for (int i = 1; i < n; ++i) {
		c[i]=b[p[i]]-a[p[i]]+a[p[i-1]];
	} segtree st(c);

	for (int i = 0; i < n-1; ++i) {
		m=max(m, b[p[i]]+st.query(i+2, n).second);
	} cout << m << '\n';

	return 0;
}