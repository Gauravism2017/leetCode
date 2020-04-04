#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

int length;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    length = (int)beginWord.size();
    unordered_set<string> _set(wordList.begin(), wordList.end());
    if(!_set.count(endWord)) return 0;
    unordered_set<string> end = {endWord};
    unordered_set<string> curr = {beginWord};

    _set.erase(endWord);

    int step = 0;
    while(!end.empty() && !curr.empty()) {
        
        step++;
        if(curr.size() > end.size()) swap(curr, end);
        unordered_set<string> temp;

        for(auto word : curr) {
            
            for(int i = 0; i < length; i++) {
                char oldchar = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) if(ch != oldchar) {
                    string newWord = word;
                    newWord[i] = ch;
                    print(temp);
                    if(end.count(newWord)) return step + 1;
                    if(_set.count(newWord)) {
                        temp.insert(newWord);
                        _set.erase(newWord);
                    }
                }
            }
        }
        swap(curr, temp);
    }
    return 0;
}


int main() {
    int n;
    cin>>n;
    string beginWord;
    string endWord;
    cin>>beginWord>>endWord;
    vector<string> dict(n);
    for(int i = 0; i< n;i++) cin>>dict[i];
    cout<<ladderLength(beginWord, endWord, dict)<<'\n';
    return 0;
}