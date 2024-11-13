#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
 
const ll inf = 1e18;
int n, m;
vector<pll> f[100000], r[100000];
ll d[2][100000];
 
void dij(int u, int t) {
	priority_queue<pll> pq;
	pq.push({0, u});
	while (!pq.empty()) {
		auto [c, n] = pq.top();
		pq.pop();
		if (d[t][n]<-c) continue;
		for (auto [v, w] : f[n]) {
			if (d[t][v]>w-c) {
				d[t][v]=w-c;
				pq.push({-d[t][v], v});
			}
		}
	}
}
 
int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		f[--a].push_back({--b, c});
		r[b].push_back({a, c});
	}

	for (int i = 1; i < n; ++i) d[0][i]=d[1][i-1]=inf;

	ll m=inf;
	dij(0, 0); swap(f, r); dij(n-1, 1);
	for (int i = 0; i < n; ++i) {
		for (auto [j, w] : r[i]) {
			m=min(m, d[0][i] + (w/2) + d[1][j]);
		}
	}
 
	cout << m << '\n';
	return 0;
}
