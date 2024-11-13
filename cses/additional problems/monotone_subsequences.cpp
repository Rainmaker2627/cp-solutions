#include<bits/stdc++.h>
using namespace std;

int isq(int s) {
	int l=1, r=s;
	while (l<r) {
		int m=(l+r)/2;
		if (m*m>=s) r=m;
		else l=m+1;
	} return l;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (k<isq(n)) {
			cout << "IMPOSSIBLE\n";
			continue;
		} else {
			for (int i = 1; i <= (n-1)/k+1; ++i) {
				for (int j = min(n, i*k); j > (i-1)*k; --j) {
					cout << j << ' ';
				}
			} cout << '\n';
		}
	}

	return 0;
}