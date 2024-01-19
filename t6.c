// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

/* For a Singly linked list define following functions:
a. int length (node *R)
b. int max (node *R)
c. int min (node *R)
d. int search (node *R, int x) - to search for an element x from the linked list having starting address R. Return the actual position of the element x. If it is not found, return -1.
e. node * merge (node *L1, node *L2) - to merge two linked list having starting address as L1 and L2 respectively and to return starting address of the resultant linked list. */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

void display(struct node *first);
int length(struct node *first); /* Same as counting of nodes */
struct node *insert(struct node *first, int x);
struct node *insend(struct node *first, int x);
int max(struct node *first);
int min(struct node *first);
int search(struct node *first, int data);
struct node *merge(struct node *first, struct node *second);

int main()
{
    printf("\n Code Prepared by : Meet Jariwala (ET22BTCO046)");

    int choice, data, position;
    struct node *linkedList1 = NULL;
    struct node *linkedList2 = NULL;
    struct node *linkedList3 = NULL;

    printf("\n Operations\n");
    printf("\n 1 -> Insert \n 2 -> Insend \n 3 -> Length \n 4 -> Max \n 5 -> Min \n 6 -> Search \n 7 -> Merge \n 8 -> Display \n 9 -> Exit \n");

    while(1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            // Insert
            case 1:
            {
                printf("\n Enter data : ");
                scanf("%d", &data);

                linkedList1 = insert(linkedList1, data); /* For 1st linked list */
                linkedList2 = insert(linkedList2, data); /* For 2nd linked list */
                break;
            }

            // Insend
            case 2:
            {
                printf("\n Enter data : ");
                scanf("%d", &data);

                linkedList1 = insend(linkedList1, data);
                break;
            }

            // Length of linked list
            case 3:
            {
                printf("\n Length : %d ", length(linkedList1));
                break;
            }

            // Maximum element from linked list
            case 4:
            {
                printf("\n Maximum element : %d ", max(linkedList1));
                break;
            }

            // Minimum element from linked list
            case 5:
            {
                printf("\n Minimum element : %d ", min(linkedList1));
                break;
            }

            // Search a element from linked list
            case 6:
            {
                printf("\n Enter element to be searched : ");
                scanf("%d", &data);
            
                int searched = search(linkedList1, data);
                
                if(searched != -1)
                {
                    printf("\n Element %d is found at position %d ", data, searched);
                }                
                break;
            }

            // Merging of linked list
            case 7:
            {
                linkedList3 = merge(linkedList1, linkedList2);
                display(linkedList3);
                break;
            }
            
            // Display
            case 8:
            {
                display(linkedList1);
                break;
            }

            // Exit
            case 9:
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

// Count the number of nodes
int length(struct node *first)
{
    int count = 0;
    if (first == NULL)
    {
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
struct node *insert(struct node *first, int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = x;
    new->link = first;
    return new;
}

// Insert a node at the end of the Linked List
struct node *insend(struct node *first, int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
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

// Maximum element from linked list
int max(struct node *first)
{
    if (first == NULL)
    {
        printf("No node present\n");
        return -1;
    }

    struct node *save = first;
    int max = save->info;

    while (save != NULL)
    {
        if (save->info > max)
        {
            max = save->info;
        }
        save = save->link;
    }
    return max;
}

// Minimum element from linked list
int min(struct node *first)
{
    if (first == NULL)
    {
        printf("No node present\n");
        return -1;
    }

    struct node *save = first;
    int min = save->info;

    while (save != NULL)
    {
        if (save->info < min)
        {
            min = save->info;
        }
        save = save->link;
    }
    return min;
}

// Search a element from linked list
int search(struct node *first, int data)
{
    if (first == NULL)
    {
        printf("No node present\n");
        return -1;
    }

    struct node *save = first;
    int index = 0;

    while (save != NULL)
    {
        index++;
        if (save->info == data)
        {
            return index;
        }
        save = save->link;
    }
    if (save == NULL)
    {
        return -1;
    }
}

// Merge two linked list
struct node *merge(struct node *first, struct node *second)
{
    if (first == NULL && second != NULL)
    {
        return second;
    }
    else if (second == NULL)
    {
        return first;
    }

    struct node *save = first;
    while (save->link != NULL)
    {
        save = save->link;
    }
    save->link = second;
    return first;
}