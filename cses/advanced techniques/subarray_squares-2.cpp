#include<bits/stdc++.h>
using namespace std;
#define int long long

struct line {
    int m, c, i;
    int operator[](int x) { return m*x+c; }
    bool useless(line a, line b) {
        return (a.c-b.c)*(m-a.m)<=(a.c-c)*(b.m-a.m);
    }
};

struct cht {
    deque<line> dq;

    void add(line l) {
        while (dq.size()>1 && dq[dq.size()-1].useless(dq[dq.size()-2], l)) dq.pop_back();
        dq.push_back(l);
    }

    line query(int x) {
        while (dq.size()>1 && dq[0][x]>dq[1][x]) dq.pop_front();
        return dq.front();
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k, m=0;
	cin >> n >> k;
	vector<int> pre(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> pre[i];
        m=max(m, pre[i]);
		pre[i]+=pre[i-1];
	}

    int ans=-1;
    int l=0, r=pre[n]*pre[n]+1;
    while (l<r) {
        int mid=(l+r)/2;
        cht lines;
        vector<int> dp(n+1, 0), c(n+1, 0);
        dp[1]=pre[1]*pre[1]; c[1]=1;
        lines.add({-2*pre[1], 2*dp[1], 1});
        for (int i = 2; i <= n; i++) {
            auto j=lines.query(pre[i]);
            if (j[pre[i]]+mid<0) {
                dp[i]=pre[i]*pre[i]+j[pre[i]]+mid;
                c[i]=c[j.i]+1;
            } else {
                dp[i]=pre[i]*pre[i];
                c[i]=1;
            } lines.add({-2*pre[i], dp[i]+pre[i]*pre[i], i});
        }
        if (c[n]>k) l=mid+1;
        else r=mid, ans=dp[n]-mid*(k-1);
    } cout << ans << '\n';

    return 0;
}