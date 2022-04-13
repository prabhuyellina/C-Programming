#include<stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    
    int i=0,j,*data_ptr;
    struct ListNode* temp=head;
    
    data_ptr=malloc(1*sizeof(int));
    /* get the data and length of linked list */
    while(temp){
        if(data_ptr!=NULL && i>0)
        data_ptr = realloc(data_ptr,(i+1)*sizeof(int));
        *(data_ptr+i)=temp->val;
        temp=temp->next;
        i++;
    }
    i=i-1;
    for(j=0;j<i;j++){
        if(*(data_ptr+j)!=*(data_ptr+i)){
            return 0;
        }
        i--;
    }
    return 1;

}
