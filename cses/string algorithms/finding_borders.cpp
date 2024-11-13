#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	string s;
	cin >> s;

	int n=s.length();
	vector<int> z(n, 0), a;
	int l=0, r=0;
	for (int i = 1; i < n; ++i) {
		if (i<r) z[i]=min(r-i, z[i-l]);
		while (i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
		if (r<i+z[i]) r=i+z[i], l=i;
		if (z[i]==n-i) a.push_back(n-i);
	}

	reverse(a.begin(), a.end());
	for (auto i : a) {
		cout << i << ' ';
	}

	return 0;
}