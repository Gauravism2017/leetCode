#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

bool isValid(vector<string> &temp, int row, int col, int &n) {
    for(int i = 0; i < row; i++) if(temp[i][col] == 'Q') return false;
    for(int i = row - 1, j = col - 1; i>= 0 && j >= 0; i-- && j--) if(temp[i][j] == 'Q') return false;
    for(int i = row - 1, j = col + 1; i>= 0 && j < n; i-- && j++) if(temp[i][j] == 'Q') return false;
    return true;
}

void solve(vector<vector<string>> &ans, vector<string> &temp, int row, int &n) {
    if(row == n) {
        ans.push_back(temp);
        return;
    }
    for(int col = 0; col < n; col++) {
        if(isValid(temp, row, col, n)) {
            temp[row][col] = 'Q';
            solve(ans, temp, row + 1, n);
            temp[row][col] = '.';
        }
    }
}

int solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> temp(n, string(n, '.'));
    solve(ans, temp, 0, n);
    print2D(ans);
    return ans.size();
}


int main() {
    // int n;
    // cin>>n;
    vector<int> ans;
    // print2D(solveNQueens(n));
    // cout<<solveNQueens(n).size()<<'\n';
    for(int i = 0; i< 6; i++) {
        cout<<i<<'\n';
        ans.push_back(solveNQueens(i));
    }
    print(ans);
    return 0;
}