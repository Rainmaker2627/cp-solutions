#include<bits/stdc++.h>
using namespace std;

bool sus(string s) {
	int n=s.length();
	stack<int> A, B;
	for (int i = 0; i < n; ++i) {
		if (s[i]=='A') {
			if (!A.empty() && (B.empty() || B.top()<A.top())) A.pop();
			else A.push(i);
		} else {
			if (!B.empty() && (A.empty() || A.top()<B.top())) B.pop();
			else B.push(i); 
		}
	} return A.empty() && B.empty();
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, r=0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (sus(s)) r++;
	} cout << r << '\n';

	return 0;
}