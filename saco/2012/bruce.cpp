#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t;
	cin >> t;
	int s=ceil(sqrt(t))-1;

	int a,b;
	if (t>=s*s+s+1) a=s+1, b=(s+1)*(s+1)-t+1;
	else a=t-s*s, b=s+1;
	if (s%2==0) swap(a, b);
	cout << a << ' ' << b << '\n';

	return 0;
}