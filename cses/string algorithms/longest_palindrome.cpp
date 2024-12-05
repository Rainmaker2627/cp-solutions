#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	string s;
	cin >> s;
	int n=s.length();
	string p="$#"; p+=s[0];
	for (int i = 1; i < n; ++i) {
		p+="#"; p+=s[i];
	} p+="#^";

	n=p.length();
	vector<int> d(n, 0);
	int l=1, r=1, a=0, b=0;
	for (int i = 1; i < n; ++i) {
		if (r>i) d[i]=min(r-i, d[l+r-i]);
		while (p[i-d[i]]==p[i+d[i]]) d[i]++;
		if (i+d[i]>r) r=i+d[i], l=i-d[i];
		if (p[i]=='#' && d[b]<d[i]) b=i;
		if (p[i]!='#' && d[a]<d[i]) a=i;
	}

	if (d[a]/2<(d[b]+1)/2) swap(a, b);
	for (int i = a-d[a]+1; i < a+d[a]; ++i) {
		if (p[i]=='#') continue;
		cout << p[i];
	} cout << '\n';

	return 0;
}