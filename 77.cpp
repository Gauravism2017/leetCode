#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

int k, n;

void combine(vector<vector<int>> & ans, vector<int> temp, int start) {
    if(temp.size() == k) {
        ans.push_back(temp);
        return;
    }
    for(int i = start; i <= n; i++) {
        temp.push_back(i);
        combine(ans, temp, i + 1);
        temp.pop_back();
    }
}


vector<vector<int>> combine(int _n, int _k) {
    k = _k;
    n = _n;
    vector<vector<int>> ans;
    vector<int> temp;
    combine(ans, temp, 1);
    return ans;
}


int main() {
    int a, b;
    cin>>a>>b;
    print2D(combine(a, b));
    return 0;
}