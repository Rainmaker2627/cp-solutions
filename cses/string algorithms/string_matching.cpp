#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	string s, p;
	cin >> s >> p;
	s=p+'#'+s;

	int n=s.size();
	vector<int> z(n);
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		if (i<r) z[i]=min(r-i, z[i-l]);
		while (i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
		if (i+z[i]>r) r=z[i]+i, l=i;
	}

	int t=0;
	for (auto i : z) {
		if (i==p.size()) t++;
	} cout << t << '\n';

	return 0;
}