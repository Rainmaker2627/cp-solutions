#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge {
	int u, v, w;
};

const ll inf=1e18;
int n, m;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	vector<edge> e(m);
	for (int i = 0; i < m; ++i) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}

	vector<ll> d(n+1, inf), p(n+1, -1);
	int x=-1; d[1]=0;
	for (int i = 0; i <= n; ++i) {
		x=-1;
		for (auto j : e) {
			if (d[j.v]>d[j.u]+j.w) {
				d[j.v]=d[j.u]+j.w;
				x=j.v; p[j.v]=j.u;
			}
		}
	}

	if (x>-1) {
		vector<int> c;
		for (int i = 0; i < n; ++i) x=p[x];
		for (int v = x;; v=p[v]) {
			c.push_back(v);
			if (v==x && c.size()>1) break;
		}

		cout << "YES\n";
		for (int i = c.size()-1; i >= 0; --i) {
			cout << c[i] << (i?' ':'\n');
		}
	} else cout << "NO\n";

	return 0;
}