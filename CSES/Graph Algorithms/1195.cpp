#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> plli;

const ll inf=1e18;
int n, m;
ll d[100000];
int s[100000];
vector<pair<int, int>> e[100000];

int main() {
	// cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a-1].push_back({b-1, c});
	}

	for (int i = 1; i < n; ++i) d[i]=inf;

	priority_queue<plli, vector<plli>, greater<plli>> pq;
	pq.push({0,0});
	while (!pq.empty()) {
		auto [c, n] = pq.top();
		pq.pop();
		if (d[n]<c) continue;
		c+=s[n]/2+s[n]%2;
		for (auto i : e[n]) {
			s[i.first]=max(s[n], i.second);
			if (d[i.first]>c+i.first-s[i.first]/2-s[i.first]%2) {
				pq.push({d[i.first]=c+i.first-s[i.first]/2-s[i.first]%2,i.first});
			}
		}
	}

	cout << d[n-1] << '\n';
	cin >> n;
	return 0;
}