#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

vector<int> minSubsequence(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<int> ans;
    int ans_sum = 0;
    int i =0;
    while(ans_sum <=  sum - ans_sum) {
        ans_sum += nums[i];
        ans.push_back(nums[i]);
        i++;
    }
    return ans;
}


int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i< n;i++) cin>>A[i];
    print(minSubsequence(A));
    return 0;
}