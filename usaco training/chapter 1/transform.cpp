/*
ID: jacobse1
LANG: C++
TASK: transform
*/
#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<char>> board;

int n;

void rotate(board &a) {
	board t(n, vector<char>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			t[i][j]=a[j][n-i-1];
		}
	} swap(a, t);
}

void flip(board &a) {
	board t(n, vector<char>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			t[i][j]=a[i][n-j-1];
		}
	} swap(a, t);
}

bool check(board &a, board &b) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j]!=b[i][j]) return false;
		}
	} return true;
}

int main() {
	ifstream fin("transform.in");
	ofstream fout("transform.out");

	fin >> n;
	board b(n, vector<char>(n)), o(n, vector<char>(n));
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) fin >> o[i][j];
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) fin >> b[i][j];

	int a=7;
	for (int i = 0; i < 4; ++i) {
		if (check(o, b)) { a=min(a, (i==0?6:i)); }
		rotate(b);
	} flip(b);
	for (int i = 0; i < 4; ++i) {
		if (check(o, b)) { a=min(a, (i==0?4:5)); }
		rotate(b);
	}
	
	fout << a << '\n';
	return 0;
}