#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

int length;
int k;

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


void combine(vector<int> &candidates, vector<vector<int>> &ans, vector<int> temp, int start, int target) {
    // print(temp);
    // int sum = accumulate(temp.begin(), temp.end(), 0);
    // cout<<target<<'\n';
    if(temp.size() == k) {
        if(!target) ans.push_back(temp);
        return;
    }
    for(int i = start; i < length && target >= candidates[i]; i++) {
        // if (i == start || candidates[i] != candidates[i - 1]) {
        temp.push_back(candidates[i]);
        combine(candidates, ans, temp,i + 1, target - candidates[i]);
        temp.pop_back();
    }
}



vector<vector<int>> combinationSum(int k, int target) {
    vector<int> candidates = {1, 2, 3, 4, 5 , 6, 7, 8, 9};
    length = candidates.size();
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    combine(candidates, ans, temp,0, target);
    return ans;
}


int main() {
    int n;
    cin>>k>>n;
    // vector<int> A(n);
    // for(int i = 0; i< n;i++) cin>>A[i];
    cin>>k;
    cin>>n;
    // cout<<n;
    print2D(combinationSum(k, n));
    return 0;
}