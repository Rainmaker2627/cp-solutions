#include<bits/stdc++.h>
using namespace std;
#define int long long

struct dsu {
	int n;
	vector<int> r, s, d;

	dsu(int n) {
		this->n=n;
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
		r[rb]=ra; s[ra]+=s[rb];
		return true;
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, a, b=1;
	cin >> n;
	vector<int> id(n+1, 0), e(2*n+1);
	for (int i = 1, t = 1; i <= n; ++i) {
		cin >> a;
		e[t++]=id[a]=i;
		while (b<=n && id[b]) e[t++]=-id[b++];
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
				if (!uf.unite(e[i], mt.top().back())) { cout << "IMPOSSIBLE\n"; return 0; }
				tmp.splice(tmp.begin(), mt.top());
				mt.pop();
			}
			if (tmp.size()) {
				mt.push({});
				mt.top().splice(mt.top().begin(), tmp);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << (uf.d[uf.find(i)]^uf.d[i])+1 << ' ';
	} cout << '\n';

	return 0;
}