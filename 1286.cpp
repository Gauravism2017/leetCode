#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}


class CombinationIterator {
    vector<string> str;
    int n;
    int length;
    int count = 0;
public:
    CombinationIterator(string characters, int combinationLength) {
        n = characters.size();
        length = combinationLength;
        permute(characters, "", 0);
    }

    void permute(string &characters, string temp, int start) {
        if(temp.size() == length) {
            str.push_back(temp);
            return;
        }
        for(int i = start; i < characters.size(); i++) {
            temp += characters[i];
            permute(characters, temp, i + 1);
            temp.pop_back();
        }
    }
    
    string next() {
        return str[count++];
    }
    
    bool hasNext() {
        return count == str.size()? false: true; 
    }
};