#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

template <typename T> void print(T vec) { for (auto d : vec) cout << d << ' '; cout << '\n'; }
template<typename T> void print2D(T mat) { for (auto vec : mat) print(vec); }


class NumArray {
public:
    vector<ll> Seg;
    vector<ll> Lazy;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        Seg.resize(2*n + 1, 0);
        Lazy.resize(2*n+1);
        build(nums, 1, 0, n - 1);
        
    }
    
    // void build(vector<int> &nums, int node, int start, int end) {
        
    //     if(start == end) Seg[node] = nums[start];
    //     else {
    //         int mid = start + (end - start) / 2;
    //         build(nums, 2*node, start, mid);
    //         build(nums, 2*node + 1, mid + 1, end);
    //         Seg[node] = Seg[2*node] + Seg[2*node + 1];
    //     }
    // }

    void build(vector<int> & nums, int node, int start, int end){
        if(start == end) {
        // Leaf node will have a single element
            Seg[node] = nums[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(nums, 2*node, start, mid);
        // Recurse on the right child
        build(nums, 2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        Seg[node] = Seg[2*node] + Seg[2*node+1];
    }
}

    void updateRange(int node, int start, int end, int idx, int val) {
        if(idx < start || idx > end) return;
        if(start == end) {
            cout<<start<<'\n';
            if(start == idx) {
                while(node != 1) {
                    Seg[node] += val;
                    node /= 2;
                }
                return;
            }
            return;    
        }
        int mid = start + (end - mid) / 2;
        updateRange(2*node, 0, mid, idx, val);
        updateRange(2*node + 1, mid+1, n-1, idx, val);
    }

    
    void update(int i, int val) {
        updateRange(1, 0, n - 1, i, val);
    }
    
    
    int query(int index, int start, int end, int left, int right) {
        if(start > end || start > right || end < left) return 0;
        if(start <= left && end >= right) return Seg[index];
        int mid = start + (end - start) / 2;
        int res = query(2*index, start, mid, left, right) + query(2*index + 1, mid+1, end, left, right);
        cout<<res<<'\n';
        return res;
    }
    
    int sumRange(int i, int j) {
        print(Seg);
        return query(1, 0, n - 1, i + 1, j + 1);
    }
};


int main() {
    freopen("inp", "r", stdin);
    freopen("out", "w", stdout);
    int n;
    cin>>n;
    vector<int> nums(n + 1);
    for(int i = 0; i< n; i++) cin>>nums[i];
    NumArray Tree(nums); 
    Tree.update(6,25);
    print(Tree.Seg);
    return 0;
}