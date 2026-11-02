#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val)
{
    stack[++top] = val;
}
int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[MAX];
    int is_building_num = 0, current_num = 0, operand1, operand2, result;

    printf("Enter postfix expression (digits & operators, space separated): ");
    fgets(postfix, MAX, stdin);

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char c = postfix[i];

        if (isdigit(c))
        {
            // We found a digit. Shift the current number left by one base-10 spot and add the new digit.
            // Example for "123":
            // 1st loop: 0 * 10 + 1 = 1
            // 2nd loop: 1 * 10 + 2 = 12
            // 3rd loop: 12 * 10 + 3 = 123
            current_num = (current_num * 10) + (c - '0');
            is_building_num = 1;
        }
        // We hit a space or the end of the line. If we were building a number, it's now complete.
        else if ((c == ' ' || c == '\n') && is_building_num == 1)
        {
            push(current_num);
            current_num = 0;     // Reset for the next number
            is_building_num = 0; // Reset flag
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            operand2 = pop();
            operand1 = pop();
            switch (c)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            default:
                result = 0;
            }
            push(result);
        }
    }

    printf("Result of postfix evaluation = %d\n", pop());
    return 0;
}