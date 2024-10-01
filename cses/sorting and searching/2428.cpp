#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k, t=0, s=0;
	cin >> n >> k;
	vector<int> a(n);
	unordered_map<int, int> m;
	for (int i = 0, j = 0; i < n; ++i) {
		cin >> a[i];
		if (m[a[i]]) m[a[i]]++;
		else { m[a[i]]=1; t++; }
		while (t>k) {
			if (--m[a[j++]]) continue;
			else t--;
		} s+=i-j+1;
	} cout << s << '\n';

	return 0;
}