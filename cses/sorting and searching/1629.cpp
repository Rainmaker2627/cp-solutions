#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<pair<int, int>> m;
	for (int i = 0; i < n; ++i) {
		int s, e;
		cin >> s >> e;
		m.push_back({e, s});
	} sort(m.begin(), m.end());

	int a=0, b=0;
	for (auto [e, s] : m) {
		if (a<=s) { a=e; b++; }
	}

	cout << b << '\n';
	return 0;
}