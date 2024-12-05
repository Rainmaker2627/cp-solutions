#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	string s;
	cin >> s;

	int n=0, c=1;
	for (int i = 1; i < s.length(); ++i) {
		if (s[i]==s[i-1]) c++;
		else n=max(n, c), c=1;
	} cout << max(n, c) << '\n';

	return 0;
}