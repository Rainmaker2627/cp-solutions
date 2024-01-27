#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pii>> e(n+1, vector<pii>());
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		e[a].push_back({b, w});
	}

	vector<ll> v(n+1, k), t;
	priority_queue<pii> pq;
	pq.push({0,1});
	while (!pq.empty()) {
		auto [w, a] = pq.top();
		pq.pop();
		if (!v[a]) continue;
		else v[a]--;
		if (a==n) t.push_back(-w);
		for (auto [b, l] : e[a]) {
			if (!v[b]) continue;
			pq.push({-l+w, b});
		}
	}

	for (int i = 0; i < k; ++i) {
		cout << t[i] << (i==k-1?'\n':' ');
	}

	return 0;
}