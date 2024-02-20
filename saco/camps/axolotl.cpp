#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll a) {
	if (a<10) return a;
	string s = to_string(a);
	ll n=a/10+9;
	if (s[0]>s[s.size()-1]) n--;
	return n;
}

int main() {
	ll l, r;
	cin >> l >> r;
	cout << f(r)-f(l-1) << '\n';
	cin >> r;
	return 0;
}