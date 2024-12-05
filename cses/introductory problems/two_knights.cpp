#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cout << (i-1)*(i+4)*(i*i-3*i+4)/2 << '\n';
	}

	return 0;
}