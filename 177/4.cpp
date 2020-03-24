#include <bits/stdc++.h>

using namespace std;

template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

string join(vector<int> &A) {
    // print(A);
    string ans = "";
    for(int d : A) {
        if(ans.size() == 0 && d == 0) continue;
        ans += '0' + d;
    }
    if(ans.size() == 0 && A.size() != 0) return "0";
    cout<<ans<<'\n';
    return ans;
}

bool deleteMod(vector<int> &digits, int m) {
    for(int i = digits.size() - 1;i >= 0; i--) {
        if(digits[i]%3 == m) {
            digits.erase(digits.begin() + i);
            return true;
        }
    }
    return false;
}

string largestMultipleOfThree(vector<int>& digits) {
    sort(digits.begin(), digits.end(), greater<int>());
    int sum = 0;
    for(int d : digits) sum += d;
    int m = sum % 3;
    if(m == 0) return join(digits);
    if(deleteMod(digits, m)) return join(digits);
    int _m = m==1?2:1;
    if(deleteMod(digits, _m) && deleteMod(digits, _m)) return join(digits);
    return "";
}

int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0;i < n; i++) cin>>A[i];
    cout<<largestMultipleOfThree(A)<<'\n';
    return 0;

}