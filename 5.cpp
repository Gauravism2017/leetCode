#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

int maxLen = 0;

string update(string s) {
    string temp = "#";
    for(char ch : s) {
        temp += ch;
        temp += '#';
    }
    return temp;
}

void PalinLength(int i, string &s, int n, int &l , int &r) {
    int len = 1;
    int left = i - 1;
    int right = i + 1;
    while(left >= 0 && right < n && s[left] == s[right]) {
        len+=2;
        left--;
        right++;
    }
    // cout<<len<<" "<<maxLen<<'\n';
    if(len > maxLen) {
        l = left + 1;
        r = right - 1;
        maxLen = len;
    }
}

string longestPalindrome(string s) {
    if(s == "") return "";
    if( s.size() % 2 == 0) s = update(s);
    // cout<<s<<'\n';
    int n = s.size();
    int left, right;
    for(int i = 0; i < n; i++) {
        // cout<<n;
        PalinLength(i, s, n, left, right);
    }
    // cout<<left<<" "<<right<<'\n';
    for(int i = left; i <= right; i++) {
        if(s[i] != '#') cout<<s[i];
    }
    return "";  
}


int main() {
    string s;
    cin>>s;
    // s = "";
    cout<<longestPalindrome(s);
    return 0;
}