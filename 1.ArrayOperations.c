
#include <stdio.h>

void traverse(int arr[], int n)
{
    printf("Marks List: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int insert(int arr[], int n, int pos, int value)
{
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    return n + 1;
}


int deleteElement(int arr[], int n, int pos)
{
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    return n - 1;
}

int main()
{
    int marks[50], studentCount, position, valueToInsert;

    printf("Enter number of students: ");
    scanf("%d", &studentCount);

    printf("Enter %d marks: ", studentCount);
    for (int i = 0; i < studentCount; i++)
        scanf("%d", &marks[i]);

    traverse(marks, studentCount);

    printf("Enter position and marks to insert: ");
    scanf("%d %d", &position, &valueToInsert);
    
    if (position < 0 || position > studentCount)
    {
        printf("Invalid position for insertion.\n");
    }
    else
    {
        studentCount = insert(marks, studentCount, position, valueToInsert);
        printf("After Insertion -> ");
        traverse(marks, studentCount);
    }

    printf("Enter position to delete: ");
    scanf("%d", &position);
    if (position < 0 || position >= studentCount)
    {
        printf("Invalid position for deletion.\n");
    }
    else
    {
        studentCount = deleteElement(marks, studentCount, position);
        printf("After Deletion  -> ");
        traverse(marks, studentCount);
    }

    return 0;
}
