#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}


int numTeams(vector<int>& rating) {
    int count = 0;
    for(int i = 0; i < rating.size(); i++) {
        for(int j = i + 1; j < rating.size(); j++) {
            for(int k = j + 1; k < rating.size(); k++) {
                if((rating[i] < rating[j] && rating[j] < rating[k]) || (rating[i] > rating[j] && rating[j] > rating[k])) {
                    count++;
                }
            }
        }
    }
    return count;
}


int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i< n;i++) cin>>A[i];
    cout<<numTeams(A)<<'\n';
    return 0;
}