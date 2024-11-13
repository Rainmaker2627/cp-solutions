#include<bits/stdc++.h>
using namespace std;
 
int n, x;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	cin >> n >> x;
	vector<int> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	} sort(s.begin(), s.end());
 
	int c=0, i=0, j=n-1;
	while (i<=j) {
		if (s[i] + s[j] <= x) i++;
		c++; j--;
	} cout << c << '\n';

	return 0;
}