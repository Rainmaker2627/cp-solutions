#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> pc(n-2), lst(n+1, -1);
	for (int i = 0; i < n-2; ++i) {
		cin >> pc[i];
		lst[pc[i]]=i;
	} pc.push_back(n);

	set<int> used;
	for (int i = 0; i < n-1; ++i) {
		used.insert(i);
	}

	vector<pair<int, int>> e;
	for (int i = 1; i < n; ++i) {
		auto j = used.upper_bound(lst[i]);
		e.push_back({i, pc[*j]});
		used.erase(j);
	}

	for (auto [u, v] : e) {
		cout << u << ' ' << v << '\n';
	}

	return 0;
}