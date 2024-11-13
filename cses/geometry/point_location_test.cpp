#include<bits/stdc++.h>
using namespace std;
#define int long long

struct vect {
	int x, y;

	vect operator-(vect b) { return {x-b.x, y-b.y}; }
	int operator*(vect b) { return x*b.y-y*b.x; }
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		vect a{x1, y1}, b{x2, y2}, c{x3, y3};
		int rep=(a-b)*(c-b);
		if (rep<0) cout << "LEFT\n";
		else if (rep>0) cout << "RIGHT\n";
		else cout << "TOUCH\n";
	}

	return 0;
}