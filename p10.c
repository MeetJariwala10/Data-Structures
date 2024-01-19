// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

/* Write a program to
implement stack using Linked List. */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

void display(struct node *first);
int length(struct node *first);
struct node *push(struct node *first, int x);
struct node *pop(struct node *first);
int peep(struct node *first, int pos);
void change(struct node *first, int pos, int data);

int main()
{
    int choice, data, position;
    struct node *stack = NULL;

    printf("\n Code Prepared by : Meet Jariwala (ET22BTCO046)");

    printf("\n Operations\n");
    printf("\n 1 -> Push \n 2 -> Pop \n 3 -> Peep \n 4 -> Change \n 5 -> Display \n 6 -> Exit \n");

    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            // Push
            case 1:
            {
                printf("\n Enter data : ");
                scanf("%d", &data);

                stack = push(stack, data);
                break;
            }

            // Pop
            case 2:
            {
                stack = pop(stack);
                break;
            }

            // Peep
            case 3:
            {
                printf("\n Enter position : ");
                scanf("%d", &position);

                if (position > length(stack) || position == 0)
                {
                    printf("\n INAVLID POSITION \n");
                    break;
                }

                int p = peep(stack, position);
                if (p != -1)
                {
                    printf(" Element : %d \n", p);
                }
                break;
            }

            // Change
            case 4:
            {
                printf("\n Enter position : ");
                scanf("%d", &position);

                printf("\n Enter data : ");
                scanf("%d", &data);

                if (position > length(stack) || position == 0)
                {
                    printf("\n INAVLID POSITION \n");
                    break;
                }

                change(stack, position, data);

                break;
            }

            // Display
            case 5:
            {
                display(stack);
                break;
            }

            // Exit
            case 6:
            {
                exit(0);
            }

            default:
            {
                printf("\n Enter proper choice \n");
                break;
            }
        }
    }
    return 0;
}

// Display
void display(struct node *first)
{
    // If no node is present
    if (first == NULL)
    {
        printf("\n Stack Underflow \n");
        return;
    }

    // Traversal in linked list while link of node is not equal to NULL
    printf("\n Data : ");
    while (first != NULL)
    {
        printf("%5d", first->info);
        first = first->link;
    }
}

// Length of stack
int length(struct node *first)
{
    int count;
    if (first == NULL)
    {
        count = 0;
        return count;
    }

    count = 1;
    struct node *save = first;

    while (save->link != NULL)
    {
        save = save->link;
        count++;
    }

    return count;
}

// Insert data to stack
struct node *push(struct node *first, int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));

    if(new == NULL)
    {
        printf("\n Stack Overflow \n");
        return first;
    }

    new->info = x;
    new->link = first;
    return new;
}

// Popping a data from stack 
struct node *pop(struct node *first)
{
    if (first == NULL)
    {
        printf("\n Stack Underflow\n");
        return first;
    }

    struct node *save = first;
    first = first->link;
    free(save);
    return first;
}

// Peep element of specified position
int peep(struct node *first, int pos)
{
    if (first == NULL)
    {
        printf("\n Stack Underflow\n");
        return -1;
    }

    struct node *save = first;
    for (int i = 1; i < pos; i++)
    {
        save = save->link;
    }
    return save->info;
}

// Change data of specified position
void change(struct node *first, int pos, int data)
{
    if (first == NULL)
    {
        printf("\n Stack Underflow\n");
        return;
    }

    struct node *save = first;
    for (int i = 1; i < pos; i++)
    {
        save = save->link;
    }

    save->info = data;
}
