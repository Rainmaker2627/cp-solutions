#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> p(20, 1);

int count(int x) {
	if (x==0) return 0;
	int a=0, n=0, c=0;
	while(x) a=10*a+x%10, x/=10, c+=p[n++];
	for (int i = 0, j = 10; i < n; ++i) {
		int d=a%10;
		c+=(d-(j<d))*p[n-i-1];
		if (d==j) break;
		else j=d, a/=10;
	} return c-p[n-1];
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	for (int i = 1; i < 20; ++i) {
		p[i]=p[i-1]*9;
	}

	int a, b;
	cin >> a >> b;
	cout << count(b+1)-count(a) << '\n';

	return 0;
}