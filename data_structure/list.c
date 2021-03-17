#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct _ListNode ListNode;
struct _ListNode
{
    ElementType data;
    ListNode *next;
};

ListNode *create()
{
    ListNode *head;
    head = malloc(sizeof(ListNode));
    if (head == NULL)
    {
        printf("Malloc Error!\n");
        exit(1);
    }
    ListNode *ptr = head;
    ElementType val;
    int len;

    printf("Input length of list: ");
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        printf("Input #%d value: ", i + 1);
        scanf("%d", &val); // suppose ElementType is <int>
        ptr->next = malloc(sizeof(ListNode));
        ptr->next->data = val;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    return head;
}

void print(ListNode *head)
{
    ListNode *ptr = head->next;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int length(ListNode *head)
{
    ListNode *ptr = head->next;
    int len = 0;
    while (ptr != NULL)
    {
        len++;
        ptr = ptr->next;
    }
    return len;
}

void reverse(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head->next;
    while (curr != NULL)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = prev;
}

void insert(ListNode *head, ElementType val) // suppose list is sorted greater
{
    ListNode *curr = head->next;
    ListNode *prev = head;
    while (curr != NULL)
    {
        if (curr->data >= val)
            break;
        prev = curr;
        curr = curr->next;
    }
    ListNode *new_node = malloc(sizeof(ListNode));
    new_node->next = prev->next;
    prev->next = new_node;
    new_node->data = val;
}

int main()
{
    ListNode *head;
    head = create();

    printf("Input a value to insert: ");
    ElementType val;
    scanf("%d", &val); // suppose ElementType is <int>

    printf("Original: ");
    print(head);
    insert(head, val);
    printf("Inserted: ");
    print(head);

    return 0;
}
