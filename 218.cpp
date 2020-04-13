#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> vec;
    for(auto b : buildings) {
        vec.push_back({b[0], b[2]});
        vec.push_back({b[1], b[2]});
    }
    sort(vec.begin(), vec.end());
    for(auto p : vec) {
        cout<<p.first<<" "<<p.second<<'\n';
    }
}


int main() {
    int n;
    cin>>n;
    vector<vector<int>> A(n, vector<int>(3, 0));
    for(int i = 0; i< n;i++) {
        for(int j = 0; j < 3; j++) {
            cin>>A[i][j];
        }
    }
    return 0;
}