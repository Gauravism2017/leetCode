#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}



vector<int> kmp(string needle) {
    int n = needle.size();
    vector<int> lps(n);
    for(int i = 1, len = 0; i<n;) {
        if(needle[i] == needle[len]) {
            lps[i++] = ++len;
        }
        else if(len) len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}

int strStr(string haystack, string needle) {
    int m = haystack.size(), n = needle.size(), p = 0;
        while (p + n - 1 < m) {
            if (haystack.substr(p, n) == needle) {
                return p;
            }
            while (p++ + n - 1 < m && haystack[p] != needle[0]);
        }
        return -1;
}



int main() {
    string haystack, needle;
    cin>>haystack>>needle;
    cout<<strStr(haystack, needle)<<'\n';
    return 0;
}