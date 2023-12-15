#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> plli;

const ll inf = 1e18;
int n, m;
ll p[100000];
vector<pair<int, int>> e[100000];

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a-1].push_back({b-1, c});
	}

	for (int i = 1; i < n; ++i) {
		p[i]=inf;
	} p[0]=0;

	priority_queue<plli, vector<plli>, greater<plli>> pq;
	pq.push({0, 0});
	while (!pq.empty()) {
		auto [c, n] = pq.top();
		pq.pop();
		if (p[n]<c) continue;
		for (auto i : e[n]) {
			if (c+i.second<p[i.first]) {
				pq.push({p[i.first]=c+i.second, i.first});
			}
		}
	}

	for (int i = 0; i < n-1; ++i) {
		cout << p[i] << ' ';
	} cout << p[n-1] << '\n';

	return 0;
}