//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode*, vector<ListNode*>, headComp > heap;
    
    ListNode head(0);
    ListNode *curNode = &head;
    
    int n = lists.size();
    for (i = 0; i < n; i++)
        if (lists[i]) 
            heap.push(lists[i]);

    while (!heap.empty()){
        curNode->next = heap.top();
        heap.pop();
        curNode = curNode->next;
        if (curNode->next) 
            heap.push(curNode->next);
    }

    return head->next;
}


static bool heapComp(ListNode* a, ListNode* b) {
        return a->val > b->val;
}

//******************************************
//.    Not using priotry Queue or Heap (below)
//******************************************


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
            
        ListNode ans(0);
        ListNode* tail = &ans;
        
        while (l1 && l2){
            if (l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        if (l1)
            tail->next = l1;
        else
            tail->next = l2;
            
        return ans.next;
        
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty()){
            return NULL;
        }

        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];








    }
};