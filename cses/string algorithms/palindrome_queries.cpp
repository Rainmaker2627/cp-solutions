#include<bits/stdc++.h>
using namespace std;
#define int long long

struct segtree {
	int n, m;
	string s;
	vector<int> stl, str, p;

	segtree(int prime, int mod, string s) {
		this->s = s;
		n=s.length(); m=mod;
		while (n&(n-1)) n++;
		p.assign(n+1, 1); p[1]=prime;
		for (int i = 2; i <= n; ++i) {
			p[i]=p[i-1]*prime%mod;
		}

		str.assign(2*n, 0); stl.assign(2*n, 0);
		for (int i = n; i < n+s.length(); ++i) stl[i]=str[i]=s[i-n]-'a';
		for (int i = n-1, j = 0; i > 0; --i) {
			stl[i]=(stl[2*i]+stl[2*i+1]*p[1<<j])%m;
			str[i]=(str[2*i]*p[1<<j]+str[2*i+1])%m;
			if ((i&(i-1))==0) j++;
		}
	}

	int hl, hr;
	bool query(int ql, int qr, int n=1, int nl=1, int nr=1) {
		if (n==1) { nr=this->n; hl=hr=0; }
		if (nr<ql || qr<nl) return false;
		if (ql<=nl && nr<=qr) {
			hl=(hl+stl[n]*p[nl-ql])%m;
			hr=(hr+str[n]*p[qr-nr])%m;
			return true;
		}
		query(ql, qr, 2*n, nl, (nl+nr)/2);
		query(ql, qr, 2*n+1, (nl+nr)/2+1, nr);
		return hl==hr;
	}

	int j;
	void update(int pos, char val, int n=1, int nl=1, int nr=1) {
		if (n==1) { nr=this->n; s[pos]=val; j=0; }
		if (nr<pos || pos<nl) return;
		if (nl==nr) { stl[n]=str[n]=val-'a'; return; }
		update(pos, val, 2*n, nl, (nl+nr)/2);
		update(pos, val, 2*n+1, (nl+nr)/2+1, nr);
		stl[n]=(stl[2*n]+stl[2*n+1]*p[1<<j])%m;
		str[n]=(str[2*n]*p[1<<j]+str[2*n+1])%m;
		j++;
	}
};

// add another segment tree with different parameters if collisions are common
signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;
	segtree st(53, 998244353, s);

	for (int i = 0; i < m; ++i) {
		int t;
		cin >> t;
		if (t==1) {
			int p;
			char v;
			cin >> p >> v;
			st.update(p, v);
		} else {
			int a, b;
			cin >> a >> b;
			bool c=st.query(a, b);
			cout << (c?"YES":"NO") << '\n';
		}
	}

	return 0;
}