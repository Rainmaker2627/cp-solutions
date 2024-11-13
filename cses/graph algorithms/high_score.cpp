#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf=1e18;
int n, m;
ll e[5000][3], d[2500];
bool v[2500], w[2500];
vector<int> f[2500], r[2500];

void dfs(int a) {
	v[a]=true;
	for (auto i : r[a]) {
		if (!v[i]) dfs(i);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, x;
		cin >> a >> b >> x;
		e[i][0]=--a; e[i][1]=--b; e[i][2]=-x;
		f[a].push_back(b);
		r[b].push_back(a);
	}

	for (int i = 0; i < n; ++i) {
		d[i]=inf;
	} d[0]=0;

	for (int i = 0; i < n-1; ++i) {
		for (int j = 0; j < m; ++j) {
			int a=e[j][0], b=e[j][1], x=e[j][2];
			d[b]=min(d[b], d[a]+x);
		}
	}

	dfs(n-1); swap(r, f); swap(v, w); dfs(0);
	bool t=false;
	for (int i = 0; i < m && !t; ++i) {
		ll a=e[i][0], b=e[i][1], x=e[i][2];
		if (d[b]>d[a]+x) t|=(v[a]&&w[a]);
	}

	cout << (t?-1:-d[n-1]) << '\n';
	return 0;
}