//https://leetcode.com/problems/merge-k-sorted-lists/
struct MinHeapNode{
    ListNode *node;
    int idx;
    MinHeapNode(ListNode* n, int i): node(n), idx(i){}
};

class mycomp{
public:
bool operator()(MinHeapNode* a, MinHeapNode* b){
    return a->node->val > b->node->val;
}
};

class Solution {
public:
/*
//min heap
//time O(nklogk)
ListNode* mergeKLists(vector<ListNode*>& lists){
    ListNode* dummy = new ListNode(0);
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, mycomp> pq;
    for(int i = 0; i < lists.size(); ++i){
        if(lists[i] == NULL)continue;
        pq.push(new MinHeapNode(lists[i], i));
        lists[i] = lists[i]->next;
    }
    ListNode* p = dummy;
    while(!pq.empty()){
        int idx = pq.top()->idx;
        p->next = pq.top()->node;
        pq.pop();
        p = p->next;
        if(lists[idx] != NULL){ 
            pq.push(new MinHeapNode(lists[idx], idx));
            lists[idx] = lists[idx]->next;
        }
    }
    return dummy->next;
}
*/


//merge sort 
//time O(nklogk)
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n=lists.size();
    if(n==0)return NULL;
    if(n==1)return lists[0];
    queue<ListNode*> q;
    for(int i=0; i<n; i+=2){
        if(i+1<n)q.push(merge(lists[i], lists[i+1]));
        else q.push(lists[i]);
    }
    while(q.size()>1){
        ListNode *a=q.front(); q.pop();
        ListNode *b=q.front(); q.pop();
        q.push(merge(a,b));
    }
    return q.front();
}

ListNode* merge(ListNode *a, ListNode *b) {
    ListNode *dummy=new ListNode(0);
    ListNode *p=dummy;
    while(a || b){
        if(a && b && a->val<b->val || a && !b){
            p->next=a;
            a=a->next;
            p=p->next;
        }
        if(a && b && a->val>=b->val || !a && b){
            p->next=b;
            b=b->next;
            p=p->next;
        }
    }
    return dummy->next;
}

};
