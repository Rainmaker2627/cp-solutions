#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];

	vector<int> d(n), f(n);
	for (int i = 0; i < n; ++i) {
		d[i]=a[i]-b[i];
		f[i]=d[i]+(i==0?0:f[i-1]);
	} sort(f.begin(), f.end());

	int s=0, m=f[n/2];
	for (int i = 0; i < n; ++i) {
		s+=abs(f[i]-m);
	} cout << s << '\n';

	return 0;
}