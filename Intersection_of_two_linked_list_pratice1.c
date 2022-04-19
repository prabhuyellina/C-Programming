/* Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:


The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns. */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <math.h>
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *t1=headA,*t2=headB;
    int listA_count=0,listB_count=0,diff,index=0;
    while(t1)
    {
        listA_count++;
        t1=t1->next;
    }
        while(t2)
    {
        listB_count++;
        t2=t2->next;
    }
    diff=abs(listA_count-listB_count);
    t1=headA;
    t2=headB;
    if(listA_count>listB_count){
        while(t1)
        {
            index++;
            t1=t1->next;
            if(index==diff)break;
        }
    }
    else if(listB_count>listA_count)
    {
        index=0;
        while(t2)
        {
            index++;
            t2=t2->next;
            if(index==diff)break;
        }
    }
    while(t1->next&&t2->next)
    {
        if(t1->next==t2->next)return t1->next;
        t1=t1->next;
        t2=t2->next;
    }
    
    return NULL;
}
