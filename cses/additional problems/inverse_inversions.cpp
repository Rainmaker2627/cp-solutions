#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n;) {
		if (k>=n-i) { k-=n-i; cout << n-- << ' '; }
		else cout << i++ << ' ';
	}

	return 0;
}