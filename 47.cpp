#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

void permute(vector<int> vec, set<vector<int>> &ans, vector<int> &nums, vector<bool> visited) {
    // print(visited);
    int n = nums.size();
    if(vec.size() > n) return;
    if(vec.size() == n) {
        ans.insert(vec);
        return;
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]) {
            vec.push_back(nums[i]);
            visited[i] = 1;
            permute(vec, ans, nums, visited);
            visited[i] = 0;
            vec.pop_back();
        }
        
        
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    set<vector<int>> ans;
    vector<int> vec;
    vector<bool> visited(nums.size(), 0);
    permute(vec, ans, nums, visited);
    vector<vector<int>> _ans(ans.begin(), ans.end());
    return _ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i< n;i++) cin>>A[i];
    print2D(permuteUnique(A));
    // permuteUnique(A);
    return 0;
}