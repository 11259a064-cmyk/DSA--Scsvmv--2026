#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int rollNo;
    struct Node *left, *right;
};

struct Node *createNode(int rollNo)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->rollNo = rollNo;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int dataToInsert)
{
    if (root == NULL)
        return createNode(dataToInsert);

    if (dataToInsert < root->rollNo)
        root->left = insert(root->left, dataToInsert);

    else if (dataToInsert > root->rollNo)
        root->right = insert(root->right, dataToInsert);

    return root; // Returning the updated tree's root pointer
}

struct Node *findMin(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node *deleteNode(struct Node *root, int rollNo)
{
    if (root == NULL)
        return root;
    if (rollNo < root->rollNo)
        root->left = deleteNode(root->left, rollNo);
    else if (rollNo > root->rollNo)
        root->right = deleteNode(root->right, rollNo);
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = findMin(root->right);
        root->rollNo = temp->rollNo;
        root->right = deleteNode(root->right, temp->rollNo);
    }
    return root;
}

//Left - Root - Right
void inOrder(struct Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->rollNo);
    inOrder(root->right);
}

//Root - Left - Right
void preOrder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->rollNo);
    preOrder(root->left);
    preOrder(root->right);
}

//Left - Right - Root
void postOrder(struct Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->rollNo);
}

//Breadth-First Search (BFS) or Level Order Traversal
void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;
    struct Node *queue[100]; //Static Queue for simplicity, assuming max 100 nodes
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        struct Node *curr = queue[front++]; //Dequeue the front node
        printf("%d ", curr->rollNo);
        if (curr->left != NULL)
            queue[rear++] = curr->left;
        if (curr->right != NULL)
            queue[rear++] = curr->right;
    }
}

int main()
{
    struct Node *root = NULL;
    int rolls[] = {150, 120, 180, 110, 130, 170, 190};
    int n = sizeof(rolls) / sizeof(rolls[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, rolls[i]);

    printf("Level-Order : ");
    levelOrder(root);
    printf("\n");

    printf("In-Order (sorted roll numbers) : ");
    inOrder(root);
    printf("\n");

    printf("Pre-Order  : ");
    preOrder(root);
    printf("\n");

    printf("Post-Order : ");
    postOrder(root);
    printf("\n");

    root = deleteNode(root, 120);
    printf("\nAfter deleting Roll No 120 (student left college):\n");
    printf("In-Order : ");
    inOrder(root);
    printf("\n");

    return 0;
}
