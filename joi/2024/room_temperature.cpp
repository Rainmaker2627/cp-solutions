#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, t;
	cin >> n >> t;
	vector<int> a(n), p;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		p.push_back(a[i]%t);
	} sort(p.begin(), p.end());

	int m=0;
	for (int i = 0; i < n-1; ++i) {
		m=max(m, (p[i+1]-p[i]-1)%t);
	} m=max(m, t+p[0]-p[n-1]-1);
	cout << (t-m)/2 << '\n';

	return 0;
}