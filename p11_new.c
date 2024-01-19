// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

/* Write a program to
implement QUEUE using Linked List. */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

// Display
void display(struct node *first)
{
    // If no node is present
    if (first == NULL)
    {
        printf("\n No Node is present\n");
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

// Insert a node at the end of the Linked List
struct node *qInsert(struct node *first, int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));

    if(new == NULL)
    {
        printf("\n Queue Overflow\n");
    }
    new->info = x;
    new->link = NULL;

    if (first == NULL)
    {
        return new;
    }

    struct node *save = first;

    while (save->link != NULL)
    {
        save = save->link;
    }
    save->link = new;

    return first;
}

// Delete a first node of the Linked List
struct node *qDelete(struct node *first)
{
    if (first == NULL)
    {
        printf("No node present Cannot perform pop operation\n");
    }

    struct node *save = first;
    first = first->link;
    free(save);
    return first;
}

int main()
{
    int choice, data, position;
    struct node *queue = NULL;

    printf("\n Operations\n");
    printf("\n 1 -> Insert \n 2 -> Delete \n 3 -> Display \n 4 -> Exit \n");

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

                queue = qInsert(queue, data);
                break;
            }

            // Delete a first node of the Linked List
            case 2:
            {
                queue = qDelete(queue);
                break;
            }

            // Display
            case 3:
            {
                display(queue);
               break;
            }

            // Exit
            case 4:
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