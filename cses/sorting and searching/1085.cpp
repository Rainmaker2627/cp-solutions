#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k, m=0;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i]; m=max(m, a[i]);
	}

	int lo=m, hi=2e14+1;
	while (lo<hi) {
		int mid=(hi+lo)/2, s=0, c=0;
		for (int j = 0; j < n; ++j) if ((s+=a[j])>mid) { s=a[j]; c++; }
		if (c<k) hi=mid;
		else lo=mid+1;
	} cout << lo << '\n';

	return 0;
}