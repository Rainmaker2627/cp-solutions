#include<bits/stdc++.h>
using namespace std;
#define int long long

struct node {
    int v, n;
    node *l, *r;

    node* init(vector<int>& t, int nl=1, int nr=0) {
        if (nr==0) {
            n=t.size();
            while (n&(n-1)) n++;
            nr=n;
        }

        if (t.size()<nl) return nullptr;
        if (nl==nr) { v=t[nl-1]; return this; }
        int mid=(nl+nr)/2;
        l=new node{0, n}; l->init(t, nl, mid); v=l->v;
        if (t.size()>=mid) { r=new node{0, n}; r->init(t, mid+1, nr); v+=r->v; }
        return this;
    }

    int query(int ql, int qr, int nl=1, int nr=0) {
        if (nr==0) nr=n;
        if (qr<nl || nr<ql) return 0;
        if (ql<=nl && nr<=qr) return v;
        int mid=(nl+nr)/2;
        return l->query(ql, qr, nl, mid)+(r?r->query(ql, qr, mid+1, nr):0);
    }

    node* set(int a, int x, int nl=1, int nr=0) {
        if (nr==0) nr=n;
        if (nr<a || a<nl) return this;
        if (nl==nr) return new node{x, n};
        int mid=(nl+nr)/2;
        auto pl=l->set(a, x, nl, mid), pr=(r?r->set(a, x, mid+1, nr):nullptr);
        return new node{pl->v+(pr?pr->v:0), n, pl, pr};
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<node*> root;
    root.emplace_back(new node{});
    root[0]->init(t);
    for (int i = 0; i < q; i++) {
        int t, k;
        cin >> t >> k;
        if (t==1) {
            int a, x;
            cin >> a >> x;
            root[k-1]=root[k-1]->set(a, x);
        } else if (t==2) {
            int a, b;
            cin >> a >> b;
            cout << root[k-1]->query(a, b) << '\n';
        } else {
            root.push_back(root[k-1]);
        }
    }
    
    return 0;
}