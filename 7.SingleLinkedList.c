#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int id;
    struct Node *next;
};

struct Node *head = NULL;

void freeLinkedList()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }
}

struct Node *createNode(int id)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

void insertBeginning(int id)
{
    struct Node *newNode = createNode(id);
    newNode->next = head;
    head = newNode;
}

void traverse()
{
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->id);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertEnd(int id)
{
    struct Node *newNode = createNode(id);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertPosition(int id, int pos)
{
    if (pos <= 0)
    {
        printf("Given position %d is invalid!\n", pos);
        return;
    }
    if (pos == 1)
    {
        insertBeginning(id);
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Given position %d is invalid!\n", pos);
        return;
    }
    struct Node *newNode = createNode(id);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(int id)
{
    struct Node *temp = head, *prev = NULL;
    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Student ID %d not found!\n", id);
        return;
    }
    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;
    free(temp);
    printf("Student ID %d removed from Linked List\n", id);
}

int main()
{
    insertBeginning(100);
    traverse();

    insertEnd(300);
    traverse();

    insertPosition(200, 2);
    traverse();

    insertPosition(1000, 12);
    traverse();

    insertPosition(400, 3);
    traverse();

    deleteNode(300);
    traverse();
    return 0;
}
