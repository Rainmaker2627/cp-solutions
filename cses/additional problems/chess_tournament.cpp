#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, s=0;
	cin >> n;
	vector<pair<int, int>> e;
	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= n; ++i) {
		int d;
		cin >> d;
		pq.push({d, i});
		s+=d;
	}

	bool p=(s%2==0);
	for (int i = 0; i < n && p; ++i) {
		auto [a, b]=pq.top();
		pq.pop();

		vector<pair<int, int>> t;
		for (int j = 0; j < a && p; ++j) {
			auto [c, d] = pq.top();
			if (c==0) p=false;
			else t.push_back({c-1, d});
			pq.pop();
		}

		for (auto [c, d] : t) {
			e.push_back({b, d});
			pq.push({c, d});
		}
	}

	if (p) {
		cout << e.size() << '\n';
		for (auto [u, v] : e) {
			cout << u << ' ' << v << '\n';
		}
	} else cout << "IMPOSSIBLE\n";

	return 0;
}