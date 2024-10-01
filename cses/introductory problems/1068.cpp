#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	cout << n;
	while (n>1) {
		if (n%2) n=3*n+1;
		else n/=2;
		cout << ' ' << n;
	} cout << '\n';

	return 0;
}