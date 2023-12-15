#include<bits/stdc++.h>
using namespace std;
#define N 300

int r[N][N];

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			cin >> r[i][j];
		}
	}

	int j=0;
	vector<int> a(n);
	a[0]=0; a[1]=r[0][1];
	for (int i = 2; i < n; ++i) {
		if (r[i-1][i]==0) {
			a[i]=a[i-1];
		} else {
			if (r[j][i]==r[j][i-1]) a[i]=a[i-1]+(a[j]<a[i-1]?-1:1)*r[i-1][i];
			else if (r[j][i]==r[i-1][i]) a[i]=a[i-1]+(a[j]<a[i-1]?-1:1)*r[i-1][i];
			else a[i]=a[i-1]+(a[j]<a[i-1]?1:-1)*r[i-1][i];
			j=i-1;
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << a[i] << (i==n-1?'\n':' ');
	}
	return 0;
}