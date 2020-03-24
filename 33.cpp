#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

int search(vector<int> &A, int target) {
    int low = 0;
    int high = A.size() - 1;
    while(low < high) {
        int mid = low + (high - low) / 2;
        if((A[0]  > target) ^ (A[0] > A[mid]) ^ (target > A[mid])) low = mid + 1;
        else high = mid ;

    }
    return (low == high) && (A[low] == target) ? low : -1;

}


int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i< n;i++) cin>>A[i];
    cin>>n;
    cout<<search(A, n)<<'\n';
    return 0;
}