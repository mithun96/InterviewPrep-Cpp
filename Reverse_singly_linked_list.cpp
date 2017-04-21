//Reverse a singly linked list.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if (!head || !(head -> next)) 
            return head;

        ListNode *prevNode = NULL;
        ListNode *nextNode = NULL;

        while(head){
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;

        }

        return prevNode;
    }
};




/******************************************
 * Done with recursion (DO NOT UNDERSTAND IT)
 */


class Solution {
public:   
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head -> next)) return head;
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node; 
    }
}; 