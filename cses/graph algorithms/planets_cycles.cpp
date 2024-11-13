#include<bits/stdc++.h>
using namespace std;

vector<int> t, h;
int s;

struct dsu {
	vector<int> par, s, cs;
 
	void setup(int n) {
		vector<int> a(n+1, 1), b(n+1), c(n+1, 0);
		for (int i = 1; i <= n; ++i) b[i]=i;
		swap(a, s); swap(b, par); swap(c, cs);
	}
 
	void unite(int a, int b) {
		a=find(a); b=find(b);
		if (s[a]<s[b]) swap(a, b);
		par[b]=a;
		s[a]+=s[b];
		if (cs[b]) cs[a]=cs[b];
	}
 
	int find(int a) {
		if (par[a]==a) return a;
		return par[a]=find(par[a]);
	}
} uf;

void dfs(int n) {
	int p=t[n];
	if (uf.find(n)!=uf.find(p)) {
		uf.unite(n, p);
		dfs(p);
	} else if (!h[n]) s=p;
	if (s) {
		h[n]=h[p]-1;
		if (n==s) { s=0; uf.cs[uf.find(n)]=-h[n]; }
	} else if (!h[n]) h[n]=max(h[p], 0)+1;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	uf.setup(n);
	h.reserve(n+1); t.reserve(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
		h[i]=0;
	}

	for (int i = 1; i <= n; ++i) {
		if (!h[i]) dfs(i);
	}

	for (int i = 1; i <= n; ++i) {
		cout << max(h[i], 0)+uf.cs[uf.find(i)] << ' ';
	}

	return 0;
}