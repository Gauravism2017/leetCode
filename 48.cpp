#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int a = 0;
    int b = n - 1;
    while(a < b) {
        for(int i = 0; i < (b - a); i++) {
            swap(matrix[a][a+i], matrix[a+i][b]);
            swap(matrix[a][a+i], matrix[b][b-i]);
            swap(matrix[a][a+i],matrix[b-i][a]);
        }
        print2D(matrix);
        ++a;
        --b;
    }
}


int main() {
    int n;
    cin>>n;
    vector<vector<int>> A(n, vector<int>(n));
    for(int i = 0; i< n;i++)
        for(int j = 0; j < n; j++) cin>>A[i][j];
    rotate(A);
    print2D(A);
    return 0;
}