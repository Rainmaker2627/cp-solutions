#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1001

int n, q;
int f[N][N];

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			char c;
			cin >> c;
			f[i][j]=(c=='*')+f[i][j-1]+f[i-1][j]-f[i-1][j-1];
		}
	}

	for (int i = 0; i < q; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << f[c][d]+f[a-1][b-1]-f[c][b-1]-f[a-1][d] << '\n';
	}

	return 0;
}