#include<bits/stdc++.h>
using namespace std;
#define int long long

int mid;
vector<int> e;
int f(int n, int p=1) {
	if (n<10) return n*(p-1)*e[p-1]+max((int)0, min((p==18?mid:mid%e[p+1])-e[p], e[p]));
	return f(n%10, p)+f(n/10, p+1);
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	e.assign({0, 1});
	for (int i = 1; i <= 18; ++i) {
		e.push_back(e[i]*10);
	}

	int l=1, r=1e18;
	while (l<r) {
		mid=(l+r)/2;
		if (f(mid)<n+1) l=mid+1;
		else r=mid;
	} cout << l-2 << '\n';

	return 0;
}