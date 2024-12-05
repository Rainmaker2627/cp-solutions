#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	string s, t;
	cin >> s >> t;
	string p=t+'#'+s;

	int n=p.length();
	vector<int> pi(n, 0);
	for (int i = 1; i < n; ++i) {
		int j=pi[i-1];
		while (j>0 && p[i]!=p[j]) j=pi[j-1];
		if (p[j]==p[i]) j++;
		pi[i]=j;
	}

	int c=0;
	for (int i = t.length()+1; i < n; ++i) {
		if (pi[i]==t.length()) c++;
	} cout << c << '\n';

	return 0;
}