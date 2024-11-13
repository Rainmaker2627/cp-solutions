#include<bits/stdc++.h>
using namespace std;

long double exp(long double a, int b) {
	double x=1;
	while (b) {
		if (b%2) x*=a;
		a*=a;
		b/=2;
	} return x;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	long double s=0, c=1, p=0;
	for (long double i = 1; i <= k; ++i) {
		c=exp(i/k, n);
		s+=i*(c-p);
		p=c;
	}

	cout << fixed << setprecision(6) << s << '\n';
	return 0;
}