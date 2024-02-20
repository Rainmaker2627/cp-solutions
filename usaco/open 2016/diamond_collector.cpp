#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream cin("diamond.in");
	ofstream cout("diamond.out");

	int n, k;
	cin >> n >> k;
	vector<int> d(n);
	for (int i = 0; i < n; ++i) cin >> d[i];
	sort(d.begin(), d.end());

	vector<int> m(n), s(n);
	for (int i = 0, j = 0; i < n; ++i) {
		while (j<n && d[j]-d[i]<=k) j++;
		m[i]=j-i;
	} s[n-1]=m[n-1];
	for (int i = n-2; i >= 0; --i) s[i]=max(s[i+1], m[i]);
	s.push_back(0);

	int ans=0;
	for (int i = 0; i < n; ++i) {
		ans=max(ans, m[i]+s[i+m[i]]);
	} cout << ans << '\n';

	return 0;
}