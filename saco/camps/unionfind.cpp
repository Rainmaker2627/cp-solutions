#include<bits/stdc++.h>
using namespace std;

struct dsu {
	vector<int> p, s;

	dsu(int n) {
		vector<int> a(n+1), b(n+1, 1);
		for (int i = 1; i <= n; ++i) a[i]=i;
		swap(p, a); swap(s, b);
	}

	int find(int u) {
		if (p[u]==u) return u;
		return p[u]=find(p[u]);
	}

	void unite(int a, int b) {
		a=find(a); b=find(b);
		if (s[a]<s[b]) swap(a,b);
		p[b]=a;
		s[a]+=s[b];
	}
};

int main() {
	int n, q;
	cin >> n >> q;
	dsu u(n);
	for (int i = 0; i < q; ++i) {
		char c;
		int a, b;
		cin >> c >> a >> b;
		if (c=='U') {
			u.unite(a, b);
		} else {
			cout << (u.find(a)==u.find(b)?"True":"False") << '\n';
		}
	} cin >> n;
	return 0;
}