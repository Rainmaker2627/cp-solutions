#include<bits/stdc++.h>
using namespace std;
#define int long long

struct dsu {
	int n, cc;
	vector<int> r, s, d;

	dsu(int n) {
		this->n=n; cc=n;
		r.reserve(n+1);
		for (int i = 1; i <= n; ++i) r[i]=i;
		s.assign(n+1, 1);
		d.assign(n+1, 0);
	}

	int find(int a) {
		if (a==r[a]) return a;
		int p=find(r[a]);
		d[a]^=d[r[a]];
		return r[a]=p;
	}

	bool unite(int a, int b) {
		int ra=find(a), rb=find(b);
		if (ra==rb) return d[a]^d[b]==1;
		if (s[ra]<s[rb]) swap(ra, rb);
		d[rb]=1^d[a]^d[b];
		r[rb]=ra; s[ra]+=s[rb]; cc--;
		return true;
	}
};

int exp(int a, int b, int mod) {
	int x=1;
	while (b) {
		if (b%2) x=(x*a)%mod;
		a=(a*a)%mod; b/=2;
	} return x;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, a, b;
	cin >> n;
	vector<int> e(2*n+1);
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		e[a]=i+1;
		e[b]=-i-1;
	}

	dsu uf(n+1);
	list<int> tmp;
	stack<list<int>> mt;
	for (auto i = 1; i <= 2*n; ++i) {
		if (e[i]>0) {
			mt.push({});
			mt.top().push_back(e[i]);
		} else {
			e[i]=-e[i];
			tmp.clear();
			while (true) {
				if (mt.top().back()==e[i]) {
					mt.top().pop_back();
					if (mt.top().size()==0) mt.pop();
					break;
				}
				if (!uf.unite(e[i], mt.top().back())) { cout << "0\n"; return 0; }
				tmp.splice(tmp.begin(), mt.top());
				mt.pop();
			}
			if (tmp.size()) {
				mt.push({});
				mt.top().splice(mt.top().begin(), tmp);
			}
		}
	}

	cout << exp(2, uf.cc-1, 1e9+7) << '\n';
	return 0;
}