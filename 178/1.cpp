#include <bits/stdc++.h>

using namespace std;

template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

vector<int> smallerNumbersThanCurrent(vector<int>& A) {
    vector<int> v = A;
    sort(v.begin(), v.end());
    unordered_map<int, int> _map;
    int n = v.size();
    // for(auto d : v) {
    //     _map[d]++;
    // }
    // int count = 0;
    // int temp;
    // for(auto p : _map) {
    //     temp = p.second;
    //     _map[p.first] = count;
    //     cout<<"temp "<<temp<<" count "<<count<<'\n';
    //     count += temp;
    // }
    for(int i = n - 1; i >= 0; i--) _map[v[i]] = i;
    vector<int> ans;
    for(auto d: A) ans.emplace_back(_map[d]);
    // cout<<A.size();
    return ans;
        
}

int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin>>A[i];
    }
    vector<int> ans = smallerNumbersThanCurrent(A);
    print(ans);
    return 0;

}