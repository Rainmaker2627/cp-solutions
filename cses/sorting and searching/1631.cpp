#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, b, s=0, m=0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> b; s+=b; m=max(m, b);
	}
	if (2*m>s) cout << 2*m << '\n';
	else cout << s << '\n';

	return 0;
}