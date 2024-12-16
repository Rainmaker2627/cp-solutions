#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> t(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	} sort(t.begin(), t.end());
	
	vector<pair<int, int>> v;
	for (int i = 1; i < n; ++i) {
		v.push_back({t[i]-t[i-1]-1, i});
	} sort(v.begin(), v.end());

	int i=0, r=n;
	while (n-->k) r+=v[i++].first;
	cout << r << '\n';

	return 0;
}