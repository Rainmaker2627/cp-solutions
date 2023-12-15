/*
ID: jacobse1
LANG: C++
TASK: dualpal
*/
#include<bits/stdc++.h>
using namespace std;

string tobase(int n, int b) {
	string s = "";
	while (n) {
		s+=n%b+'0';
		n/=b;
	} reverse(s.begin(), s.end());
	return s;
}

bool pal(string s) {
	int n = s.size();
	for (int i = 0; i < n/2; ++i) {
		if (s[i]!=s[n-i-1]) return false;
	} return true;
}

int main() {
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");

	int n, s;
	fin >> n >> s;
	while (n) {
		int t = 0; s++;
		for (int i = 2; i <= 10 && t<2; ++i) if (pal(tobase(s, i))) t++;
		if (t>=2) { n--; fout << s << '\n'; }
	}

	return 0;
}