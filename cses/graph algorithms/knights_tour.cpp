#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> sol={
	{6, 19, 58, 37, 4, 17, 60, 47},
	{57, 38, 5, 18, 59, 48, 15, 62},
	{20, 7, 36, 3, 16, 61, 46, 49},
	{39, 56, 29, 32, 35, 2, 63, 14},
	{8, 21, 34, 1, 30, 27, 50, 45},
	{55, 40, 31, 28, 33, 64, 13, 26},
	{22, 9, 42, 53, 24, 11, 44, 51},
	{41, 54, 23, 10, 43, 52, 25, 12}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int x, y;
	cin >> x >> y;
	int s=64-sol[y-1][x-1];
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cout << (sol[i][j]+s)%64+1 << '\t';
		} cout << '\n';
	}

	return 0;
}