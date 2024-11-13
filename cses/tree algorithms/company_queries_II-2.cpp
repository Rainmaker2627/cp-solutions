#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> c;
vector<int> e, h, p;

struct sparse {
	int n, m;
	vector<vector<int>> sp;

	int high(int a, int b) {
		return (h[a]<=h[b]?a:b);
	}

	sparse(int x) {
		m=0; n=e.size();
		while ((1<<m)<n) m++;
		sp.assign(m, vector<int>(n, 0));
		for (int i = 0; i < n; ++i) sp[0][i]=e[i];
		for (int i = 1; i < m; ++i) {
			for (int j = 0; j < n-(1<<i)+1; ++j) {
				sp[i][j]=high(sp[i-1][j], sp[i-1][j+(1<<i-1)]);
			}
		}
	}

	int query(int a, int b) {
		if (a==b) return a;
		a=p[a], b=p[b];
		if (a>b) swap(a, b);
		int d=b-a, t=0;
		while ((1<<t)<=d) t++; t--;
		return high(sp[t][a], sp[t][b-(1<<t)+1]);
	}
};

void dfs(int u) {
	p[u]=e.size();
	e.push_back(u);
	for (auto i : c[u]) {
		h[i]=h[u]+1;
		dfs(i);
		e.push_back(u);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	c.assign(n+1, vector<int>());
	h.assign(n+1, 0); p.assign(n+1, 0);
	for (int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		c[p].push_back(i);
	} dfs(1);
	sparse sp(0);

	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		cout << sp.query(a, b) << '\n';
	}

	return 0;
}