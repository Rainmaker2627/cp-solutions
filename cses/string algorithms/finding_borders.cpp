#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	string s;
	cin >> s;

	int n=s.length(), l=0, r=0;
	vector<int> z(n);
	for (int i = 1; i < n; ++i) {
		if (i<=r) z[i]=min(z[i-l], r-i);
		while (i+z[i]<n && s[i+z[i]]==s[z[i]]) z[i]++;
		if (z[i]+i>r) r=z[i]+i, l=i;
	}

	for (int i = n-1; i > 0; --i) {
		if (i+z[i]==n) cout << n-i << ' ';
	} cout << '\n';

	return 0;
}