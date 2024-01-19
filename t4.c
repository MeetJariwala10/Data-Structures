// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

/* Write a 'C' program to convert a given parentheses-free infix expression into postfix expression.*/

# include<stdio.h> 
# include<ctype.h>
# define SIZE 10

void push(char *stack, int *top, char next);
char pop(char *stack, int *top);
int precedence(char ch);

int main()
{
    printf("Code Prepared by -> Meet Jariwala (ET22BTCO046)\n");
    
    char stack[SIZE], infix[SIZE], postfix[SIZE];
    int top = -1, i = 0, j = 0;

    printf("Enter Infix Expression : ");
    scanf("%s", infix);

    while(infix[i] != '\0')
    {
        if(isalpha(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if(precedence(infix[i]) > precedence(stack[top]))
            {
                push(stack, &top, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(stack, &top);
                j++;
            }
        }
    }

    while(top != -1)
    {
        postfix[j] = pop(stack, &top);
        j++;
    }
    postfix[j] = '\0';

    printf("The Postfix Expression is : %s", postfix);
    return 0;
}

// Push Operation
void push(char *stack, int *top, char next)
{
    if(*top == SIZE - 1)
    {
        printf("\nSTACK OVERFLOW\n");
    }
    else
    {
        *top = *top + 1;
        stack[*top] = next;
    }
}

// Pop Operation
char pop(char *stack, int *top)
{
    if(*top == -1)
    {
        printf("\nSTACK UNDERFLOW\n");
    }
    else
    {
        *top = *top - 1;
        return stack[*top + 1];
    }
}

// Precedence Operation
int precedence(char ch)
{
    if(ch == '*' || ch == '/')
    {
        return 3;
    }
    else if(ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;  
    }
}