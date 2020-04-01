#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

int trap(vector<int>& height) {
    stack<int> s;
    int n = height.size();
    if(n == 0 || n == 1) return 0;
    int i = 0;
    while(i < n && height[i] == 0) {
        i++;
    }
    int ans = 0;
    while(i < n) {
        while(!s.empty() && height[i] >= height[s.top()]) {
            int b = s.top();
            s.pop();
            if (s.empty()) {
                    break;
            }
            ans += (i - s.top() - 1)* (min(height[i], height[s.top()]) - height[b]);
        }
        s.push(i);
        i++;
    }
    return ans;
}


int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i< n;i++) cin>>A[i];
    cout<<trap(A);
    return 0;
}