#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

bool isHappy(int n) {
    int temp;
    while(n != 1 && n != 4) {
        cout<<n<<'\n';
        int sum = 0;
        while(n > 0) {
            temp = n % 10;
            sum += (temp*temp);
            n /= 10;
        }
        n = sum;
    }
    return n == 1 ? true : false;
        
}


int main() {
    int n;
    cin>>n;
    cout<<isHappy(n);
    return 0;
}