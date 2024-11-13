#include<bits/stdc++.h>
using namespace std;

int f(int n, int k) {
	if (n==1) return 1;
	if (k<=n/2) {
		return 2*k;
	} else {
		if (n%2==0) return 2*f(n/2, k-n/2)-1;
		else return (2*f(n/2+1, k-n/2)+(n-3))%(n+1)+1;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n, k;
		cin >> n >> k;
		cout << f(n, k) << '\n';
	}

	return 0;
}