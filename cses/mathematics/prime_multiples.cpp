#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k, s=0;
	cin >> n >> k;
	vector<__int128> a;
	a.push_back(1);
	for (int i = 0; i < k; ++i) {
		int p; cin >> p;
		for (int j = 0; j < (1<<i); ++j) {
			__int128 x=p*a[j];
			if (x<=0 || x>n) x=0;
			else s+=(__builtin_popcount(j)%2?-1:1)*(n/x);
			a.push_back(x);
		}
	} cout << s << '\n';

	return 0;
}