typedef struct MyLinkedList
{
    struct MyLinkedList *next;
    int val;
    
} MyLinkedList;


// -------------------helper functions------------------

// returns pointer to the i-th node
size_t get_node(MyLinkedList* obj, int index)
{
    MyLinkedList *iter = obj;
    int i = 0;
    while(i < index && iter) 
    {
        i++;
        iter = iter->next;
    }
    
    return iter;
}

// builds a new node
MyLinkedList* create_node(int val)
{
    MyLinkedList *node = malloc(sizeof(MyLinkedList));
    node->val = val;
    node->next = NULL;
    
    return node;
}

// -------------------------------------------------------

MyLinkedList* myLinkedListCreate() 
{
    MyLinkedList *head = malloc(sizeof(MyLinkedList));;
    head->next = NULL;
    
    return head;
}

int myLinkedListGet(MyLinkedList* obj, int index) 
{
    MyLinkedList *iter = get_node(obj->next, index);
    
    return iter ? iter->val : -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) 
{
    MyLinkedList *new_head = create_node(val);
    new_head->next = obj->next;
    obj->next = new_head;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) 
{
    MyLinkedList *iter = obj;
    while (iter->next)
    {
        iter = iter->next;
    }
    
    iter->next = create_node(val);
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) 
{
    MyLinkedList *iter = get_node(obj, index);
    if (iter)
    {
        MyLinkedList *new_node = create_node(val);
        new_node->next = iter->next;
        iter->next = new_node;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) 
{
    MyLinkedList *iter = get_node(obj, index), *tmp;
    if (iter)
    {    
        if(iter->next && iter->next->next != NULL) 
        {
            tmp =iter->next;
            iter->next = iter->next->next;
            free(tmp);
        }
        else if(iter->next && iter->next->next == NULL) 
        {
            tmp = iter->next;
            free(tmp);
            iter->next = NULL;
        }
    }
}

void myLinkedListFree(MyLinkedList* obj)
{
    MyLinkedList* iter = obj;
    
    while(iter->next)
    {
        MyLinkedList* tmp = iter->next;
        iter->next = iter->next->next;
        free(tmp);
    }
}
