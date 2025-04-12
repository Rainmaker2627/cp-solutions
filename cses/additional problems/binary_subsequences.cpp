#include<bits/stdc++.h>
using namespace std;

string get(int a, int b) {
    if (a>b) return '1'+get(a-b, b);
    else if (b>a) return '0'+get(a, b-a);
    else return "";
}

int len(int a, int b) {
    if (b==0) return 0;
    return a/b+len(b, a%b);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    int min=++n, ans=1;
    for (int i = 2; i <= n/2; i++) {
        if (__gcd(i, n+1)==1) {
            int res=len(n+1-i, i);
            if (min>res) min=res, ans=i;
        }
    }

    string s=get(n+1-ans, ans);
    cout << s << '\n';

    return 0;
}