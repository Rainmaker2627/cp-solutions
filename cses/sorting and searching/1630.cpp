#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, s=0;
	cin >> n;
	vector<int> a(n), d(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> d[i];
		s+=d[i];
	} sort(a.begin(), a.end());

	for (int i = 0; i < n; ++i) {
		s-=(n-i)*a[i];
	} cout << s << '\n';

	return 0;
}