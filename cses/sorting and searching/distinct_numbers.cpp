#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	} sort(a.begin(), a.end());

	int ans=1;
	for (int i = 1; i < n; ++i) {
		if (a[i-1]!=a[i]) ans++;
	} cout << ans << '\n';

	return 0;
}