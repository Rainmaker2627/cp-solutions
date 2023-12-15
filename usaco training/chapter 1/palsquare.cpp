/*
ID: jacobse1
LANG: C++
TASK: palsquare
*/
#include<bits/stdc++.h>
using namespace std;

string tobase(int n, int b) {
	string s = "";
	while (n) {
		s+="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n%b];
		n/=b;
	} reverse(s.begin(), s.end());
	return s;
}

int main() {
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");

	int b;
	fin >> b;
	for (int i = 1; i <= 300; ++i) {
		string s = tobase(i*i, b);
		int n = s.size(), t=1;
		for (int i = 0; i < n/2 && t; ++i) {
			if (s[i]!=s[n-i-1]) t=0;
		} if (t) { fout << tobase(i, b) << ' ' << s << '\n'; }
	}

	return 0;
}