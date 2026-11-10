
#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id;
    char name[30];
    float cgpa;
};


void display(struct Student *s, int n)
{
    printf("\n%-6s %-15s %-6s\n", "ID", "Name", "CGPA");
    for (int i = 0; i < n; i++)
        printf("%-6d %-15s %-6.2f\n", (s + i)->id, (s + i)->name, (s + i)->cgpa);
}

int main()
{
    int n;
    printf("Enter number of students to admit: ");
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));
    if (students == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter ID, Name, CGPA of student %d: ", i + 1);
        scanf("%d %s %f", &(students + i)->id, (students + i)->name, &(students + i)->cgpa);
    }

    display(students, n);

    free(students);
    return 0;
}
