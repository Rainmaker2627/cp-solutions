#include<bits/stdc++.h>
using namespace std;
#define int long long
 
struct query {
	int a, b, i;
	bool operator<(query t) {
		if (a==t.a) return b<t.b;
		return a<t.a;
	}
};
 
signed main() {
	cin.tie(0)->sync_with_stdio(false);
 
	int n, q;
	cin >> n >> q;
	vector<int> x(n), p(n+1, 0);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		p[i+1]=p[i]+x[i];
	}
 
	vector<query> que(q);
	for (int i = 0; i < q; ++i) {
		cin >> que[i].a >> que[i].b;
		que[i].i=i;
	} sort(que.begin(), que.end());
 
	int i=n, c=q;
	vector<int> ans(q, 0);
	vector<int> val{(int) 1e9+1}, pos{n}, sum{0};
	while (c--) {
		que[c].a--; que[c].b--;
		while (i>que[c].a) {
			i--;
			int l=val.size();
			int nsum=sum[l-1];
			while (val[--l]<=x[i]) {
				nsum+=(x[i]-val[l])*(pos[l-1]-pos[l]);
				val.pop_back(); pos.pop_back(); sum.pop_back();
			}
			val.push_back(x[i]);
			pos.push_back(i);
			sum.push_back(nsum);
		}
		auto lb=lower_bound(pos.begin(), pos.end(), que[c].b, greater<int>())-pos.begin();
		ans[que[c].i]=sum.back()-sum[lb-1]-(val[lb]*(pos[lb-1]-que[c].b-1)-(p[pos[lb-1]]-p[que[c].b+1]));
	}
 
	for (int i = 0; i < q; ++i) {
		cout << ans[i] << '\n';
	}
 
	return 0;
}