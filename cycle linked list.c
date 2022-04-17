/* Problem: Linked List Cycle
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false. */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(!head || ! head->next)return false;
    struct ListNode *slow=head,*fast=head->next;
    while(fast && fast->next)
	{
        if(slow==fast) return true;
            slow=slow->next;
            fast=fast->next->next;
    }
    return false;
}
