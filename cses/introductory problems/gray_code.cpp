#include<bits/stdc++.h>
using namespace std;

void gray(int n, string& p, bool r=false) {
	if (n==1) {
		cout << p << (char)('0'^r) << '\n';
		cout << p << (char)('1'^r) << '\n';
	} else {
		p.push_back((char)('0'^r));
		gray(n-1, p);
		p.pop_back();
		p.push_back((char)('1'^r));
		gray(n-1, p, true);
		p.pop_back();
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	string p="";
	gray(n, p);

	return 0;
}