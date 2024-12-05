#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	map<char, int> m; m['#']=26;
	for (int i = 'a'; i <= 'z'; ++i) m[i]=i-'a';

	string s, c;
	cin >> s; c=s;
	sort(c.begin(), c.end());

	int n=s.length();
	vector<int> f(n);
	vector<queue<int>> adj(27);
	for (int i = 0; i < n; ++i) adj[m[s[i]]].push(i);
	for (int i = 0; i < n; ++i) { f[i]=adj[m[c[i]]].front(); adj[m[c[i]]].pop(); }

	int b=f[0];
	string r;
	while (b) {
		r.push_back(c[b]);
		b=f[b];
	} cout << r << '\n';

	return 0;
}