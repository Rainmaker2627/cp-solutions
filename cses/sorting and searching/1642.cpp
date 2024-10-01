#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	bool f=false;
	unordered_map<int, pair<int, int>> m;
	for (int i = 0; i < n && !f; ++i) {
		for (int j = i+1; j < n && !f; ++j) {
			if (m.count(x-a[i]-a[j])) {
				auto p = m[x-a[i]-a[j]];
				cout << p.second+1 << ' ' << p.first+1 << ' ' << i+1 << ' ' << j+1 << ' ' << '\n';
				f=true;
			}
		}
		for (int j = i-1; j >= 0; --j) m[a[i]+a[j]]={i, j};
	} if (!f) cout << "IMPOSSIBLE\n";

	return 0;
}