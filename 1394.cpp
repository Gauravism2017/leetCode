#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}


int findLucky(vector<int>& arr) {
    unordered_map<int, int> _map;
    for(auto d : arr) _map[d]++;
    int mx = INT_MIN;
    for(auto p : _map) {
        if(p.first == p.second) {
            mx = max(mx, p.first);
        }
    }
    return (mx == INT_MIN) ? -1 : mx;

}


int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i< n;i++) cin>>A[i];
    cout<<findLucky(A)<<'\n';
    return 0;
}