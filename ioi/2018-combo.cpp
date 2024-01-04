#include<bits/stdc++.h>
#include "combo.h"
using namespace std;

std::string guess_sequence(int N) {
	vector<string> a;
	string s;

	if (press("AB")) {
		if (press("A")) {
			s="A"; a={"B", "X", "Y"};
		} else {
			s="B"; a={"A", "X", "Y"};
		}
	} else {
		if (press("X")) {
			s="X"; a={"A", "B", "Y"};
		} else {
			s="Y"; a={"A", "B", "X"};
		}
	}

	for (int i = 1; i < N-1; ++i) {
		string p = (s+a[0]+a[0])+(s+a[0]+a[1])+(s+a[0]+a[2])+(s+a[1]);
		int q = press(p);
		if (q==i) s+=a[2];
		else if (q==i+1) s+=a[1];
		else s+=a[0];
	}

	if (N>1) {
		if (press(s+a[0])==N) s+=a[0];
		else if (press(s+a[1])==N) s+=a[1];
		else s+=a[2];
	}

	return s;
}