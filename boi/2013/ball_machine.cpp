#include<bits/stdc++.h>
using namespace std;

struct lazy {
    int sz;
    vector<int> st, lz;

    lazy(vector<int>& ord) {
        sz=ord.size();
        while (sz&(sz-1)) sz++;
        st.assign(2*sz, 0);
        for (int i = sz; i < sz+ord.size(); i++) st[i]=1;
        for (int i = sz-1; i > 0; i--) st[i]=st[2*i]+st[2*i+1];
        lz.assign(2*sz, 0);
    }

    int find(int x, int n=1, int nl=1, int nr=1) {
        if (n==1) nr=sz;
        push(n, nl, nr);
        if (nl==nr) return nl;
        if (st[2*n]>=x) return find(x, 2*n, nl, (nl+nr)/2);
        else return find(x-st[2*n], 2*n+1, (nl+nr)/2+1, nr);
    }

    void push(int n, int l, int r) {
        if (lz[n]==0) return;
        if (l<r) lz[2*n]=lz[2*n+1]=1;
        st[n]=lz[n]=0;
    }

    void set(int l, int r, int v, int n=1, int nl=1, int nr=1) {
        if (n==1) nr=sz;
        push(n, nl, nr);
        if (nr<l || r<nl) return;
        if (l<=nl && nr<=r) {
            if (v==0) { lz[n]=1; push(n, nl, nr); return; }
            else { st[n]=1; return; }
        }
        set(l, r, v, 2*n, nl, (nl+nr)/2);
        set(l, r, v, 2*n+1, (nl+nr)/2+1, nr);
        st[n]=st[2*n]+st[2*n+1];
    }

    int get(int p, int n=1, int nl=1, int nr=1) {
        if (n==1) nr=sz;
        push(n, nl, nr);
        if (nl==nr) return st[n];
        else if (p<=(nl+nr)/2) return get(p, 2*n, nl, (nl+nr)/2);
        else return get(p, 2*n+1, (nl+nr)/2+1, nr);
    }
};

const int inf=1e9;
vector<int> dp;
vector<vector<int>> cld;
bool comp(int u, int v) { return dp[u]<dp[v]; }
void dfs(int u) {
    dp[u]=min(dp[u], u);
    for (auto v : cld[u]) {
        dfs(v);
        dp[u]=min(dp[v], dp[u]);
    } sort(cld[u].begin(), cld[u].end(), comp);
}

vector<int> tin, tout, ord;
void eul(int u) {
    tin[u]=ord.size()+1;
    for (auto v : cld[u]) eul(v);
    ord.push_back(u);
    tout[u]=ord.size();
}

/*
O(lgn) for q1 and O(lg^2n) for q2.
Can be optimised to O(lgn) by changing q1 to O(klgn) per query using a normal segtree
which seems worse but amoritizes to O((n+q)lgn)
but this works despite being overkill
*/
int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, q, r;
    cin >> n >> q;
    vector<int> par(n+1, 0);
    cld.assign(n+1, vector<int>());
    for (int i = 1; i <= n; i++) {
        cin >> par[i];
        cld[par[i]].push_back(i);
        if (par[i]==0) r=i;
    }

    dp.assign(n+1, inf);
    for (int i = 1; i <= n; i++) dp[i]=i;
    dfs(r);

    tin.assign(n+1, 0);
    tout.assign(n+1, 0);
    eul(r);
    lazy st(ord);

    int lg=0;
    while (n>=(1<<lg)) lg++;
    vector<vector<int>> bl(n+1, vector<int>(lg+1, 0));
    for (int i = 1; i <= n; i++) bl[i][0]=par[i];
    for (int i = 1; i <= lg; i++) {
        for (int j = 1; j <= n; j++) {
            bl[j][i]=bl[bl[j][i-1]][i-1];
        }
    }

    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t==1) {
            int r=st.find(x);
            st.set(1, r, 0);
            cout << ord[r-1] << '\n';
        } else {
            int r=x, a=0;
            for (int i = lg; i >= 0; i--) {
                if (bl[r][i]==0 || st.get(tout[bl[r][i]])==1) continue;
                a+=1<<i; r=bl[r][i];
            } st.set(tout[r], tout[r], 1);
            cout << a << '\n';
        }
    }

    return 0;
}