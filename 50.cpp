#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

double myPow(double x, int n) {
    int sign = 1;
    if(n < 0) sign = -1;
    double res = 1.0;
    for(int i = n; i; i /= 2) {
        if(i & 1) res*=x;
        x*=x;
    }
    return sign == -1 ? 1/res : res;
}


int main() {
    double n;
    double x;
    cin>>x>>n;
    cout<<myPow(x, n);
    return 0;
}