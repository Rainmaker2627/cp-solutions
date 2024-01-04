#include<bits/stdc++.h>
#include "shoes.h"
using namespace std;

struct segtree {
	int n;
	vector<int> st;

	segtree(int a) {
		n=a;
		while (n&(n-1)) n++;
		vector<int> b(2*n);
		swap(b, st);
	}

	int query(int ql, int qr, int v=1, int nl=1, int nr=-1) {
		if (nr==-1) { nr=this->n; ql++; qr++; }
		if (ql>nr || qr<nl) return 0;
		if (ql<=nl && qr>=nr) return st[v];
		return query(ql, qr, 2*v, nl, (nl+nr)/2) + query(ql, qr, 2*v+1, (nl+nr)/2+1, nr);
	}

	void update(int p) {
		for (p+=n; p>0; p/=2) st[p]++;
	}

	int operator[](int a) { return st[a+n]; }
};

long long count_swaps(vector<int> s) {
	int n = s.size();
	queue<int> left[n+1], right[n+1];
	segtree st(n);

	for (int i = 0; i < n; ++i) {
		if (s[i]<0) {
			left[-s[i]].push(i);
		} else right[s[i]].push(i);
	}

	long long ans=0;
	for (int i = 0; i < n; ++i) {
		while (i<n && st[i]) i++;
		if (i>=n) break;
		if (s[i]<0) {
			ans+=right[-s[i]].front()-i-1-st.query(i, right[-s[i]].front());
			st.update(right[-s[i]].front());
			right[-s[i]].pop(); left[-s[i]].pop();
		} else {
			ans+=left[s[i]].front()-i-st.query(i, left[s[i]].front());
			st.update(left[s[i]].front());
			left[s[i]].pop(); right[s[i]].pop();
		}
	}

	return ans;
}