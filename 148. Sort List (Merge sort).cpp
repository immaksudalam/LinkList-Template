class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* temp = new ListNode(0);
        ListNode* cur = temp;
        while(l1 && l2){
            if(l1->val <= l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1){
            cur->next = l1;
        }
        if(l2){
            cur->next = l2;
        }
        return temp->next;
    }
    ListNode* sortList(ListNode* head) {
       if(!head || !head->next) return head;
       ListNode* slow= head;
       ListNode* fast=head;
       ListNode* temp = NULL;
       while(fast && fast->next){
           temp = slow;
           slow = slow->next;
           fast=fast->next->next;
       }
       temp->next = NULL;
       
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        return merge(l1, l2);
    }
    
};
