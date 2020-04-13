#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}


bool isValid(string str, char ch) {
    int len = str.size();
    if(str[len - 1] == ch && str[len - 2] == ch) return false;
    return true;
}

void dp(string &ans, string temp, vector<int> count) {
    cout<<temp<<'\n';
    if(ans.size() < temp.size()) {
        ans = temp;
    }
    for(int i = 0; i < 3; i++) {
        if(count[i]) {
            if(isValid(temp, 'a' + i)) {
                // check = true;
                count[i] -= 1;
                temp += ('a' + i);
                dp(ans, temp, count);
                temp.pop_back();
                count[i] += 1;
            }
        }
    }
}





// string longestDiverseString(int a, int b, int c) {
//     string ans = "";

//     vector<int> count = {a, b, c};
//     dp(ans, "", count);
//     return ans;
// }''


int maxm(vector<int> _map, bool diff, ch last) {
    int idx = -1;
    for(int i = 0; i < 3; i++) {
        if(_map[i] == 0 || (diff && i == (last - 'a'))) continue;
        if(idx == -1 || _map[i] > _map[idx]) idx = i;
    }
    return idx;
}


char nextchar(char last, int count, vector<int> _map) {
    int currentMax = maxm(_map, false, NULL);
    if(last == NULL || currentMax != (last - 'a') || count < 2) {
        return currentMax + 'a';
    }
    else {
        int idx = maxm(_map, true, last);
        return idx == -1 ? NULL : idx + 'a';
    }
}

string longesrDiverseString(int a, int b, int c) {

}


int main() {
    int a, b, c;
    cin>>a>>b>>c;
    cout<<longestDiverseString(a, b, c)<<'\n';
    return 0;
}