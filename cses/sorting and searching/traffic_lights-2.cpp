#include<bits/stdc++.h>
using namespace std;

int x, n;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> x >> n;
	multiset<int> m;
	set<int> s;
	s.insert(0); s.insert(x); m.insert(x);
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;

		auto a = s.lower_bound(t);
		m.erase(m.find(*a-*(prev(a))));
		m.insert(t-*(prev(a)));
		m.insert(*a-t);
		s.insert(t);

		cout << *(--m.end()) << (i==n-1?'\n':' ');
	}

	return 0;
}
