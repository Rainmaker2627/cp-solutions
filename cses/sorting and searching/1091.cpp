#include<bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	multiset<int> h;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		h.insert(a);
	} h.insert(-1);

	int t;
	for (int i = 0; i < m; ++i) { 
		cin >> t;
		auto l = --h.upper_bound(t);
		cout << *l << '\n';
		if (*l!=-1) h.erase(l);
	}

	return 0;
}