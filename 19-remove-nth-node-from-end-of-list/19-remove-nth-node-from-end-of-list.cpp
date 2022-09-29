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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *h=head;
                ListNode *q=head;
        int ct=0;
        while(h!=NULL){
            ct++;
            h=h->next;
        }
        if(ct==1){
            head=NULL;
            return head;
        }
        ct=(ct-n)+1;
        if(ct==1){
            head=head->next;
            return head;
        }
        //cout<<ct;
        int k=0;
        h=head;
        q=head;
        while(h!=NULL){
            k++;
            if(k==ct){
                //cout<<q->val<<" "<<h->val;
                q->next=h->next;
                break;
            }
            q=h;
            h=h->next;
        }
        return head;
    }
};