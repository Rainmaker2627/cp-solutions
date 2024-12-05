#include<bits/stdc++.h>
using namespace std;
#define int long long

struct segtree {
	int n;
	vector<int> st;

	segtree(vector<int>& v) {
		n=v.size();
		while (n&(n-1)) n++;
		st.assign(2*n, 0);
	}

	void update(int p, int n=1, int nl=1, int nr=1) {
		if (n==1) nr=this->n;
		if (nr<p || p<nl) return;
		if (nl==nr) { st[n]++; return; }
		update(p, 2*n, nl, (nl+nr)/2);
		update(p, 2*n+1, (nl+nr)/2+1, nr);
		st[n]++;
	}

	int query(int a, int b, int n=1, int nl=1, int nr=1) {
		if (n==1) nr=this->n;
		if (nr<a || b<nl) return 0;
		if (a<=nl && nr<=b) return st[n];
		return query(a, b, 2*n, nl, (nl+nr)/2) + query(a, b, 2*n+1, (nl+nr)/2+1, nr);
	}
};

vector<int> v, s;
bool scomp(int a, int b) { return v[a]<v[b]; }

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	v.reserve(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		s.push_back(i);
	} sort(s.begin(), s.end(), scomp);

	int m=0;
	segtree st(s);
	for (int i = 0; i < n; ++i) {
		m+=min(s[i]-st.query(1, s[i]+1), n-s[i]-1-st.query(s[i]+1, n));
		st.update(s[i]+1);
	} cout << m << '\n';

	return 0;
}