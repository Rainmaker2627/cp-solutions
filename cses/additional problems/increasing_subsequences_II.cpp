#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

struct segtree {
	int n;
	vector<int> st;
	map<int, int> m;

	segtree(vector<int> v) {
		sort(v.begin(), v.end()); m[v[0]]=1;
		for (int i = 1, j = 1; i < v.size(); ++i) {
			if (v[i]==v[i-1]) continue;
			m[v[i]]=++j;
		} n=m.size();
		while (n&(n-1)) n++;
		st.assign(2*n, 0);
	}

	void update(int p, int v, int n=1, int nl=1, int nr=1) {
		if (n==1) { nr=this->n; p=m[p]; }
		if (nr<p || p<nl) return;
		if (nl==nr) { st[n]=(st[n]+v)%mod; return; }
		update(p, v, 2*n, nl, (nl+nr)/2);
		update(p, v, 2*n+1, (nl+nr)/2+1, nr);
		st[n]=(st[n]+v)%mod;
	}

	int query(int a, int b, int n=1, int nl=1, int nr=1) {
		if (n==1) { nr=this->n; b=m[b]-1; }
		if (nr<a || b<nl) return 0;
		if (a<=nl && nr<=b) return st[n];
		return (query(a, b, 2*n, nl, (nl+nr)/2) + query(a, b, 2*n+1, (nl+nr)/2+1, nr))%mod;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	int m=0;
	segtree st(v);
	for (int i = 0; i < n; ++i) {
		int q=st.query(1, v[i])+1;
		st.update(v[i], q);
		m=(m+q)%mod;
	} cout << m << '\n';

	return 0;
}