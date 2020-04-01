#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

int length;

// void combine(vector<int> &candidates, vector<vector<int>> &ans, vector<int> temp, int start, const int &target) {
//     // print(temp);
//     int sum = accumulate(temp.begin(), temp.end(), 0);
//     if(sum == target) {ans.push_back(temp); return;}
//     else if(sum > target) return;
//     for(int i = start; i < length; i++) {
//         temp.push_back(candidates[i]);
        
//         combine(candidates, ans, temp,i, target);
//         temp.pop_back();
//     }
// }


// void combine(vector<int> &candidates, vector<vector<int>> &ans, vector<int> temp, int start, int target) {
//     // print(temp);
//     // int sum = accumulate(temp.begin(), temp.end(), 0);
//     // cout<<target<<'\n';
//     if(!target) {ans.push_back(temp); return;}
//     for(int i = start; i < length && target >= candidates[i]; i++) {
//         temp.push_back(candidates[i]);
//         combine(candidates, ans, temp,i, target - candidates[i]);
//         temp.pop_back();
//     }
// }


void combine(vector<int> &candidates, vector<vector<int>> &ans, vector<int> temp, int start, int target, int soFar) {
    // print(temp);
    // int sum = accumulate(temp.begin(), temp.end(), 0);
    // cout<<target<<'\n';
    if(!target) {ans.push_back(temp); return;}
    for(int i = start; i < length; i++) {
        if(soFar + candidates[i] <= target) {
            temp.push_back(candidates[i]);
            combine(candidates, ans, temp,i, target, soFar + candidates[i]);
            temp.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    length = candidates.size();
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    combine(candidates, ans, temp,0, target, 0);
    return ans;
}


int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i< n;i++) cin>>A[i];
    cin>>n;
    // cout<<n;
    print2D(combinationSum(A, n));
    return 0;
}