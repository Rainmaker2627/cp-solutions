#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll inf = 1e18;
const int mod = 1e9+7;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<pll>> e(n+1, vector<pll>());
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a].push_back({b, c});
	}

	vector<ll> d(n+1, inf), a(n+1, 0), s(n+1, inf), l(n+1, 0);
	vector<bool> f(n+1, 0); a[1]=1; s[1]=d[1]=0;
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({0, 1});
	while (!pq.empty()) {
		auto [w, u] = pq.top(); pq.pop();
		if (f[u]) continue;
		f[u]=true;
		for (auto [v, t] : e[u]) {
			if (d[v]>w+t) {
				a[v]=a[u]; s[v]=s[u]+1; l[v]=l[u]+1;
				pq.push({d[v]=w+t, v});
			} else if (d[v]==w+t) {
				(a[v]+=a[u])%=mod;
				s[v]=min(s[u]+1, s[v]);
				l[v]=max(l[u]+1, l[v]);
			}
		}
	}
	
	cout << d[n] << ' ' << a[n] << ' ' << s[n] << ' ' << l[n] << '\n';
	return 0;
}