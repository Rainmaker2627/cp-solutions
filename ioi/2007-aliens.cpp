#include<bits/stdc++.h>
using namespace std;

int n, xs, ys;

bool inside(int i, int j) { return (i>0 && j>0 && i<=n && j<=n); }

bool examine(int i, int j) {
	if (!inside(i, j)) return false;
	cout << "examine " << i << ' ' << j << endl;
	string s;
	cin >> s;
	return (s[0]=='t');
}

int find(int r, int d) {
	int i=1;
	while (examine(xs+(r<<i)-r, ys+(d<<i)-d)) i++;
	int lo=(1<<(i-1))-1, hi=(1<<i)-1;
	while (lo+1<hi) {
		int mid=(lo+hi)/2;
		if (examine(xs+mid*r, ys+mid*d)) lo=mid;
		else hi=mid;
	} return hi;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> xs >> ys;
	int r=find(1, 0), l=find(-1, 0), t=find(0, -1);
	int sz=l+r-1;
	int x=xs-l+1+sz/2, y=ys-t+sz/2+1;

	while(examine(x+2*sz, y)) x+=2*sz;
	while(examine(x, y+2*sz)) y+=2*sz;
	while(examine(x+sz, y+sz)) x+=sz, y+=sz;

	cout << "solution " << x-2*sz << ' ' << y-2*sz << endl;
	return 0;
}