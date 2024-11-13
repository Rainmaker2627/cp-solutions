#include<bits/stdc++.h>
using namespace std;
#define int long long

struct segtree {
	int n;
	vector<int> s, m, lr, rl;

	segtree(vector<int>& v) {
		n=v.size();
		while (n&(n-1)) n++;
		s.assign(2*n, 0); m.assign(2*n, 0);
		lr.assign(2*n, 0); rl.assign(2*n, 0);
		for (int i = n; i < n+v.size(); ++i) s[i]=m[i]=lr[i]=rl[i]=v[i-n];
		for (int i = n-1; i > 0; --i) {
			s[i]=s[2*i]+s[2*i+1];
			lr[i]=max(lr[2*i], s[2*i]+lr[2*i+1]);
			rl[i]=max(rl[2*i]+s[2*i+1], rl[2*i+1]);
			m[i]=max(m[2*i], m[2*i+1]);
			m[i]=max(m[i], rl[2*i]+lr[2*i+1]);
		}
	}

	void update(int k, int x, int n=1, int ql=1, int qr=-1) {
		if (n==1) qr=this->n;
		if (k<ql || qr<k) return;
		if (ql==qr)  {
			s[n]=m[n]=lr[n]=rl[n]=x;
			return;
		}
		update(k, x, 2*n, ql, (ql+qr)/2);
		update(k, x, 2*n+1, (ql+qr)/2+1, qr);
		s[n]=s[2*n]+s[2*n+1];
		lr[n]=max(lr[2*n], s[2*n]+lr[2*n+1]);
		rl[n]=max(rl[2*n]+s[2*n+1], rl[2*n+1]);
		m[n]=max(m[2*n], m[2*n+1]);
		m[n]=max(m[n], rl[2*n]+lr[2*n+1]);
	}

	int query() {
		return max(m[1], (int)0);
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	segtree st(v);
	for (int i = 0; i < m; ++i) {
		int k, x;
		cin >> k >> x;
		st.update(k, x);
		cout << st.query() << '\n';
	}

	return 0;
}