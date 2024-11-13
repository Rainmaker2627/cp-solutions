#include<bits/stdc++.h>
using namespace std;
#define int long long

void sums(int a, int b, vector<int>& t, vector<int>& s) {
	s.push_back(0);
	for (int i = a; i < b; ++i) {
		int l=s.size();
		for (int j = 0; j < l; ++j) {
			s.push_back(t[i]+s[j]);
		}
	} sort(s.begin(), s.end());
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, x;
	cin >> n >> x;
	vector<int> t(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}

	int ans=0;
	vector<int> s1, s2;
	sums(0, n/2, t, s1); sums(n/2, n, t, s2);
	for (int i = 0; i < s1.size(); ++i) {
		ans += upper_bound(s2.begin(), s2.end(), x-s1[i])-lower_bound(s2.begin(), s2.end(), x-s1[i]);
	} cout << ans << '\n';
	
	return 0;
}