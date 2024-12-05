#include<bits/stdc++.h>
using namespace std;
 
void solve(int n, int a, int b) {
	if (n==1) {
		cout << a << ' ' << b << '\n';
	} else {
		solve(n-1, a, 6-a-b);
		cout << a << ' ' << b << '\n';
		solve(n-1, 6-a-b, b);
	}
}
 
int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	cout << pow(2, n)-1 << '\n';
	solve(n, 1, 3);

	return 0;
}