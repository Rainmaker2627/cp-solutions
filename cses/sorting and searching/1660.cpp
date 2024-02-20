#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int s=0, i=0, j=0, p=0;
	while (i<n) {
		if ((s<=x || i==j) && j<n) s+=a[j++];
		else s-=a[i++];
		if (s==x) p++;
	} cout << p << '\n';

	return 0;
}