#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	string s, p;
	cin >> s >> p;
	s=p+'#'+s;

	int n=s.length();
	vector<int> pi(n, 0);
	for (int i = 1; i < n; ++i) {
		int j=pi[i-1];
		while (j>0 && s[i]!=s[j]) j=pi[j-1];
		if (s[i]==s[j]) j++;
		pi[i]=j;
	}

	int x=0;
	for (int i = p.length()+1; i < n; ++i) {
		if (pi[i]==p.length()) x++;
	} cout << x << '\n';

	return 0;
}