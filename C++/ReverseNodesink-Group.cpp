// LeetCode Problem Link :- https://leetcode.com/problems/reverse-nodes-in-k-group/
// Author :- Anup Jeejo

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    void reverse(ListNode* s,ListNode* e){
        ListNode* p=NULL,*c=s,*n=s->next;
        while(p!=e){
            c->next=p;
            p=c;
            c=n;
            if(n!=NULL) n=n->next;
        }
    }
    
//---------------------Recursive Approach--------------------------------//
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(head==NULL || head->next==NULL || k==1)
//             return head;
        
//         ListNode* s=head,* e=head;
        
//         int ctr = k-1;
        
//         while(ctr--){
//             e=e->next;
//             if(e==NULL) return head;
//         }
        
//         ListNode* new_head = reverseKGroup(e->next,k);
//         reverse(s,e);
//         s->next=new_head;
        
//         return e;
//     }
    
//---------------------Iterative Approach--------------------------------//
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL || k==1)
            return head;
        
        
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        
        ListNode* bs=dummy, *e=head;
        int i=0;
        
        while(e!=NULL){
            i++;
            if(i%k == 0){
                ListNode* s=bs->next, *temp=e->next;
                reverse(s,e);
                bs->next=e;
                bs=s;
                s->next=temp;
                e=temp;
            }else{
                e=e->next;
            }
        }
        return dummy->next;   
    }
};