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