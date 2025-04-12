#include<bits/stdc++.h>
using namespace std;

struct segtree {
    int n;
    unordered_map<int, int> cc;
    vector<int> st;

    segtree(vector<int>& x) {
        int t=1;
        sort(x.begin(), x.end());
        cc[x[0]]=t++;
        for (int i = 1; i < x.size(); i++) {
            if (x[i]==x[i-1]) continue;
            cc[x[i]]=t++;
        } n=t;
        while (n&(n-1)) n++;
        st.assign(2*n, 0);
    }

    int query(int l, int r, int n=1, int nl=1, int nr=1) {
        if (n==1) { nr=this->n; l=cc[l]; r=cc[r]; }
        if (nr<l || r<nl) return 0;
        if (l<=nl && nr<=r) return st[n];
        return query(l, r, 2*n, nl, (nr+nl)/2)+query(l, r, 2*n+1, (nl+nr)/2+1, nr);
    }

    void update(int p, int v, int n=1, int nl=1, int nr=1) {
        if (n==1) { nr=this->n; p=cc[p]; }
        if (nr<p || p<nl) return;
        if (nl==nr) { st[n]+=v; return; }
        update(p, v, 2*n, nl, (nl+nr)/2);
        update(p, v, 2*n+1, (nl+nr)/2+1,  nr);
        st[n]=st[2*n]+st[2*n+1];
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> xs, tr(n);
        for (int i = 0; i < n; i++) {
            cin >> tr[i];
            xs.push_back(tr[i]);
        } sort(tr.begin(), tr.end());

        vector<pair<pair<int, int>, int>> rs;
        for (int i = 0; i < k; i++) {
            int l, r, t;
            cin >> l >> r >> t;
            rs.push_back({{r, l}, t});
            xs.push_back(l);
            xs.push_back(r);
        } sort(rs.begin(), rs.end());
        
        int j=0;
        segtree st(xs);
        priority_queue<int> pq;
        for (int i = 0; i < k; i++) {
            auto [t, v]=rs[i];
            auto [r, l]=t;
            while (tr[j]<=r) pq.push(tr[j++]);
            int q=st.query(l, r);
            while (q<v) {
                int x=pq.top();
                st.update(x, 1);
                pq.pop();
                q++;
            }
        }
        
        cout << n-st.query(tr[0], tr[n-1]) << '\n';
    }

    return 0;
}