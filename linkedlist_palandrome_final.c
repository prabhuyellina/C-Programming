/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* findSecondHalf(struct ListNode* head);
struct ListNode* reverse(struct ListNode* head);

bool isPalindrome(struct ListNode* head){
    if(head->next==NULL)return true;
    struct ListNode* secondHalf_head=findSecondHalf(head);
    struct ListNode* reverse_list= reverse(secondHalf_head->next);
    struct ListNode* p1=head, *p2=reverse_list;
    bool result=true;
    while(result && p2!=NULL){
        if(p1->val!=p2->val) return false;
        p1=p1->next;
        p2=p2->next;
    }
    return result;

}

struct ListNode* findSecondHalf(struct ListNode* head){
    struct ListNode* slow_ptr=head;
    struct ListNode* fast_ptr=head;
    while(fast_ptr->next !=NULL && fast_ptr->next->next !=NULL){
        fast_ptr=fast_ptr->next->next;
        slow_ptr=slow_ptr->next;
    }
    return slow_ptr;
}

struct ListNode* reverse(struct ListNode* head){
    struct ListNode* current=head;
    struct ListNode* prev=NULL, *temp;
    while(current!=NULL){
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
    }
    return prev;
}
