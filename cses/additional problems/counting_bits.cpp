#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n; n++;

	int s=0, one=1;
	for (int i = 50; i >= 0; --i) {
		if (n&(one<<i)) {
			s+=i*(n&(one<<i))>>1;
			s+=(n^=n&(one<<i));
		}
	} cout << s << '\n';

	return 0;
}