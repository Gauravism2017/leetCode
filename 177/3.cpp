#include <bits/stdc++.h>

using namespace std;

template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

template<typename T>
void print(T vec) {
    for(auto d : vec) cout<<d<<' ';
    cout<<'\n';
}

int divisor(int n) {
    int d = sqrt(n);
    while(n % d) --d;
    return d;
}

vector<int> closestDivisors(int n) {
    int d1 = divisor(n + 2), d2 = divisor(n + 1);
    if(abs(d1 - (n + 2) / d1) > abs(d2 - (n + 1)/d2)) {
        return {d2, (n + 1)/d2};
    }
    else{
        return {d1, (n + 2) / d1};
    }

}

int main() {
    int n;
    cin>>n;
    vector<int> ans = closestDivisors(n);
    print(ans);
    return 0;
}