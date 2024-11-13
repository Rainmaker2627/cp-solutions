#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct dsu {
	vector<int> rep, s;
	int cc, m;

	dsu(int n) {
		cc=n; m=1;
		vector<int> a(n+1), b(n+1, 1);
		for (int i = 1; i <= n; ++i) a[i]=i;
		swap(a, rep); swap(b, s);
	}

	int find(int a) {
		if (a==rep[a]) return a;
		return rep[a]=find(rep[a]);
	}

	void unite(int a, int b) {
		a=find(a), b=find(b);
		if (s[a]<s[b]) swap(a, b);
		if (a!=b) { rep[b]=a; s[a]+=s[b]; cc--; m=max(m, s[a]); }
		cout << cc << ' ' << m << '\n';
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	dsu uf(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		uf.unite(a, b);
	}

	return 0;
}