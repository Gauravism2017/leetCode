#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}



double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
    if(A.size() > B.size()) {
        return findMedianSortedArrays(B, A);
    }
    int x = A.size();
    int y = B.size();
    int low = 0;
    int high = x;
    while(low <= high) {
        int pX = low + (high - low) / 2;
        int py = (x + y + 1) / 2 - pX;

        int maxLeftX = (pX == 0) ? INT_MIN:A[pX - 1];
        int minRightX = (pX == x) ? INT_MAX:A[pX];

        int maxLeftY = (py == 0) ? INT_MIN:B[py - 1];
        int minRightY = (py == y) ? INT_MAX:B[py];

        if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
            cout<<maxLeftX <<" "<<maxLeftY<<" "<<minRightX<<" "<<minRightY<<'\n';
            if ( (x + y) % 2) {
                return (double)max(maxLeftX, maxLeftY);
            }
            else return ((double)max(maxLeftX, maxLeftY) + (double)min(minRightX, minRightY)) / 2;
        } 
        else if(maxLeftX > minRightY) {
            high = pX - 1;
        }
        else {
            low = pX + 1;
        }
    }
}

int main() {
    int n, m;
    cin>>n >> m;
    vector<int> A(n), B(m);
    for(int i = 0; i< n;i++) cin>>A[i];
    for(int i = 0; i< m;i++) cin>>B[i];
    cout<<findMedianSortedArrays(A, B)<<'\n';
    return 0;
}