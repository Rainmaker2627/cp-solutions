#include<bits/stdc++.h>
using namespace std;

struct segtree {
	int n;
	vector<int> st, mp, ms, mc;

	segtree(string s, char c) {
		n=s.length();
		while (n&(n-1)) n++;
		st.assign(2*n, 0);
		mp.assign(2*n, 0);
		ms.assign(2*n, 0);
		mc.assign(2*n, 0);
		for (int i = n; i < n+s.size(); ++i) st[i]=mp[i]=ms[i]=mc[i]=(s[i-n]==c);
		for (int i = n-1; i > 0; --i) {
			st[i]=st[2*i]&&st[2*i+1];
			mp[i]=mp[2*i]+(st[2*i]?mp[2*i+1]:0);
			ms[i]=ms[2*i+1]+(st[2*i+1]?ms[2*i]:0);
			mc[i]=max(mp[i], ms[i]);
			mc[i]=max(ms[2*i]+mp[2*i+1], mc[i]);
			mc[i]=max(max(mc[2*i], mc[2*i+1]), mc[i]);
		}
	}

	int query() {  return mc[1]; }
	void update(int p, int n=1, int nl=1, int nr=1) {
		if (n==1) nr=this->n;
		if (p<nl || nr<p) return;
		if (nl==nr) { st[n]=mp[n]=ms[n]=mc[n]=st[n]^1; return; }
		update(p, 2*n, nl, (nl+nr)/2);
		update(p, 2*n+1, (nl+nr)/2+1, nr);
		st[n]=st[2*n]&&st[2*n+1];
		mp[n]=mp[2*n]+(st[2*n]?mp[2*n+1]:0);
		ms[n]=ms[2*n+1]+(st[2*n+1]?ms[2*n]:0);
		mc[n]=max(mp[n], ms[n]);
		mc[n]=max(ms[2*n]+mp[2*n+1], mc[n]);
		mc[n]=max(max(mc[2*n], mc[2*n+1]), mc[n]);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int m;
	string s;
	cin >> s >> m;

	segtree one(s, '1'), zero(s, '0');
	for (int i = 0, p; i < m; ++i) {
		cin >> p;
		one.update(p);
		zero.update(p);
		cout << max(one.query(), zero.query()) << ' ';
	}

	return 0;
}