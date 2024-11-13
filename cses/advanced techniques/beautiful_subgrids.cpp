#pragma GCC target("popcnt")
#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	// bs because bitset problems are bullshit
	vector<bitset<3000>> bs(n);
	for (int i = 0; i < n; ++i) {
		string grid;
		cin >> grid;
		bs[i]=bitset<3000>(grid);
	}

	int ans=0;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			int c=(bs[i]&bs[j]).count();
			ans+=c*(c-1)/2;
		}
	} cout << ans << '\n';

	return 0;
}