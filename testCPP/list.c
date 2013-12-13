#include<stdio.h>


typedef  int DataType 


typedef struct {
    Node *next;
    DataType data;
} Node;

typedef Node* List;


Node *listInit()
{
    List **head = NULL;

    *head = newNode();
    if (NULL == head)
	return NULL;
    head->next = NULL;
    head->data = -1;
    return head;
}

int listSize(List *head)
{
    List tmp = *head;
    int size = 0;
    while(tmp) {
	size++;
	tmp = tmp->next;
    }
    return size;
}


Node *listFind(List *head, DataType data)
{
    List tmp = *head;
    if(NULL == tmp)
	return -1;

    while (tmp->data != data) {
	tmp = tmp->next;
    }
    return tmp;
}


Node *newNode()
{
    Node *p = NULL;
    p = malloc(sizeof(Node));
    if (NULL == p) {
	fprintf(stderr, "Malloc failed.\n");
    }
    return p;
}

void freeNode(Node *pNode)
{
    if (pNode != NULL) 
	free(pNode);
    return;
}


bool listInsert(List head, DataType data)
{
}

bool listEmpty(List *head)
{
    return NULL == *head;
}

bool listDelete(List *head, Node *delNode)
{
    bool result;

    if (NULL == delNode) {
	fprintf(stderr, "The deleted node is empty can't delete it.\n");
	result = false;
    }

    if (NULL == *head) {
	fprintf(stderr, "List is empty, can't delete it.\n");
	result = false;
    }

    List tmp = *head;
    while(tmp->data != delNode->data)
	tmp++;
    if (NULL == tmp->prev && NULL == tmp->next) {
	tmp->>next = tmp->next;
	tmp->next_>prev = tmp->prev;
        result = true;
    } else {
	result = false;
    }

    return result;
}

int main(void)
{
    return 0;
}
