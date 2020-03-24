#include <bits/stdc++.h>

using namespace std;

int maxEvents(vector<vector<int>>& A) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = A.size();
    sort(A.begin(), A.end());
    int i = 0;
    int count = 0;
    for(int d = 1; d <= 100000; ++d) {
        // if(pq.size())
        cout<<pq.top()<<" "<<d<<'\n';
        while(pq.size() && pq.top() < d) {
            // cout<<pq.top()<<" "<<d<<'\n';
            pq.pop();
        }
        while(i < n && A[i][0] == d) {
            pq.push(A[i++][1]);
        }
        if(pq.size()) {
            // cout<<pq.top()<<'\n';
            pq.pop();
            count++;
        }

    }
    return count;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> array(n, vector<int>(2));
    for(int i = 0; i<n;i++) {
        cin>>array[i][0]>>array[i][1];
    }
    cout<<maxEvents(array)<<'\n';
    return 0;
}