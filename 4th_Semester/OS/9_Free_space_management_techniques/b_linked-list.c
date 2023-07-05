#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int start;
    int end;
    struct Node *next;
} Node;

typedef struct
{
    int size;
    Node *head;
} LinkedList;

void initLinkedList(LinkedList *list, int size)
{
    list->size = size;
    list->head = (Node *)malloc(sizeof(Node));
    list->head->start = 0;
    list->head->end = size - 1;
    list->head->next = NULL;
}

int allocate(LinkedList *list, int blocks)
{
    Node *curr = list->head;
    Node *prev = NULL;

    while (curr)
    {
        if (curr->end - curr->start + 1 >= blocks)
        {
            if (curr->end - curr->start + 1 == blocks)
            {
                if (prev)
                {
                    prev->next = curr->next;
                }
                else
                {
                    list->head = curr->next;
                }
            }
            else
            {
                Node *allocatedNode = (Node *)malloc(sizeof(Node));
                allocatedNode->start = curr->start;
                allocatedNode->end = curr->start + blocks - 1;
                curr->start += blocks;

                if (prev)
                {
                    allocatedNode->next = prev->next;
                    prev->next = allocatedNode;
                }
                else
                {
                    allocatedNode->next = list->head;
                    list->head = allocatedNode;
                }
            }
            return curr->start - blocks;
        }
        prev = curr;
        curr = curr->next;
    }
    return -1;
}

void deallocate(LinkedList *list, int start, int blocks)
{
    Node *curr = list->head;
    Node *prev = NULL;

    while (curr)
    {
        if (curr->start > start)
        {
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    if (prev && prev->end + 1 == start && curr && curr->start - 1 == start + blocks)
    {
        prev->end = curr->end;
        prev->next = curr->next;
        free(curr);
    }
    else if (prev && prev->end + 1 == start)
    {
        prev->end += blocks;
    }
    else if (curr && curr->start - 1 == start + blocks)
    {
        curr->start -= blocks;
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->start = start;
        newNode->end = start + blocks - 1;

        if (prev)
        {
            newNode->next = prev->next;
            prev->next = newNode;
        }
        else
        {
            newNode->next = list->head;
            list->head = newNode;
        }
    }
}

void printLinkedList(LinkedList *list)
{
    Node *curr = list->head;
    while (curr)
    {
        printf("(%d, %d) -> ", curr->start, curr->end);
        curr = curr->next;
    }
    printf("NULL\n");
}

void freeLinkedList(LinkedList *list)
{
    Node *curr = list->head;
    Node *next;

    while (curr)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
}

int main()
{
    LinkedList list;
    int size = 16;
    initLinkedList(&list, size);
    printf("Initial Linked List: ");
    printLinkedList(&list);

    int start = allocate(&list, 3);
    printf("Allocated blocks at index %d\n", start);
    printf("Updated Linked List: ");
    printLinkedList(&list);

    deallocate(&list, start, 3);
    printf("Deallocated blocks at index %d\n", start);
    printf("Updated Linked List: ");
    printLinkedList(&list);

    freeLinkedList(&list);

    return 0;
}
