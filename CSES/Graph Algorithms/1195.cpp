#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> plli;

const ll inf=1e18;
int n, m;
ll d[100000][2];
vector<pair<int, int>> e[100000];

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a-1].push_back({b-1, c});
	}

	for (int i = 1; i < n; ++i) d[i][false]=d[i][true]=inf;

	priority_queue<plli, vector<plli>, greater<plli>> pq;
	pq.push({0,0});
	while (!pq.empty()) {
		auto [c, u] = pq.top();
		bool b=u<0; u=abs(u);
		pq.pop();
		if (d[u][b]<c) continue;
		if (u==n-1) break;
		for (auto [v, w] : e[u]) {
			if (!b && d[v][true] > c+w/2) {
				d[v][true]=c+w/2;
				pq.push({d[v][true], -v});
			} if (d[v][b]>c+w) {
				d[v][b]=c+w;
				pq.push({d[v][b], -(2*b-1)*v});
			}
		}
	}

	cout << d[n-1][true] << '\n';
	return 0;
}