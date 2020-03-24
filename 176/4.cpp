#include <bits/stdc++.h>


using namespace std;

// bool isPossible(vector<int>& target) {
//     int idx = max_element(target.begin(), target.end()) - target.begin();
//     int maxm = target[idx];
//     if(maxm == 1) return true;
//     int n = target.size();
//     for(int i = 0; i < n; i++) {
//         if(i == idx) continue;
//         if(target[i] > maxm) return false;
//         maxm -= target[i];
//         if(maxm <= 0) return false;
//     }
//     target[idx] = maxm;
//     return isPossible(target);

        
// }
// long long int sum = 0;
// bool isPossible(vector<int> &target) {
//     priority_queue<long long int> pq;
//     // cout<<1;
//     for(int d : target) {
//         sum += d;
//         // pq.push(d);
//     }
//     for(int d : target) {
//         // sum += d;
//         pq.push(d);
//     }
//     // cout<<1;
//     while(pq.top() > 1) {
//         long long int top = pq.top();
//         pq.pop();
//         long long int _top = 2 * top - sum;
//         if(_top < 1) return false;
//         sum = top;
//         pq.push(_top);
//     }

//     return true;
// }

bool isPossible(vector<int>& target) {
        long long sum = 0;
        for(auto t : target)
            sum += t;
        priority_queue<long long> Q;
        for(auto t : target)
            Q.push(t);
        while(Q.top() > 1){
            long long maxn = Q.top();
            Q.pop();
            long long lst_val = (maxn << 1) - sum;
            if(lst_val < 1)
                return false;
            sum = maxn;
            Q.push(lst_val);
        }
        return true;
}   

int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i< n;i++) cin>>A[i];
    cout<<'a'<<isPossible(A)<<'\n';
    return 0;
}