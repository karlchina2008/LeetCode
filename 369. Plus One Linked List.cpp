/*
Given a non-negative number represented as a singly linked list of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/
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
    ListNode* plusOne(ListNode* head) {
        if(head==NULL) return head;
        ListNode *root=new ListNode(1);
        ListNode *slow,*fast;
        fast=head;
        slow=root;
        while(fast){
            if(fast->val!=9) slow=fast;
            fast=fast->next;
        }
        if(slow==root){
            slow->next=head;
            while(head){
                head->val=0;
                head=head->next;
            }
            return root;
        }
        else{
            slow->val++;
            while(slow=slow->next){
                slow->val=0;
            }
            return head;
        }
    }
};
