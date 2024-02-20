#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, a, s=0, p=0;
	cin >> n;
	vector<int> m(n, 0); m[0]=1;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s+=a;
		p+=m[(s%n+n)%n]++;
	} cout << p << '\n';

	return 0;
}