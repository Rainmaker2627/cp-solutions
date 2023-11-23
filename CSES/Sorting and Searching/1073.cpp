#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n;
	vector<int> k(n);
	for (int i = 0; i < n; ++i) {
		cin >> k[i];
	}

	multiset<int> s;
	for (int i = 0; i < n; ++i) {
		auto u = s.upper_bound(k[i]);
		if (u!=s.end()) s.erase(u);
		s.insert(k[i]);
	}

	cout << s.size() << '\n';
	return 0;
}