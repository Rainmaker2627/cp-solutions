#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, s=0;
	cin >> n;
	for (int p = 5; p <= n; p*=5) {
		s+=n/p;
	} cout << s << '\n';

	return 0;
}