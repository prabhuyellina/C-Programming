/* Reference: https://www.youtube.com/watch?v=PvrxZaH_eZ4 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    /* handle one or no nodes*/
    if(!head || !head->next)return NULL;
    /* Handle 2 nodes */
    if(head->next->next==head) return head;
    struct ListNode *slow =head, *fast=head;
    int met=0;
    while(fast && fast->next){
        /* Traverse till fast and slow pointer meets */
        if(met==0){
        slow=slow->next;
        fast=fast->next->next;
        }
        /* if slow and fast mets, increment both pointers by one node */
        if(met==1){
        slow=slow->next;
        fast=fast->next;
        }
        /* slow and mets second time return the slow or fast */
        if(slow==fast){
            if(met==1)return slow;
            met=1;
            /* set slow to head if slow and fast already mets */
            slow=head;
        }
    }
    return NULL;
}
