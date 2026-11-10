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
           
            current_num = (current_num * 10) + (c - '0');
            is_building_num = 1;
        }
       
        else if ((c == ' ' || c == '\n') && is_building_num == 1)
        {
            push(current_num);
            current_num = 0;     
            is_building_num = 0;
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