#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int x, y, s=0;
		cin >> x >> y;
		int m=max(x, y);
		s+=m*m;
		if (m%2) swap(x, y);
		if (x==m) s-=y-1;
		else s-=2*y-x-1;
		cout << s << '\n';
	}

	return 0;
}