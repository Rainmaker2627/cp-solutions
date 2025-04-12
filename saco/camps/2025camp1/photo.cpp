#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf=1e18;

struct segtree {
	int n, t;
	vector<int> st;
	map<int, int> m;
 
	segtree(vector<pair<int, int>>& v, map<int, int>& _m, int _t) {
		m=_m; n=m.size(); t=_t;
		while (n&(n-1)) n++;
		st.assign(2*n, 0);
		for (int i = 0; i < v.size(); ++i) {
			if (v[i].second<0) continue;
			st[m[v[i].first]+n-1]+=(_t?v[i].first:1);
		}
		for (int i = n-1; i > 0; --i) st[i]+=st[2*i]+st[2*i+1];
	}
 
	void update(int p, int v, int n=1, int nl=1, int nr=1) {
		if (n==1) nr=this->n;
		if (nr<p || p<nl) return;
		if (nl==nr) { st[n]+=v; return; }
		update(p, v, 2*n, nl, (nl+nr)/2);
		update(p, v, 2*n+1, (nl+nr)/2+1, nr);
		st[n]=st[2*n]+st[2*n+1];
	}
 
	int query(int a, int b, int n=1, int nl=1, int nr=1) {
		if (b<a) return 0;
		if (n==1) nr=this->n;
		if (nr<a || b<nl) return 0;
		if (a<=nl && nr<=b) return st[n];
		return query(a, b, 2*n, nl, (nl+nr)/2) + query(a, b, 2*n+1, (nl+nr)/2+1, nr);
	}

	void print() {
		for (int i = 1; i < 2*n; ++i) {
			cout << st[i] << ' ';
		} cout << '\n';
	}
};

bool qcomp(pair<int, int> a, pair<int, int> b) {
	if (a.first==b.first) return a.second>b.second;
	return a.first<b.first;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	map<int, int> m;
	vector<pair<int, int>> v(2*n);
	for (int i = 0; i < n; ++i) {
		cin >> v[2*i].first >> v[2*i+1].first;
		v[2*i].second=i+1; v[2*i+1].second=-i-1;
	} sort(v.begin(), v.end(), qcomp); m[v[0].first]=1;
	for (int i = 1, j = 1; i < v.size(); ++i) {
		if (v[i].first==v[i-1].first) continue;
		m[v[i].first]=++j;
	}

	int ans=inf;
	segtree stn(v, m, 0), sts(v, m, 1);
	for (int i = 0; i < 2*n; ++i) {
		if (v[i].second<0) {
			stn.update(m[v[i].first], 1);
			sts.update(m[v[i].first], v[i].first);
		} else {
			stn.update(m[v[i].first], -1);
			sts.update(m[v[i].first], -v[i].first);
		}
		int a=v[i].first*stn.query(1, m[v[i].first]-1)-sts.query(1, m[v[i].first]-1);
		int b=sts.query(m[v[i].first]+1, m.size())-v[i].first*stn.query(m[v[i].first]+1, m.size());
		ans=min(ans, a+b);
	} cout << ans << '\n';

	return 0;
}