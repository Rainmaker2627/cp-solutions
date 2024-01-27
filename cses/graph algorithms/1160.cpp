#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> sp;
vector<int> h;
int t;

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
	int p=sp[0][n];
	if (uf.find(n)!=uf.find(p)) {
		uf.unite(n, p);
		dfs(p);
	} else if (!h[p]) t=p;
	if (t) {
		h[n]=h[p]-1;
		if (n==t) { t=0; uf.cs[uf.find(n)]=-h[n]; }
	} else if (!h[n]) h[n]=max(0, h[p])+1;
}

int jump(int n, int v) {
	for (int i = 0; i < 30; ++i) {
		if (v&(1<<i)) n=sp[i][n];
	} return n;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	uf.setup(n);
	h.reserve(n+1);
	vector<vector<int>> x(30, vector<int>(n+1, 0));
	for (int i = 1; i <= n; ++i) {
		cin >> x[0][i];
		h[i]=0;
	} swap(x, sp);

	for (int i = 1; i <= n; ++i) {
		if (!h[i]) dfs(i);
	}

	for (int i = 1; i < 30; ++i) {
		for (int j = 1; j <= n; ++j) {
			sp[i][j]=sp[i-1][sp[i-1][j]];
		}
	}

	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		if (uf.find(a)==uf.find(b)) {
			if (h[b]<0) {
				int d=0;
				if (h[a]>0) {
					d=h[a];
					a=jump(a, d);
				}
				int t=h[b]-h[a], s=uf.cs[uf.find(a)];
				if (t<0) t=(t%s+s)%s;
				cout << t+d << '\n';
			} else {
				if (h[a]>=h[b]) {
					if (b!=jump(a, h[a]-h[b])) cout << -1 << '\n';
					else cout << h[a]-h[b] << '\n';
				} else cout << -1 << '\n';
			}
		} else cout << -1 << '\n';
	}
	
	return 0;
}