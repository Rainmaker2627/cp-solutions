#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, s=0, m=0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		s+=max((int)0, m-v[i]);
		m=max(m, v[i]);
	} cout << s << '\n';

	return 0;
}