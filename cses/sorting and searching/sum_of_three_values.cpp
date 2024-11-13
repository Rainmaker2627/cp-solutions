#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second=i+1;
	} sort(a.begin(), a.end());

	bool b=false;
	for (int i = 1; i < n-1 && !b; ++i) {
		int l=0, r=n-1;
		while (l<i && i<r && !b) {
			int s=a[i].first+a[l].first+a[r].first;
			if (s==x) {
				cout << a[i].second << ' ' << a[l].second << ' ' << a[r].second << '\n';
				b=true;
			} else if (s<x) l++;
			else r--;
		}
	}
	
	if (!b) cout << "IMPOSSIBLE\n";
	return 0;
}