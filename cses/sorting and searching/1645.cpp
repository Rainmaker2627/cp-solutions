#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	stack<pii> s;
	s.push({0, 0});
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		while (x<=s.top().first) {
			s.pop();
		} cout << s.top().second << ' ';
		s.push({x, i+1});
	} cout << '\n';

	return 0;
}