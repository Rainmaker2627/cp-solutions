#include<bits/stdc++.h>
using namespace std;

int n;
string s;
vector<int> c;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=0;
	cin >> n >> s;

	for (int i = 0; i <= n; ++i) {
		if (i!=n && s[i]=='1') t++;
		else if (t>0) {
			c.push_back(t);
			t=0;
		}
	} if (t>0) c.push_back(t);

	int a=0, b=c.size(), m=1e9, v=0;
	if (s[0]=='1') { m=min(m, c[a++]-1); }
	if (s[n-1]=='1') { m=min(m, c[--b]-1); }
	for (int i = a; i < b; ++i) m=min(m, (c[i]-1)/2);
	for (auto i : c) v+=i/(2*m+1)+(i%(2*m+1)>0);

	cout << v << '\n';
	return 0;
}