#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return;;
        int i;
        for(i = n - 2; i >= 0; i--) {
            cout<<i<<'\n';
            if(nums[i] < nums[i+1]) break;
        }
        cout<<i<<'\n';
        reverse(nums.begin() + i + 1, nums.end());
        
        if(i == -1) return;
        auto itr = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]);
        // print(nums);
        cout<<*itr<<'\n';
        swap(nums[i], *itr);
}


int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i< n;i++) cin>>A[i];
    nextPermutation(A);
    print(A);
    return 0;
}