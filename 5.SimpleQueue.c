#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int id)
{
    if (rear == MAX - 1)
    {
        printf("Queue is Full! Cannot enqueue Student ID %d\n", id);
        return;
    }
    //Inserting the first element
    if (front == -1)
        front = 0;
    queue[++rear] = id;
    printf("Student ID %d added to fee-payment queue\n", id);
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Student ID %d served and removed from queue\n", queue[front++]);
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty!\n");
        return;
    }
    
    printf("Current Queue: ");

    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main()
{
    int choice, id;
    do
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("Enter Student ID: ");
            scanf("%d", &id);
            enqueue(id);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}