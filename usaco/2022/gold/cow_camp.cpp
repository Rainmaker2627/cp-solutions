#include<bits/stdc++.h>
using namespace std;
#define double long double

double pow(double a, int b) {
    double x=1;
    while (b) {
        if (b%2) x=x*a;
        a=a*a; b/=2;
    } return x;
}

double next(double e, int d, double m, double c) {
    double r=pow(m, d);
    return r*e+(r-1)/(m-1)*c;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t, k;
    cin >> t >> k;

    vector<double> fact(t+1, 1);
    for (int i = 2; i <= t; i++) {
        fact[i]=i*fact[i-1];
    } 
    
    double inv=pow(0.5f, t-1);
    vector<double> prob(t, 0), exp(t, 0);
    for (int i = 0; i < t; i++) {
        prob[i]=inv*fact[t-1]/fact[i]/fact[t-i-1];
        exp[i]=prob[i]*(t-i-1);
        if (i==0) continue;
        prob[i]+=prob[i-1];
        exp[i]+=exp[i-1];
    } reverse(exp.begin(), exp.end());
    exp.push_back(0);

    k--;
    double e=exp[0];
    while (k) {
        int l=1, r=k;
        while (l<r) {
            int mid=(l+r)/2;
            double t=next(e, mid, prob[(int) e], exp[(int) e+1]);
            if ((int) t>(int) e) r=mid;
            else l=mid+1;
        } e=next(e, l, prob[(int) e], exp[(int) e+1]); k-=l;
    } cout << setprecision(20) << e+1 << '\n';

    return 0;
}