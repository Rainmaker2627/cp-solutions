#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	string s, p;
	cin >> s >> p;
	s=p+'#'+s;

	int n=s.length(), l=0, r=0;
	vector<int> z(n, 0);
	for (int i = 1; i < n; ++i) {
		if (i<=r) z[i]=min(z[i-l], r-i);
		while (i+z[i]<n && s[i+z[i]]==s[z[i]]) z[i]++;
		if (i+z[i]>r) r=i+z[i], l=i;
	}

	int t=0;
	for (auto i : z) {
		if (i==p.size()) t++;
	} cout << t << '\n';

	return 0;
}