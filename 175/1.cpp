#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

bool checkIfExist(vector<int>& arr) {
    unordered_map<int, int> _map;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        if(_map.find(2*arr[i]) != _map.end()) {
            return true;
        }
        if(!(arr[i] & 1)) {
            if(_map.find(arr[i] / 2) != _map.end()) {
                return true;
            }
        }
        _map[arr[i]]++;
    }
    return false;
        
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i< n;i++) cin>>A[i];
    cout<<checkIfExist(A);
    return 0;
}