#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
struct node {
    int val=-1;
    node *rep, *l, *r;

    node* find() {
        if (rep==nullptr) return this;
        return rep=rep->find();
    }

    void dfs(bool p=false, int v=0) {
        if (val>-1) {
            ans[val]=v;
        } else {
            l->dfs(true, v);
            r->dfs(false, v+p);
        }
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> p(n);
    vector<node*> nd(n+1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        nd[i]=new node{i};
    } nd[n]=new node{n};
    
    ans.assign(n+1, 0);
    for (int i = n-1; i >= 0; i--) {
        auto a=nd[p[i]-1], b=nd[p[i]];
        a=a->find(); b=b->find();
        node* rep=new node{-1, nullptr, a, b};
        a->rep=b->rep=rep;
    } nd[0]->find()->dfs();
    
    for (int i = 0; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}