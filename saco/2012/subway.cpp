#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_cxx;
using namespace std;

struct tree {
	int n, r=1;
	vector<int> ss, p;
	vector<vector<int>> e;
	rope<char> rep;

	tree(string s) {
		n=s.size()/2+1;
		p.assign(n+1, -1);
		ss.assign(n+1, 0);
		e.assign(n+1, vector<int>());
		int a=1, b=1;
		for (auto i : s) {
			if (i=='0') {
				e[a].push_back(++b);
				e[b].push_back(a);
				p[b]=a;
				ss[b]=1;
				a=b;
			} else {
				ss[p[a]]+=ss[a];
				a=p[a];
			}
		}
		center();
		rep=represent(r);
	}

	void center() {
		for (auto i : e[r]) {
			if (ss[i]>n/2) {
				p[i]=-1;
				p[r]=i;
				ss[r]-=ss[i];
				ss[i]+=ss[r];
				r=i;
				center();
				return;
			} else if (ss[i]==n/2 && n%2==0) {
				p[i]=0;
				p[r]=0;
				e[0].push_back(i);
				e[0].push_back(r);
				e[i].erase(find(e[i].begin(), e[i].end(), r));
				e[r].erase(find(e[r].begin(), e[r].end(), i));
				ss[r]-=ss[i];
				ss[0]=n;
				r=0;
			}
		}
	}

	rope<char> represent(int n) {
		vector<rope<char>> t;
		for (auto i : e[n]) {
			if (i==p[n]) continue;
			t.push_back(represent(i));
		}
		sort(t.begin(), t.end());
		rope<char> r = "(";
		for (auto i : t) {
			r+=i;
		} r+=")";
		return r;
	}

	bool operator==(tree t2) {
		return rep==t2.rep;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<tree> ts;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		tree t(s);
		bool b=true;
		for (auto i : ts) {
			if (t==i) {
				b=false;
				break;
			}
		}
		if (b) ts.push_back(t);
	}
	
	cout << ts.size() << '\n';

	return 0;
}