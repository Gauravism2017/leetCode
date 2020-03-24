#include <bits/stdc++.h>

using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    int count = 0;
    for(auto vec : grid) {
        for(int d : vec) {
            if(d < 0) count++;
        }
    }
    return count;
        
}

int main() {
    int m, n;
    cin>>m>>n;
    vector<vector<int>> A(m, vector<int>(n));
    for(int i = 0; i< m; i++) {
        for(int j = 0; j < n; j++) {
            cin>>A[i][j];
        }
    }
    cout<<countNegatives(A)<<"\n";
    return 0;
}