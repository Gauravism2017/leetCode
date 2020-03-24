#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

 int minSteps(string s, string t) {
     vector<int> vec1(26), vec2(26);
     int diff = 0;
     for(char ch : s) vec1[ch - 'a']++;
     for(char ch : t) vec2[ch - 'a']++;
     for(int i = 0; i < 26; i++) diff += abs(vec1[i] - vec2[i]);
     return diff / 2;
        
}

int main() {
    string s1, s2;
    cin>>s1>>s2;
    cout<<minSteps(s1, s2);
    return 0;
}