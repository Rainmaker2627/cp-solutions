#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, x, s=0, p=0;
	cin >> n >> x;
	unordered_map<int, int> m; m[0]=1;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		p+=m[(s+=a)-x];
		m[s]++;
	} cout << p << '\n';

	return 0;
}