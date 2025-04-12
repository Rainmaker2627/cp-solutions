#include<bits/stdc++.h>
using namespace std;

// im not sure how the cses grader is intended to work, but im sure this code works
int main() {
    cin.tie(0)->sync_with_stdio(false);

    vector<int> sets;
    for (int i = 0; i < 4096; i++) {
        if (__popcount(i)==6) sets.push_back(i);
    }
    
    int h, n, t;
    cin >> h >> n >> t;
    if (h==1) {
        for (int i = 0; i < t; i++) {
            int x, y;
            cin >> x >> y;
            int r=(sets[x]^sets[y])&sets[x], s=1;
            while (r%2==0) r>>=1, s++;
            cout << s << '\n';
        }
    } else {
        for (int i = 0; i < t; i++) {
            int q, h;
            cin >> q >> h;
            if (sets[q]&(1<<(h-1))) cout << "yes\n";
            else cout << "no\n";
        }
    }

    return 0;
}