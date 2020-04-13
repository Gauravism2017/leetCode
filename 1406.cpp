#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}



string stoneGameIII(vector<int>& stoneValue) {
    vector<int> bestScore(stoneValue.size(), 0);
    for(int i = stoneValue.size() - 1; i >= 0; i--) {
        int take = 0;
        int best = INT_MIN;
        for(int j = 0; j < 3 && i + j < stoneValue.size(); j++) {
            take += stoneValue[i + j];
            int oppo = ( i + j + 1 < stoneValue.size()) ? bestScore[i + j + 1] : 0;
            best = max(best, take - oppo);
        }
        bestScore[i] = best;
    }
    return (bestScore[0] > 0) ? "Alice" : (bestScore[0] == 0) ? "Tie" : "Bob";
}


int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i< n;i++) cin>>A[i];
    cout<<stoneGameIII(A);
    return 0;
}