#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

string rankTeams(vector<string>& votes) {
    int n = votes[0].size();
    vector<vector<int>> count(26, vector<int>(n + 1));
    for (int i = 0; i < 26; i++)
            count[i][n] = -i;
    for(auto vote : votes) {
        for(int i = 0; i <n; i++) {
            count[vote[i] - 'A'][i] += 1; 
        }
    }
    print2D(count);
    sort(count.begin(), count.end(), greater<vector<int>>());
    string ans;
    for(int i = 0 ; i < min(n , 26); i++) {
        ans += -count[i][n] + 'A';
    } 
    // reverse(ans.begin(), ans.end());
    // print2D(count);
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<string> A(n);
    for(int i = 0; i< n;i++) cin>>A[i];
    string ans = rankTeams(A);
    cout << ans<<'\n';
    return 0;

}