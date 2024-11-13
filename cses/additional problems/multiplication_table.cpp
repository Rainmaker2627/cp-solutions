#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int f(int p, int n) {
	int s=0, a=n;
	for (int i = 1; i <= n; ++i) {
		while (i*a>p) --a;
		s+=a;
	} return s;
}
 
signed main() {
	cin.tie(0)->sync_with_stdio(false);
 
	int n;
	cin >> n;
 
	int lo=1, hi=n*n;
	while (lo<hi) {
		int mid=(lo+hi)/2;
		if (f(mid, n)<=n*n/2) lo=mid+1;
		else hi=mid;
	} cout << hi << '\n';
 
	return 0;
}