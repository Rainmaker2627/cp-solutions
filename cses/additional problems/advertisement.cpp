#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m=0;
	cin >> n;
	vector<int> k(n);
	for (int i = 0; i < n; ++i) {
		cin >> k[i];
	} k.push_back(0);

	stack<int> s, h;
	h.push(0); s.push(0);
	for (int i = 0; i < n+1; ++i) {
		int p = i;
		while (h.top()>k[i]) {
			p=s.top();
			m=max(m, (i-p)*h.top());
			s.pop(); h.pop();
		} s.push(p); h.push(k[i]);
	}

	cout << m << '\n';
	return 0;
}