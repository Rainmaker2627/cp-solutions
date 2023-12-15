/*
ID: jacobse1
LANG: C++
TASK: beads
*/
#include<bits/stdc++.h>
using namespace std;

int r[2][700], b[2][700];

int main() {
	ifstream fin("beads.in");
	ofstream fout("beads.out");

	int n;
	string s;
	fin >> n >> s;
	n*=2; s+=s;

	for (int i = 1; i < n; ++i) {
		if (s[i-1]=='r') r[0][i]=r[0][i-1]+1;
		else if (s[i-1]=='b') b[0][i]=b[0][i-1]+1;
		else { r[0][i]=r[0][i-1]+1; b[0][i]=b[0][i-1]+1; }
	} for (int i = n-1; i >= 0; --i) {
		if (s[i]=='r') r[1][i]=r[1][i+1]+1;
		else if (s[i]=='b') b[1][i]=b[1][i+1]+1;
		else { r[1][i]=r[1][i+1]+1; b[1][i]=b[1][i+1]+1; }
	}

	int a=0;
	for (int i = 0; i <= n; ++i) {
		a=max(max(b[0][i], r[0][i]) + max(b[1][i], r[1][i]), a);
	}

	fout << min(a, n/2) << '\n';
	return 0;
}