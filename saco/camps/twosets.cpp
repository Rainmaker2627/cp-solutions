#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct dsu {
	vector<int> v, t, s;
	unordered_map<int, int> m;

	dsu(int N, unordered_map<int, int>& M) {
		m=M;
		vector<int> b(N), c(N, 1), d(N, -1);
		for (int i = 0; i < N; ++i) b[i]=i;
		swap(v, b); swap(t, d); swap(s, c);
	}

	bool unite(int a, int b) {
		a=par(a); b=par(b);
		if (s[a]<s[b]) swap(a, b);
		v[b]=a; s[a]+=s[b];
		if (t[a]==-1) t[a]=t[b];
		else if (t[a]!=t[b] && t[b]!=-1) return false;
		return true;
	}

	int par(int a) {
		a=m[a];
		while (a!=v[a]) {
			v[a]=v[v[a]];
			a=v[a];
		} return a;
	}

	bool set(int a, int p) {
		a=par(a);
		if (t[a]==-1) t[a]=p;
		else if (t[a]!=p) return false;
		return true;
	}
};

int main() {
	int N, a, b;
	cin >> N >> a >> b;

	vector<int> x(N);
	unordered_map<int, int> m;
	for (int i = 0; i < N; ++i) {
		cin >> x[i];
		m[x[i]]=i;
	} dsu u(N, m);

	bool p=true;
	for (int i = 0; i < N && p; ++i) {
		if (m.count(a-x[i])) {
			p&=u.unite(x[i], a-x[i]);
			if (m.count(b-x[i])) {
				p&=u.unite(x[i], b-x[i]);
			} else p&=u.set(x[i], 0);
		} else if (m.count(b-x[i])) {
			p&=u.unite(x[i], b-x[i]);
			p&=u.set(x[i], 1);
		} else p=false;
	}

	if (p) {
		cout << "YES\n";
		for (int i = 0; i < N; ++i) {
			int r=u.t[u.par(x[i])];
			cout << (r==-1?1:r) << ' ';
		}
	} else cout << "NO\n";
	cin >> a;
	return 0;
}