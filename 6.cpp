#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}


string convert(string str, int n) {
    if(n <=1 || n >= str.size()) return str;
    int down = 0;
    int row = 0;
    vector<string> vec(n);
    for(auto ch : str) {
        vec[row].push_back(ch);
        if(row == 0) down = 1;
        if(row == n -1) down = -1;
        row += down;
    }
    // print2D(vec);
    string s = "";
    for(string _str : vec) s += _str;
    return s;   
}

int main() {
    int n;
    string str;
    cin>>n;
    cin>>str;
    cout<<convert(str, n);
    return 0;
}