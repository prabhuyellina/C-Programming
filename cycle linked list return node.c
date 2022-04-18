/* Problem: Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list. */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(!head || !head->next)return NULL;
    if(head->next->next==head) return head;
    struct ListNode *slow =head, *fast=head;
    int met=0;
    while(fast && fast->next){
        if(met==0){
        slow=slow->next;
        fast=fast->next->next;
        }
        if(met==1){
        slow=slow->next;
        fast=fast->next;
        }
        if(slow==fast){
            if(met==1)return slow;
            met=1;
            slow=head;
        }
    }
    return NULL;
}
