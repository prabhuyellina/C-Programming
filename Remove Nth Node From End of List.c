/* Problem: Given the head of a linked list, remove the nth node from the end of the list and return its head.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head==NULL) return NULL;
    if(head->next==NULL&&n==1)
    {
        free(head);
        return NULL;
    }
    struct ListNode *slow=head,*fast=head,*temp=NULL;
    int count=0;
    while(fast->next){
        if(count>=n)slow=slow->next;
        fast=fast->next;
        count++;
    }
    if(n>count){
    temp=head;
    head=head->next;
    free(temp);  
    }
    else{
        temp=slow->next;
        slow->next=slow->next->next;
        free(temp);
    }
    
return head;
    
}
