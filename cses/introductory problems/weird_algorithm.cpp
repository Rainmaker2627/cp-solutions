#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;

	cout << n;
	while (n>1) cout << ' ' << (n=(n&1?3*n+1:n/2));
	cout << '\n';

	return 0;
}