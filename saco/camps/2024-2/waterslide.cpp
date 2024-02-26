#include<bits/stdc++.h>
using namespace std;
#define int long long

struct dsu {
	vector<int> par, s, c;
	vector<int> cycle;
 
	void setup(int n, vector<int>& cost) {
		vector<int> a(n+1, 1), b(n+1);
		c.reserve(n+1);
		cycle.assign(n+1, false);
		for (int i = 1; i <= n; ++i) b[i]=i;
		for (int i = 1; i <= n; ++i) c[i]=cost[i];
		swap(a, s); swap(b, par);
	}
 
	void unite(int a, int b) {
		a=find(a); b=find(b);
		if (s[a]<s[b]) swap(a, b);
		par[b]=a; s[a]+=s[b];
		if (cycle[b]) {
			c[a]=c[b];
			cycle[a]=true;
		}
	}
 
	int find(int a) {
		if (par[a]==a) return a;
		return par[a]=find(par[a]);
	}

	void cyclemin(int a, int v) {
		a=find(a);
		c[a]=v;
		cycle[a]=true;
	}
} uf;

int n, t;
vector<int> succ, cost;
vector<int> v;

int dfs1(int n) {
	v[n]=2;
	uf.unite(n, succ[n]);
	if (v[succ[n]]==2) { v[n]=1; return succ[n]; }
	else if (v[succ[n]]==1) { v[n]=1; return 0; }
	int t=dfs1(succ[n]);
	v[n]=1;
	return t;
}

void dfs2(int s, int n, int& m) {
	if (n==s) return;
	dfs2(s, succ[n], m=min(m, cost[n]));
}

signed main() {
	cin >> n;
	v.assign(n+1, 0);
	succ.assign(n+1, 0); cost.assign(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> cost[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> succ[i];
	} uf.setup(n, cost);

	for (int i = 1; i <= n; ++i) {
		if (!v[i]) {
			int x=dfs1(i);
			if (x) {
				int m=cost[x];
				dfs2(x, succ[x], m);
				uf.cyclemin(x, m);
			}
		}
	}

	int ans=0;
	vector<bool> v(n+1, false);
	for (int i = 1; i <= n; ++i) {
		int t=uf.find(i);
		if (v[t]) continue;
		v[t]=true;
		ans+=uf.c[t];
	} cout << ans << '\n';

	return 0;
}