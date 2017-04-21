//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.




class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode Head(0);
        ListNode *curNode = &Head;

        /*

        ListNode *Head=new ListNode(INT_MIN);
        ListNode *curNode=Head;
        */
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curNode->next = l1;
                l1 = l1->next;
            } 

            else {
                curNode->next = l2;
                l2 = l2->next;
            }
            curNode = curNode->next;
        }

        if (l1)
            curNode->next = l1;
        else 
            curNode->next = l2;

        return Head.next;


        /*  ***Another way to return a clean list
        ListNode *Result=Head->next;
        delete Head;
        return Result;
        */
    }
};