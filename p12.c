/* Write a program to
implement following operations on Doubly Linked List.

(a)   Insert a node at the front of the Linked List

(b)  Insert a node at the end of the Linked List

(c)   Delete a last node of the Linked List

(d)  Delete a node before specified position */

# include<stdio.h> 
# include<stdlib.h> 

struct node
{
    struct node *lptr;
    int info;
    struct node *rptr;
};

// Count the number of nodes
int count_nodes(struct node *first)
{
    int count;
    if(first == NULL)
    {
        count = 0;
        return count;
    }

    count = 1;
    struct node *save = first;

    while(save->rptr != NULL)
    {
        save = save->rptr;
        count++;
    }

    return count;
}

// Display
void display(struct node *first)
{
    // If no node is present 
    if(first == NULL)
    {
        printf("\n No Node is present\n");
        return;
    }

    // Traversal in linked list while link of node is not equal to NULL
    printf("\n Data : ");
    while(first != NULL)
    {
        printf("%5d", first->info);
        first = first->rptr;
    }
}

// struct node *insert(struct node *first, int pos, int data)
// {
//     struct node *new = (struct node *) malloc(sizeof(struct node));
    
//     new->info = data;

//     if(first == NULL)
//     {
//         new->lptr = NULL;
//         new->rptr = NULL;
//         return new;
//     }

//     // Insert before first node
//     if(pos == 1)
//     {
//         new->lptr = NULL;
//         new->rptr = first;
//         first->lptr = new;
//         return new;
//     }
//     else
//     {
//         struct node *save = first;
//         struct node *pred = NULL;

//         for(int i = 1; i <= pos - 1; i++)
//         {
//             pred = save;
//             save = save->rptr;
//         }

//         new->lptr = save->lptr;
//         new->rptr = save;
//         save->lptr = new;
//         new->lptr->rptr = new;
//         return first;

//     }
// }

struct node *insert(struct node *first, int pos, int data)
{
    struct node *new = (struct node *) malloc(sizeof(struct node));
    
    new->info = data;
    struct node *l = NULL;
    struct node *r = NULL;
    l = r = first;

    if(r == NULL)
    {
        new->lptr = NULL;
        new->rptr = NULL;
        l = r = new;
        return new;
    }

    // Insert before first node
    if(pos == 1)
    {
        new->lptr = NULL;
        new->rptr = first;
        first->lptr = new;
        l = new;
        return new;
    }
    else
    {
        struct node *save = first;
        struct node *pred = NULL;

        for(int i = 1; i <= pos - 1; i++)
        {
            pred = save;
            save = save->rptr;
        }

        new->lptr = save->lptr;
        new->rptr = save;
        save->lptr = new;
        new->lptr->rptr = new;
        return first;

    }
}

int main()
{
    struct node *linkedlist1 = NULL;

    printf("%d\n", count_nodes(linkedlist1));

    linkedlist1 = insert(linkedlist1, 1, 25);
    linkedlist1 = insert(linkedlist1, 1, 5);
    linkedlist1 = insert(linkedlist1, 1, 2);
    display(linkedlist1);
    
    linkedlist1 = insert(linkedlist1, 2, 78);
    display(linkedlist1);
    linkedlist1 = insert(linkedlist1, 1, 58);
    display(linkedlist1);
    return 0;
}