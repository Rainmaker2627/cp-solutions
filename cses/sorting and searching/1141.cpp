#include<bits/stdc++.h>
using namespace std;
 
int n;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	cin >> n;
	vector<int> k(n);
	for (int i = 0; i < n; ++i) {
		cin >> k[i];
	}
 
	int c=0, m=0, j=0;
	set<int> s;
	for (int i = 0; i < n; ++i) {
		if (s.count(k[i])) {
			do {
				s.erase(k[j]);
				c--;
			} while (k[i]!=k[j++]);
		}
		s.insert(k[i]);
		m=max(++c, m);
	}
 
	cout << m << '\n';
	return 0;
}