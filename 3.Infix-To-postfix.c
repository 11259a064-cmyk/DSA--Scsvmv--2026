/* Experiment 3: Infix to Postfix Conversion using Stack
   Case Study: Vidya College SIS - Converting the CGPA-computation formula
   entered by faculty into postfix form for the result-processing engine */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
int top = -1;

// Push operator onto stack
void push(char c)
{
    if (top >= MAX - 1)
    {
        printf("Error: Stack Overflow!\n");
        return;
    }
    stack[++top] = c;

}

// Pop operator from stack
char pop()
{
    if (top == -1)
    {
        printf("Error: Stack Underflow!\n");
        return '\0';
    }
    return stack[top--];
}

// Peek at top of stack
char peek()
{
    if (top == -1)
        return '\0';
    return stack[top];
}

// Get precedence of operator
int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}

// Check if character is an operator
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char c;

    // Step 4: Scan the infix expression from left to right
    for (i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];

        // Step 4.I: If token is an operand
        // if(isalpha(c)
        if (!isOperator(c) && c != '(' && c != ')' && c != '[' && c != ']' && c != '{' && c != '}')
        {
            // Add it directly to the postfix expression
            postfix[j++] = c;
        }

        // Step 4.II: If token is an operator
        else if (isOperator(c))
        {
            // Step 4.II.A: Check if stack is empty OR top has lower precedence OR top is '('
            if (top == -1 || precedence(peek()) < precedence(c) || peek() == '(')
            {
                // Push the operator onto the stack
                push(c);
            }
            // Step 4.II.B: Otherwise (top has higher or equal precedence)
            else
            {
                // Pop operators from stack and add to postfix until condition is true
                while (top != -1 && peek() != '(' && precedence(peek()) >= precedence(c))
                {
                    postfix[j++] = pop();
                }
                // Then push the current operator onto the stack
                push(c);
            }
        }

        // Step 4.III: If token is '('
        else if (c == '(')
        {
            // Push it onto the stack
            push(c);
        }

        // Step 4.IV: If token is ')'
        else if (c == ')')
        {
            // Pop operators from stack and add to postfix until '(' is found
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }
            // Ignore both parentheses (no need to add them to postfix expression)
            if (top != -1)
            {
                pop(); // Remove the '('
            }
        }
    }

    // Step 6: Pop any remaining operators from the stack
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    // Output the postfix expression
    postfix[j] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression (formula): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}