/* Experiment 1: Basic Array Operations (Insertion, Deletion, Traversal)
   Case Study Context:
   The admission office maintains the internal-assessment marks of a section as a simple array.
   New marks need to be inserted when a late entry arrives, incorrect entries need to be deleted,
   and the full list needs to be traversed (printed) for verification. */
#include <stdio.h>

/// @brief Traverses and prints the elements of an array
/// @param arr
/// @param n
void traverse(int arr[], int n)
{
    printf("Marks List: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/// @brief Inserts an element at a specified position in the array
/// @param arr - marks array
/// @param n - current size of the array
/// @param pos - position to insert the new element
/// @param value - the new element to be inserted
/// @return The new size of the array
int insert(int arr[], int n, int pos, int value)
{
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    return n + 1;
}

/// @brief  Deletes an element from a specified position in the array
/// @param arr
/// @param n
/// @param pos
/// @return The new size of the array
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
