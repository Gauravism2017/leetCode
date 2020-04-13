#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}


void div(string &str) {

    for(int i = str.size() - 1; i > 0; i--) {
        str[i] = str[i - 1];
    }
    str[0] = '0';
}

void add(string &str) {
    int carry = '1';
    for(int i = str.size() - 1; i >= 0 && carry == '1'; i--) {
        if(str[i] == '0') {
            str[i] = '1';
            carry = '0';
        }
        else if(str[i] == '1') {
            str[i] = '0';
            carry = '1';
        }
    }
    if(carry == '1') str = '1' + str;
}
int temp;
int numSteps(string str) {
    int count = 0;
    while(str != "1") {
        cout<<str<<'\n';
        
        if(str.back() == '0') {
            div(str);
            count++;
        }
        else if(str.back() == '1') {
            add(str);
            count++;
        }
        while(str.front() == '0') str.erase(str.begin());
    }
    // temp = 
    return count;
}



int main() {
    string str;
    cin>>str;
    cout<<numSteps(str)<<'\n';
    return 0;
}