#include<bits/stdc++.h>
using namespace std;

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

	return 0;
}