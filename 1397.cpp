#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}


#define MOD 1e9+7

string e;


void add(int &x, int y) {
    if((x += y) >= MOD) x -= MOD;
}


int findGoodStrings(int n, string s1, string s2, string evil) {
    const int m = evil.length();
    vector<int> next(m + 1);
    next[0] = -1;
    


}



int main() {
    int n;
    cin>>n;
    string s1, s2, s3;
    cin>>s1>>s2>>s3;
    cout<<findGoodStrings(n, s1, s2, s3)<<'\n';
    return 0;
}