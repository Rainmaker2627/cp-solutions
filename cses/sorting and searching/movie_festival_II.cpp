#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		v.push_back({y, x});
	} sort(v.begin(), v.end());

	multiset<int> m;
	for (int i = 0; i < k; ++i) m.insert(0);
	m.insert(-1);

	int a=0;
	for (auto [e, s] : v) {
		auto t=prev(m.upper_bound(s));
		if (*t>-1) {
			m.erase(t);
			m.insert(e);
			a++;
		}
	}

	cout << a << '\n';
	return 0;
}