#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

int curr_max = INT_MAX;
int length;
unordered_map<string, int> _map;

void func(vector<vector<string>> &ans, string &endWord, vector<string> temp, set<string> s) {
    if(temp.size() > curr_max) return;
    if(temp.back() == endWord) {
        if(temp.size() < curr_max) {
            ans.push_back(temp);
            curr_max = min(curr_max, (int)temp.size());
        }
        return;
    }
    for(int i = 0; i<length;i++) {
        string str = temp.back();
        for(char ch = 'a'; ch <= 'z'; ch++) {
            str[i] = ch;
            if(_map.find(str) != _map.end() && s.count(str) == 0) {
                // cout<<str<<'\n';
                temp.push_back(str);
                s.insert(str);
                func(ans, endWord, temp, s);
                temp.pop_back();
            }
        }
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    _map.clear();
    length = beginWord.size();
    vector<vector<string>> ans;
    for(string str : wordList) _map[str]++;
    // _map[beginWord]++;
    vector<string> seq;
    set<string> s;
    s.insert(beginWord);
    seq.push_back(beginWord);
    func(ans, endWord, seq, s);
    int mn = INT_MAX;
    // print2D(ans);
    for(auto vec : ans) {
        mn = min((int)vec.size(), mn);
    }
    vector<vector<string>> result;
    for(auto vec : ans) {
        if(vec.size() == mn) result.push_back(vec);
    }
    return result;
}


int main() {
    int n;
    cin>>n;
    string beginWord;
    string endWord;
    cin>>beginWord>>endWord;
    vector<string> dict(n);
    for(int i = 0; i< n;i++) cin>>dict[i];
    print2D(findLadders(beginWord, endWord, dict));
    return 0;
}