#include<bits/stdc++.h>
using namespace std;

void solve(int n, int from, int to, int unused) {
	if (n==1) {
		cout << from << ' ' << to << '\n';
	} else {
		solve(n-1, from, unused, to);
		cout << from << ' ' << to << '\n';
		solve(n-1, unused, to, from);
	}
}

int main() {
	int n;
	cin >> n;
	cout << pow(2, n)-1 << '\n';
	solve(n, 1, 3, 2);
	cin >> n;
}