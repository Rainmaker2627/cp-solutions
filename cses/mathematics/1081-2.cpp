#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m=0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		m=max(m, a[i]);
	}

	int g=0;
	vector<bool> p(m+1, false);
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j*j <= a[i]; ++j) {
			if (a[i]%j) continue;
			int b=a[i]/j;
			if (p[b]) g=max(g, b);
			if (p[j]) g=max(g, j);
			p[b]=p[j]=true;
		}
	} cout << g << '\n';

	return 0;
}