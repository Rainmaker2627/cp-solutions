#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;

	if (n%4==1 or n%4==2) { cout << "NO\n"; return 0; }
	else cout << "YES\n";
	int s=0, g=n*(n+1)/4;
	vector<int> a, b;
	for (int i = n; i; --i) {
		if (s+i<=g) {
			s+=i;
			a.push_back(i);
		} else {
			b.push_back(i);
		}
	}

	cout << a.size() << '\n';
	for (auto i : a) {
		cout << i << ' ';
	} cout << '\n' << b.size() << '\n';
	for (auto i : b) {
		cout << i << ' ';
	} cout << '\n';

	return 0;
}