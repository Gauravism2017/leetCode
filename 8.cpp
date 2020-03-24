#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

int myAtoi(string str) {
    while(str[0] == ' ') str.erase(str.begin());
    if(str.empty()) return 0;
    long num = 0;
    int sign = 1;
    if(str[0] == '+') str.erase(str.begin());
    if(str[0] == '-') {
        sign = -1;
        str.erase(str.begin());
    }
    for(auto ch: str) {
        if(ch - '0' < 10 && ch - '0' >= 0) num = num * 10 + (ch - '0');
        else break;
        if(num*sign >= INT_MAX) return INT_MAX;
        if(num*sign <= INT_MIN) return INT_MIN;
        
    }
    return sign*num;
    
}


int main() {
    string s;
    cin>>s;
    // s = "   -42";
    cout<<myAtoi(s);
    return 0;
}