#include <bits/stdc++.h>

using namespace std;

template<typename T>
void print(T vec) {
    for(auto d : vec) cout<<d<<' ';
    cout<<'\n';
}

template <typename T>
void print2D(T mat) {
    for(auto vec : mat) {
        print(vec);
    }
    
}

int root(int i, vector<int> &A) {
    while(i != A[i]) {
        A[i] = A[A[i]];
        i = A[i];
    }
    return i;
}

void wunion(int a, int b, vector<int> &id, vector<int> &size) {
    int roota = root(a, id);
    int rootb = root(b, id);
    if(size[a] < size[b]) {
        id[a] = b;
    }
    else{
        id[b] = a;
    }
}

bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
    
    vector<vector<int>> edge;
    vector<int> vec;
    for(int i = 0; i < n; i++) {
        if(left[i] != -1) {
            vec.clear();
            // cout<<"i "<<i<<" left[i] "<<left[i]<<'\n';
            vec.emplace_back(i);
            vec.emplace_back(left[i]);
            edge.push_back(vec);
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(right[i] != -1) {
            vec.clear();
            // cout<<"i "<<i<<" left[i] "<<right[i]<<'\n';
            vec.emplace_back(i);
            vec.emplace_back(right[i]);
            edge.push_back(vec);
        }
    }
    
    vector<int> id(n);
    for(int i = 0; i < n; i++) id[i] = i;
    vector<int> size(n, 1);
    
    for(auto ed : edge) {
        wunion(ed[0], ed[1],id, size);
    }
    print(right);
    int count = 0;
    for(int i = 0; i < n;i++) {
        if(id[i] == i) count++;
    }
    if(count) {
        return edge.size() == n - 1;
    }
    else{
        return 0;
    }
    // cout<<edge.size() <<'\n';
    // print2D(edge);
        
}

int main() {
    int n;
    cin>>n;
    cout<<n<<'\n';
    vector<int> left(n), right(n);
    for(int i = 0; i< n;i++) {
        cin>>left[i];
    }
    // print(left);
    for(int i = 0; i< n;i++) {
        cin>>right[i];
    }
    cout<<validateBinaryTreeNodes(n, left, right)<<'\n';
    return 0;
}