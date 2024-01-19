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
int pop(struct node **first); 
int peep(struct node *first, int pos);
void change(struct node *first, int pos, int data);

int main()
{
    int choice, data, position;
    struct node *stack = NULL;

    printf("\n Operations\n");
    printf("\n 1 -> Push \n 2 -> Pop \n 3 -> Display \n 4 -> Peep \n 5-> Change \n 6 -> Exit \n");

    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            // Insert
            case 1:
            {
                printf("\n Enter data : ");
                scanf("%d", &data);

                stack = push(stack, data);
                break;
            }

            // Delete a first node of the Linked List
            case 2:
            {
                int p = pop(&stack); /* We are passing address here as any change will be reflected in stack */
                if (p != -1)
                {
                    printf("\n Popped : %d\n", p);
                }
                break;
            }

            // Display
            case 3:
            {
                display(stack);
                break;
            }

            // Peep
            case 4:
            {
                printf("\n Enter position : ");
                scanf("%d", &position);

                if (stack == NULL)
                {
                    printf("\n Stack Underflow\n");
                    break;
                }
                else if (position > length(stack) || position == 0)
                {
                    printf("\n INAVLID POSITION \n");
                    break;
                }

                int p = peep(stack, position);
                if (p != -1)
                {
                    printf("Element : %d \n", p);
                }
                break;
            }

            // Change
            case 5:
            {
                printf("\n Enter position : ");
                scanf("%d", &position);

                printf("\n Enter data : ");
                scanf("%d", &data);

                if (stack == NULL)
                {
                    printf("\n Stack Underflow\n");
                    break;
                }
                else if (position > length(stack) || position == 0)
                {
                    printf("\n INAVLID POSITION \n");
                    break;
                }

                change(stack, position, data);

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
        printf("\n Stack Underflow\n");
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

// Count the number of nodes
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

// Insert a node at the front of the Linked List
struct node *push(struct node *first, int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));

    if(new == NULL)
    {
        printf("\n Stack Overflow\n");
        return first;
    }
    new->info = x;
    new->link = first;
    return new;
}


// Delete a first node of the Linked List
int pop(struct node **first) /* Pointer to pointer */
{
    if (*first == NULL)
    {
        printf("\n Stack Underflow\n");
        return -1;
    }

    struct node *save = *first;
    *first = (*first)->link;
    int data = save->info;
    free(save);
    return data;
}

// Peep element of specified position
int peep(struct node *first, int pos)
{
    if (first == NULL)
    {
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
        return;
    }

    struct node *save = first;
    for (int i = 1; i < pos; i++)
    {
        save = save->link;
    }

    save->info = data;
}