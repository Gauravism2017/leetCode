#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}


bool compare(vector<int> &A, vector<int> & B) {
    if(A[0] < B[0]) return true;
    else if(A[0] == B[0]) if(A[1] < B[1]) return true;
    return false;
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), compare);
    // print2D(intervals);
    int i = 0;
    int j = 1;
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    while(j < intervals.size()) {
        if(ans[i][1] >= intervals[j][0]) {
            if(ans[i][1] < intervals[j][1]) {
                ans[i][1] = intervals[j][1];
            }
            j++;
        }
        else {
            ans.push_back(intervals[j]);
            i++;
            j++;
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> A(n, vector<int>(2, 0));
    for(int i = 0; i< n;i++) cin>>A[i][0]>>A[i][1];
    vector<int> interval(2);
    cin>>interval[0]>>interval[1];
    print2D(insert(A, interval));
    return 0;
}