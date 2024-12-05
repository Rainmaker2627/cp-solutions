#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	string s;
	cin >> s;
	map<char, int> m;
	for (int i = 0; i < s.length(); ++i) {
		m[s[i]]++;
	}

	string r;
	char o='.';
	for (char i = 'A'; i <= 'Z'; ++i) {
		if (m[i]%2) {
			if (o=='.') o=i;
			else { cout << "NO SOLUTION\n"; return 0; }
		} else {
			for (int j = 0; j < m[i]/2; ++j) r+=i;
		}
	} for (int j = 0; j < m[o]; ++j) r+=o;
	for (char i = 'Z'; i >= 'A'; --i) {
		if (m[i]%2) continue;
		for (int j = 0; j < m[i]/2; ++j) r+=i;
	} cout << r << '\n';

	return 0;
}