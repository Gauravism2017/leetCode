#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct compare {
    bool operator() (ListNode* A, ListNode* B) {
        if(A->val > B->val) return true;
        return false;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    ListNode* head = NULL, *tail;

    for(ListNode* node : lists) {
        pq.push(node);
    }
    while(!pq.empty()) {
        ListNode* top = pq.top();
        pq.pop();
        if(top->next != NULL) {
            pq.push(top->next);
        }
        if(!head) {
            head == top;
            tail == top;
        }
        else{
            tail->next = top;
            tail = top;
        }
    }
    return head;

}

int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i< n;i++) cin>>A[i];
    return 0;
}