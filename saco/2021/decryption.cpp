#include<bits/stdc++.h>
using namespace std;

string shift(string w, int k) {
	string s;
	for (int i = 0; i < w.length(); ++i) s+='A'+(w[i]-'A'+k)%26;
	sort(s.begin(), s.end());
	return s;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) cin >> s[i];

	unordered_map<string, string> d;
	for (int i = 0; i < 71778; ++i) {
		string w, o;
		cin >> w; o=w;
		sort(w.begin(), w.end());
		d[w]=o;
	}

	for (int k = 0; k < 26; ++k) {
		vector<string> m;
		for (int i = 0; i < n; ++i) {
			string t=shift(s[i], k);
			if (d.count(t)) m.push_back(t);
			else break;
		}

		if (m.size()==n) {
			cout << (26-k)%26 << '\n';
			for (int i = 0; i < n; ++i) {
				cout << d[m[i]] << ' ';
			} cout << '\n';
			break;
		}
	}

	return 0;
}