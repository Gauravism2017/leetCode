#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
}

int main() {
    int n;
    cin>>n;
    vector<int> A(n), B(n);
    for(int i = 0; i< n;i++) cin>>A[i];
    for(int i = 0; i< n;i++) cin>>B[i];
    cout<<findMedianSortedArrays(A, B)<<'\n';
    return 0;
}